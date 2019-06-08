#include <opencv2/opencv.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	
	CascadeClassifier face_cascade;
	face_cascade.load("haarcascade_frontalface_alt.xml");
	VideoCapture cap;
	cv::String addr("rtsp://admin1:123Admin@192.168.0.102:10554/tcp/av0_0");
	if (!cap.open(addr))
	{
		printf("camera is null\n");
		
		return -1;
	}
	else
	{
		
		Mat img;
		int i;
		std::vector<Rect> faces;
		while (cap.isOpened())
		{
			cap >> img;
			face_cascade.detectMultiScale(img, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
			
			if (faces.size()  > 0 ) imwrite("result.jpg", img);
			
			
			
			waitKey(1);
		}
	}
	return 0;
}
