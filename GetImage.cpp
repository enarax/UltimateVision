#include "stdafx.h"
#include "GetImage.h"

#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\highgui\highgui.hpp"

Mat GetImageFromWebcam()
{
	//Read the video stream
	CvCapture* capture = cvCaptureFromCAM(1);
	IplImage* frame = cvQueryFrame( capture ); 
	return Mat(frame);
}
