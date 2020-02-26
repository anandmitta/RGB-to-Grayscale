#include <iostream>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int main()
{
 Mat image;

 image =imread("<image path>");

 int rows=image.rows;
 int cols=image.cols;

 uint8_t myArray[rows][cols];

 for (int i = 0; i < rows; i++) {
   for (int j = 0; j < cols; j++) {
     myArray[i][j] = 0;
   }
 }

 uint8_t* pixelPtr = (uint8_t*)image.data;

 int cn = image.channels();

 Scalar_<uint8_t> bgrPixel;

 for(int i = 0; i < rows; i++)

 {

     for(int j = 0; j < cols; j++)

     {

         bgrPixel.val[0] = pixelPtr[i*image.cols*cn + j*cn + 0]; // B

         bgrPixel.val[1] = pixelPtr[i*image.cols*cn + j*cn + 1]; // G

         bgrPixel.val[2] = pixelPtr[i*image.cols*cn + j*cn + 2]; // R

         int average = (bgrPixel.val[0]+bgrPixel.val[1]+bgrPixel.val[2])/3;

         myArray[i][j]=average;
     }
 }
 
 Mat averaged_image(Size(rows, cols), CV_8UC1, myArray, Mat::AUTO_STEP);

 imshow("averaged_image",averaged_image);

 waitKey(0);

 return 0;
}
