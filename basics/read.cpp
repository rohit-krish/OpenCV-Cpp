#include <opencv2/opencv.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void read_and_show_img(string path)
{
    Mat img = imread(path);
    imshow("img", img);
    waitKey(0);
}

void read_and_show_video()
{
    VideoCapture cap(1);

    if (!cap.isOpened())
    {
        cout << "Error opening video stream or file" << endl;
        return;
    }

    Mat frame;

    while (1)
    {
        cap.read(frame);

        if (frame.empty())
            break;

        imshow("Frame", frame);

        if (waitKey(1) == 27)
            break;
    }

    cap.release();

    destroyAllWindows();
}

int main(int argc, char **argv)
{
    read_and_show_img(argv[1]);
    // read_and_show_video();
}
