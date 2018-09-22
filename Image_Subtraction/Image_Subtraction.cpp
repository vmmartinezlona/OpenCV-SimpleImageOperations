#include<iostream>
#include<math.h>
#include<opencv2/opencv.hpp>

using namespace cv;

Mat calculateHistogram(Mat *image);//;, const unsigned int *color);

int main(int argc, char** argv)
{
  //Verify that the user give a image path
  if (argc !=2 )
  {
    std::cout << "Usage: DisplayImage.out <Image_path>" << std::endl;
    return -1;
  }

  Mat image;

  //Read the image and save into a matrix. The second argument is the type of image tha will be read
  image = imread(argv[1], 1);

  //Verify that the image have data
  if(!image.data)
  {
    std::cout << "No image data" << std::endl;
    return -2;
  }

  //Convert to gray scale
  Mat gray_image;
  cvtColor(image, gray_image, CV_BGR2GRAY);

  //Negative image
  //Se resta a 255 es valor de la matriz
  Mat negative_image;
  subtract(255, image, negative_image);

  //Gamma correction
  Mat gamma_image;
  float gamma;
  gamma_image.rows = image.rows;
  gamma_image.cols = image.cols;
  std::cout << "Ingrese un valor de gamma entre:  ";
  std::cin >> gamma;
  pow(image, gamma, gamma_image);
  gamma_image *= 2;

  //_________________________________Histogram equalization
  Mat equalized_image;
  equalizeHist(gray_image, equalized_image);

  //_________________________________MedianFilter
  Mat median_image;
  int window;
  do{
      std::cout << "Ingrese un valor impar de ventana: " << std::endl;
      std::cin >> window;
  } while(window % 2 == 0);

  medianBlur(image, median_image, 9);

  //subtract
  //Original - negative_image
  Mat sub_negative;
  subtract(image, negative_image, sub_negative);
  namedWindow("Original - NegativeImage", WINDOW_AUTOSIZE);
  imshow("Original - NegativeImage", sub_negative);

  //Original - EqualizedImage
  Mat sub_equalized;
  subtract(gray_image, equalized_image, sub_equalized);
  namedWindow("Original - EqualizedImage", WINDOW_AUTOSIZE);
  imshow("Original - EqualizedImage", sub_equalized);

  //Original - median_image
  Mat sub_median;
  subtract(image, median_image, sub_median);
  namedWindow("Original - MedianImage", WINDOW_AUTOSIZE);
  imshow("Original - MedianImage", sub_median);


  //Convert to gray scale for the histograms
  cvtColor(sub_negative, sub_negative, CV_BGR2GRAY);
  //This is already in 1channel cvtColor(sub_equalized, sub_equalized, CV_BGR2GRAY);
  cvtColor(sub_median, sub_median, CV_BGR2GRAY);

  int histSize = 256;
  //Set the ranges
  float range[] = {0, 256};
  const float* histRange = {range};

  bool uniform = true, accumulate = false;
  //Compute the histograms
  //sub_negative
  Mat sub_negative_hist;
  calcHist(&sub_negative, 1, 0, Mat(), sub_negative_hist, 1, &histSize, &histRange, uniform, accumulate);
  //sub_equalized
  Mat sub_equalized_hist;
  calcHist(&sub_equalized, 1, 0, Mat(), sub_equalized_hist, 1, &histSize, &histRange, uniform, accumulate);
  //sub_median
  Mat sub_median_hist;
  calcHist(&sub_median, 1, 0, Mat(), sub_median_hist, 1, &histSize, &histRange, uniform, accumulate);

  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound((double)hist_w/histSize);

  Mat histImage_sub_negative(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));
//  histImage_sub_negative = calculateHistogram(sub_negative);//, [255, 0, 0]);

  Mat histImage_sub_equalized(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));
  Mat histImage_sub_median(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

  normalize(sub_negative_hist, sub_negative_hist, 0, histImage_sub_negative.rows, NORM_MINMAX, -1, Mat());
  normalize(sub_equalized_hist, sub_equalized_hist, 0, histImage_sub_equalized.rows, NORM_MINMAX, -1, Mat());
  normalize(sub_median_hist, sub_median_hist, 0, histImage_sub_median.rows, NORM_MINMAX, -1, Mat());

  //Draw dor each channel
  for(int i = 1; i < histSize; i++)
  {
    //sub_negative_hist red
    line(histImage_sub_negative, Point(bin_w * (i - 1), hist_h - cvRound(sub_negative_hist.at <float> (i - 1)) ) ,
                       Point(bin_w * (i), hist_h - cvRound(sub_negative_hist.at <float> (i)) ),
                       Scalar(255, 0, 0), 2, 8, 0);

    //sub_equalized_hist green
    line(histImage_sub_equalized, Point(bin_w * (i - 1), hist_h - cvRound(sub_equalized_hist.at <float> (i - 1)) ) ,
                       Point(bin_w * (i), hist_h - cvRound(sub_equalized_hist.at <float> (i)) ),
                       Scalar(0, 255, 0), 2, 8, 0);
    //sub_median_hist blue
    line(histImage_sub_median, Point(bin_w * (i - 1), hist_h - cvRound(sub_median_hist.at <float> (i - 1)) ) ,
                      Point(bin_w * (i), hist_h - cvRound(sub_median_hist.at <float> (i)) ),
                      Scalar(255, 0, 0), 2, 8, 0);
  }


  //Create the window
  namedWindow("DisplayImage", WINDOW_AUTOSIZE);
  namedWindow("GrayImage", WINDOW_AUTOSIZE);
  namedWindow("NegativeImage", WINDOW_AUTOSIZE);
  namedWindow("EqualizedImage",WINDOW_AUTOSIZE);
  namedWindow("medianBlur", WINDOW_AUTOSIZE);
  namedWindow("SubtractNegativeHistogram", WINDOW_AUTOSIZE);
  namedWindow("SubtractEqualizedHistogram", WINDOW_AUTOSIZE);
  namedWindow("SubtractMedianHistogram", WINDOW_AUTOSIZE);
  //Show the image in the window
  imshow("DisplayImage", image);
  imshow("GrayImage", gray_image);
  imshow("NegativeImage", negative_image);
  imshow("EqualizedImage", equalized_image);
  imshow("medianBlur", median_image);
  imshow("SubtractNegativeHistogram", histImage_sub_negative);
  imshow("SubtractEqualizedHistogram", histImage_sub_equalized);
  imshow("SubtractMedianHistogram", histImage_sub_median);

  waitKey(0);
  return 0;
}
/*
Mat calculateHistogram(Mat image)//, const unsigned int *color)
{
  unsigned short int histSize = 256;
  //Set the ranges
  float range[] = {0, 256};
  const float* histRange = {range};

  bool uniform = true, accumulate = false;
  //Compute the histogram
  Mat image_hist;
  calcHist(&image, 1, 0, Mat(), image_hist, 1, &histSize, &histRange, uniform, accumulate);
  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound((double)hist_w/histSize);

  Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

  normalize(image_hist, image_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

  //Draw dor each channel
  for(int i = 1; i < histSize; i++)
  {
    //sub_negative_hist red
    line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(image_hist.at <float> (i - 1)) ) ,
                       Point(bin_w * (i), hist_h - cvRound(image_hist.at <float> (i)) ),
                       Scalar(255, 0, 0), 2, 8, 0);
  }

  return histImage;
}*/
