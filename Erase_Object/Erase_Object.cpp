#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
  //Verify that the user give a image path
  if (argc == 1 )
  {
    std::cout << "Usage: DisplayImage.out <Image_path>" << std::endl;
    return -1;
  }

  Mat image1, image2;

  //Read the image and save into a matrix. The second argument is the type of image tha will be read
  image1 = imread(argv[1], 1);
  image2 = imread(argv[2], 1);

  //Verify that the image have data
  if(!image1.data || !image2.data)
  {
    std::cout << "No image data" << std::endl;
    return -2;
  }


  Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2().dynamicCast<BackgroundSubtractor>();
  Mat  foregroundMask, backgroundImage, foregroundImg;

  Mat gray1, gray2;
  cvtColor(image1, gray1, CV_BGR2GRAY);
  cvtColor(image2, gray2, CV_BGR2GRAY);

  Mat image_subtract1, image_subtract2, object_area;

  subtract(gray1, gray2, image_subtract1);
  subtract(gray2, gray1, image_subtract2);
  add(image_subtract1, image_subtract2, object_area);

  for(int i = 0; i < object_area.rows; i++)
  {
    for(int j = 0; j < object_area.cols; j++)
    {
      if(object_area.at<uchar>(i, j) != 0) object_area.at<uchar>(i, j) = 255;
    }
  }

  Mat result, background_area, tmp1;
  subtract(gray2, object_area, result);
  subtract(255, object_area, background_area );
  subtract(gray1, background_area, tmp1);
  add(gray2, tmp1, result);

  namedWindow("RESULT", WINDOW_AUTOSIZE);
  imshow("RESULT", result);

  waitKey(0);
  return 0;
}
