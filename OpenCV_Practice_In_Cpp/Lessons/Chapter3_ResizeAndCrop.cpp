#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Resize and Crop //////////////////////

void main()
{

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCrop, imgResizeChangedAspectRatio;

	//cout << img.size() << endl;

	// scales img down, maintains the aspect ratio
	resize(img, imgResize, Size(), 0.5, 0.5);

	// changes the img's width and height, does not maintain aspect ratio
	resize(img, imgResizeChangedAspectRatio, Size(640, 480));

	// roi: region of interest for cropping
	Rect roi(200, 100, 300, 300);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}