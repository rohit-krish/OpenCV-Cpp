#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat warp_img(Mat img)
{
    float w = 250, h = 350;
    Mat matrix, img_warp;

    Point2f src[4] = {{20, 340}, {160, 220}, {360, 445}, {460, 300}};
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, img_warp, matrix, Point(w, h));

    for (int i = 0; i < 4; i++)
        circle(img, src[i], 5, Scalar(0, 0, 255), FILLED);

    return img_warp;
}

int main()
{
    string path = "../assets/book-in-a-table.jpg";
    Mat img = imread(path);
    Mat warped = warp_img(img);

    imshow(path, img);
    imshow(path + " warped", warped);
    waitKey(0);
}
