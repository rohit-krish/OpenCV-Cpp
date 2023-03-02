#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    // Blank Image
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));
    // 8bit unsigned 3 channel image
    // Scalar(255, 0, 0) -> blue

    circle(img, Point(250, 250), 100, Scalar(0, 0, 0), FILLED);
    rectangle(img, Point(100, 100), Point(400, 400), Scalar(0, 0, 0), 2);
    line(img, Point(100, 300), Point(300, 400), (255,0,0), 2);

    putText(img, "C++ OpenCV", Point(50, 50), FONT_HERSHEY_SIMPLEX, 2, Scalar(255,0,255), 5);

    imshow("Image", img);
    waitKey(0);
}