#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat crop(Mat img)
{
    // Mat img_crop;
    Rect roi(100, 100, 150, 150); // x, y, w, h
    return img(roi);
}

Mat resize(Mat img)
{
    cout << img.size << '\t';
    Mat resized;
    cv::resize(img, resized, Size(0, 0), .8, .8);
    cout << resized.size << endl;
    return resized;
}

int main()
{
    string path = "../assets/lenna.png";
    Mat img = imread(path);

    img = resize(img);
    Mat img_gray, img_blur, img_canny, img_dilate, img_erode;

    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img_gray, img_blur, Size(3, 3), 1, 1);
    Canny(img_blur, img_canny, 10, 100);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(img_canny, img_dilate, kernel); // thick
    erode(img_dilate, img_erode, kernel);  // thin

    Mat cropped = crop(img_canny);

    // imshow("img", img);
    // imshow("gray", img_gray);
    // imshow("guassian blur", img_blur);
    imshow("Canny", img_canny);
    imshow("Cropped", cropped);
    // imshow("Dilate", img_dilate);
    // imshow("Erode", img_erode);
    waitKey(0);
}