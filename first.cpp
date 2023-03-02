/*
VGA = 640X480
HD  = 1280X720
FHD = 1920X1080
4K  = 3840X2160
*/

#include <opencv2/opencv.hpp>
#include<stdio.h>

using namespace cv;

int main(int argc, char **argv)
{
	if (argc != 2){
		printf("usage: display_image.out <img_path>");
		return -1;
	}

	Mat image;
	image = imread(argv[1], 1);

	if (!image.data)
	{
		printf("No image data\n");
		return -1;
	}

	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", image);
	waitKey(0);
	return 0 ;
}
