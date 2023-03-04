#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat img_hsv, mask;
int h_min = 0, s_min = 0, v_min = 180;
int h_max = 39, s_max = 255, v_max = 225;

int main()
{
    std::string path = "../assets/ironmanShield.jpg";

    Mat img = imread(path);
    cvtColor(img, img_hsv, COLOR_BGR2HSV);

    // namedWindow("TrackBars", (640, 200));
    // createTrackbar("Hue Min", "TrackBars", &h_min, 179);
    // createTrackbar("Hue Max", "TrackBars", &h_max, 179);
    // createTrackbar("Sat Min", "TrackBars", &s_min, 255);
    // createTrackbar("Sat Max", "TrackBars", &s_max, 255);
    // createTrackbar("Val Min", "TrackBars", &v_min, 255);
    // createTrackbar("Val Max", "TrackBars", &v_max, 255);

    // while (1)
    {
        std::cout << h_min << ' ' << h_max << ' ' << s_min << ' ' << s_max << ' ' << v_min << ' ' << v_max << ' ' << '\n';

        Scalar lower(h_min, s_min, v_min);
        Scalar upper(h_max, s_max, v_max);
        inRange(img_hsv, lower, upper, mask);

        imshow(path, img);
        imshow(path + " hsv", img_hsv);
        imshow(path + " mask", mask);
        waitKey(0);
    }
}