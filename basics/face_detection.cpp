#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Useage: ./main <path_to_cascade>";
        return 0;
    }

    VideoCapture cap(1);
    Mat frame;

    CascadeClassifier faceCascade(argv[1]);
    vector<Rect> faces;

    // faceCascade.load(<path>)
    // if (faceCascade.empty()) { }

    while (1)
    {
        cap.read(frame);
        if (frame.empty() || waitKey(1) == 27)
            break;

        faceCascade.detectMultiScale(frame, faces, 1.1, 10);

        for (int i = 0; i < faces.size(); i++)
            rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 2);

        imshow("frame", frame);
    }

    cap.release();
    destroyAllWindows();
}