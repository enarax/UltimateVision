#include "stdafx.h"
#include "GetImage.h"

Mat GetImageFromWebcam(CvCapture *capture)
{
	//Read the video stream
	IplImage* frame = cvQueryFrame( capture ); 
	return Mat(frame);
}
