#include<iostream>
#include<math.h>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
  //__________________________________________________Verify that the user give a image path
  if (argc !=2 )
  {
    std::cout << "Usage: DisplayImage.out <Image_path>" << std::endl;
    return -1;
  }

  Mat image, gray_image, negative_image, fourier_transform, gamma_image;
  double min, max;

  //__________________________________________________Read the image and save into a matrix. The second argument is the type of image tha will be read
  image = imread(argv[1], 1);

  //Verify that the image have data
  if(!image.data)
  {
    std::cout << "No image data" << std::endl;
    return -2;
  }

  //__________________________________________________image.channels() calculate the image channels
  std::cout << "Image channels: " << image.channels() << std::endl;
  //Maximum, min
  minMaxLoc(image, &min, &max);
  std::cout << "max: " << max << "min: "<< min << std::endl;


  //__________________________________________________Normalize a image to a range [0.0, 1.0]
  //normalize(image, image, 1.0, 0.0, NORM_MINMAX);
  //Arroja imagen en negro

  ////__________________________________________________Convert to gray scale
  //cvt modify a image, CV_BGR2GRAY indicate the modification type
  cvtColor(image, gray_image, CV_BGR2GRAY);

  ////__________________________________________________Negative image
  //Se resta a 255 es valor de la matriz
  subtract(255, image, negative_image);

//__________________________________________________Gamma Correction
  float gamma;
  gamma_image.rows = image.rows;
  gamma_image.cols = image.cols;
  //~~std::cout << "Ingrese un valor de gamma entre:  ";
  //~~std::cin >> gamma;
  gamma = 3;
  pow(image, gamma, gamma_image);
  gamma_image *= 2;

  //__________________________________________________Histogram calculate *gray image*
  //Establish the number of bins
  int histSize = 256;
  //Set the ranges
  float range[] = {0, 256};
  const float* histRange = {range};

  bool uniform = true, accumulate = false;
  Mat image_hist;
  //Compute the histograms
  calcHist(&gray_image, 1, 0, Mat(), image_hist, 1, &histSize, &histRange, uniform, accumulate);

  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound((double)hist_w/histSize);

  Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

  normalize(image_hist, image_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

  //Draw dor each channel
  for(int i = 1; i < histSize; i++)
  {
    line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(image_hist.at <float> (i - 1)) ) ,
                       Point(bin_w * (i), hist_h - cvRound(image_hist.at <float> (i)) ),
                       Scalar(255, 255, 255), 2, 8, 0);
  }

  //_________________________________Histogram equalization
  Mat equalize_image;
  equalizeHist(gray_image, equalize_image);

  //_________________________________MedianFilter
  Mat median_image;
  medianBlur(image, median_image, 9);

  //_________________________________Laplacian (Grayscale)
  int kernel_size = 7; //ventana
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;
  Mat laplace_image, tmp_image;
  Laplacian(gray_image, tmp_image, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
  convertScaleAbs(tmp_image, laplace_image);
  //_________________________________Laplacian subtraction
  subtract(gray_image, laplace_image, tmp_image);

  //_________________________________Sobel (Gradient) (Grayscale)
  Mat gradient_image;
  Mat grad_x, grad_y;
  Mat abs_grad_x, abs_grad_y;

  //_________________________________ Canny

  //_________________________________ Prewitt

  //Gradient X
  Sobel(gray_image, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
  convertScaleAbs(grad_x, abs_grad_x);
  //Gradient Y
  Sobel(gray_image, grad_y, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
  convertScaleAbs(grad_y, abs_grad_y);
  //Totalgradient(approximate)
  addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, gradient_image);
  //__________________________________________________ Sobel subtraction
  Mat gradient_subtraction;
  subtract(gray_image, gradient_image, gradient_subtraction);
  //__________________________________________________Show results
  //Create the window
  namedWindow("DisplayImage", WINDOW_AUTOSIZE);
  namedWindow("GrayImage", WINDOW_AUTOSIZE);
  //namedWindow("NegativeImage", WINDOW_AUTOSIZE);
  // namedWindow("DiscreteFourierTransform", WINDOW_AUTOSIZE);
  //namedWindow("GammaTransform", WINDOW_AUTOSIZE);
  //namedWindow("ImageHistogram", WINDOW_AUTOSIZE);
  //namedWindow("EqualizedImage",WINDOW_AUTOSIZE);
  //namedWindow("medianBlur", WINDOW_AUTOSIZE);
  namedWindow("LaplaceFunction", WINDOW_AUTOSIZE);
  namedWindow("LaplaceFunctionSub");
  namedWindow("SobelGradient", WINDOW_AUTOSIZE);
  namedWindow("SobelSub", WINDOW_AUTOSIZE);
  //Show the image in the window
  imshow("DisplayImage", image);
  imshow("GrayImage", gray_image);
  //imshow("NegativeImage", negative_image);
  //imshow("DiscreteFourierTransform", magI);//complexI);
  //imshow("GammaTransform", gamma_image);
  //imshow("ImageHistogram", histImage);
  //imshow("EqualizedImage", equalize_image);
  //imshow("medianBlur", median_image);
  imshow("LaplaceFunction", laplace_image);
  imshow("LaplaceFunctionSub", tmp_image);
  imshow("SobelGradient", gradient_image);
  imshow("SobelSub", gradient_subtraction);
  waitKey(0);
  return 0;
}
