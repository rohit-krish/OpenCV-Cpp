#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// void detect_shape(){

//     double area, peri;
//     Mat approx_corners;
//     int approx_corners_n;
//     Rect bounding_rect;

//     for (vector cnt : contours)
//     {
//         area = contourArea(cnt);
//         peri = arcLength(cnt, true);
//         approxPolyDP(cnt, approx_corners, 0.02 * peri, true);
//         approx_corners_n = approx_corners.size[0];
//         bounding_rect = boundingRect(approx_corners);
//         cout << bounding_rect.x << bounding_rect.y << bounding_rect.width << bounding_rect.height << '\t';
//     }
// }

void getContour(Mat img_dil, Mat img)
{
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy; // Vec 4 int
    findContours(img_dil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    // drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

    float peri, area;
    vector<vector<Point>> con_poly(contours.size());
    vector<Rect> bound_rect(contours.size());
    int n_corner_points = 0;
    string obj_shape = "";
    float ratio_for_square = 0.0;

    for (int i = 0; i < contours.size(); i++)
    {
        area = contourArea(contours[i]);
        if (area > 1000)
        {
            peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], con_poly[i], 0.02 * peri, true);
            bound_rect[i] = boundingRect(con_poly[i]);

            n_corner_points = (int)con_poly[i].size();
            if (n_corner_points == 3)
                obj_shape = "Tri";
            else if (n_corner_points == 4)
            {
                ratio_for_square = (float)bound_rect[i].width / (float)bound_rect[i].height;
                cout << ratio_for_square << '\t';
                if ((ratio_for_square >= 0.975) && (ratio_for_square <= 1.02))
                    obj_shape = "Square";
                else
                    obj_shape = "Rect";
            }
            else if (n_corner_points > 4)
                obj_shape = "Circle";


            // contours
            drawContours(img, con_poly, i, Scalar(255, 0, 255), 2);
            // bound rect
            /* .tl -> top-left, .br -> bottom-right */
            rectangle(img, bound_rect[i].tl(), bound_rect[i].br(), Scalar(0, 255, 0), 2);
            // bound rect shape
            putText(img, obj_shape, {bound_rect[i].x, bound_rect[i].y}, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);
        }
    }
}
// 0.975 -> 1.02

int main()
{
    string path = "../assets/shapes.png";
    Mat img = imread(path);
    Mat img_gray, img_blur, img_canny, img_dil;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img_gray, img_blur, Size(3, 3), 1, 1);
    Canny(img_blur, img_canny, 50, 50);
    dilate(img_canny, img_dil, kernel);

    getContour(img_dil, img);

    imshow("Img", img);
    // imshow("Canny", img_canny);
    // imshow("Dilate", img_dil);

    waitKey(0);
}