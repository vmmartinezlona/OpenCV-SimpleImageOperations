#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
  //Verify that the user give a image path
  if (argc !=2 )
  {
    std::cout << "Usage: DisplayImage.out <Image_path>" << std::endl;
    return -1;
  }

  Mat image, bitand_image;

  //Read the image and save into a matrix. The second argument is the type of image tha will be read
  image = imread(argv[1], 1);
  //Verify that the image have data
  if(!image.data)
  {
    std::cout << "No image data" << std::endl;
    return -2;
  }

  bitand_image.rows = image.rows;
  bitand_image.cols = image.cols;
  bitand_image = image;
  bitwise_and(image, 248, bitand_image, 0);

  namedWindow("bitwiseAND", WINDOW_AUTOSIZE);
  imshow("bitwiseAND", bitand_image);

  waitKey(0);
  return 0;
}
