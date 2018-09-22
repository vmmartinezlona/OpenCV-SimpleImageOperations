#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//Functions
double pixelDistance(const double &u, const double &v);
double gaussianCoeff(const double &u, const double &v, const double &d0);

int main(int argc, char** argv)
{
  //__________________________________________________Verify that the user give a image path
  if (argc !=2 )
  {
    std::cout << "Usage: DisplayImage.out <Image_path>" << std::endl;
    return -1;
  }

  Mat image, gray_image;

  //__________________________________________________Read the image and save into a matrix. The second argument is the type of image tha will be read
  image = imread(argv[1], 1);

  //Verify that the image have data
  if(!image.data)
  {
    std::cout << "No image data" << std::endl;
    return -2;
  }

  ////__________________________________________________Convert to gray scale
  //cvt modify a image, CV_BGR2GRAY indicate the modification type
  cvtColor(image, gray_image, CV_BGR2GRAY);


  //1.- Fourier Spectrum or images, 2D Discrete Fourier Transform (DFT) is used to find the frequency domain.
  //1.1.- The image has to be in gray scale

  Mat optimal_size;
  //1.2 The image has to be in a optimal size, added zero pixels
  //getOptimalDFTSize() returns this optimal size
  // copyMakeBorder() function to expand the borders of an image
  int m = getOptimalDFTSize( gray_image.rows );
  int n = getOptimalDFTSize( gray_image.cols ); // on the border add zero pixels
  copyMakeBorder(gray_image, optimal_size, 0, m - gray_image.rows, 0, n - gray_image.cols, BORDER_CONSTANT, Scalar::all(0));

  //1.3 Make place for both the complex and the real values (Because the transform is complex)
  //Store the values in float format. Therefore we’ll convert our input image to this type
  //Expand it with another channel to hold the complex values
  Mat planes[] = {Mat_<float>(optimal_size), Mat::zeros(optimal_size.size(), CV_32F)};
  Mat complexI;
  merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

  //Discrete Fourier Transform
  dft(complexI, complexI);

  //Transform the real and complex values to magnitude
  split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
  magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude

  Mat DFTmagnitude = planes[0];

  //Switch to a logarithmic scale
  // the dynamic range of the Fourier coefficients is too large to be displayed on the screen.
  DFTmagnitude += Scalar::all(1);                    // switch to logarithmic scale
  //imshow("Spectrum magnitude no log", DFTmagnitude); No muestra nada
  log(DFTmagnitude, DFTmagnitude);

  //Crop an rearrange
  DFTmagnitude = DFTmagnitude(Rect(0, 0, DFTmagnitude.cols & -2, DFTmagnitude.rows & -2));
  int cx = DFTmagnitude.cols/2;
  int cy = DFTmagnitude.rows/2;

  Mat q0(DFTmagnitude, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
  Mat q1(DFTmagnitude, Rect(cx, 0, cx, cy));  // Top-Right
  Mat q2(DFTmagnitude, Rect(0, cy, cx, cy));  // Bottom-Left
  Mat q3(DFTmagnitude, Rect(cx, cy, cx, cy)); // Bottom-Right

  Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
  q0.copyTo(tmp);
  q3.copyTo(q0);
  tmp.copyTo(q3);

  q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
  q2.copyTo(q1);
  tmp.copyTo(q2);

  //Normalize for visualization purposes.
  normalize(DFTmagnitude, DFTmagnitude, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
                                        // viewable image form (float between values 0 and 1).

  imshow("Input Image", image);    // Show the result
  imshow("Spectrum magnitude", DFTmagnitude);

  waitKey();

  return 0;
}

double pixelDistance(const double &u, const double &v)
{
  return sqrt(u * u + v * v);
}

double gaussianCoeff(const double &u, const double &v, const double &d0)
{
  double d = pixelDistance(u,v);
  return 1.0 - exp((-d * d) / (2 * d0 * d0));
}

Mat createGaussianHighPassFilter(Size size, double cutoffInPixels)
