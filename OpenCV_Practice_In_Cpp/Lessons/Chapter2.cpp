#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// namespaces used to avoid naming conflicts
using namespace cv;
using namespace std;

///////////////  Basic Functions  //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);

	// we will pass these in by reference
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);

	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	// increases edge thickness
	dilate(imgCanny, imgDil, kernel);
	// decreases edge thickness
	erode(imgDil, imgErode, kernel);

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
}