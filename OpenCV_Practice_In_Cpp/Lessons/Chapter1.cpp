#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
/* import images, videos, and webcams */
using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

//void main()
//{
//	string path = "Resources/test.png";
//	// loads an image from a file
//	Mat img = imread(path);
//	imshow("Image", img);
//	// show the image until a key is pressed
//	waitKey(0);
//}


///////////////  Video  //////////////////////
/*a video is a series of images, so we need a while loop to iterate thru all of them*/
//void main()
//{
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	
//	int milliseconds = 20;
//
//	while (true)
//	{
//		cap.read(img);
//		imshow("Image", img);
//		// fewer milliseconds will speed up the video
//		waitKey(milliseconds);
//	}
//}


/////////////////  Webcam  //////////////////////

void main()
{
	// my window external webcam uses my phone as a webcam and id of 0 didn't work, but 1 did
	int cameraId = 1;
	VideoCapture cap(cameraId);
	Mat img;

	while (true)
	{
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}
