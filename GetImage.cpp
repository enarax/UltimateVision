#include "stdafx.h"
#include "GetImage.h"

Mat GetImageFromWebcam()
{
	//Read the video stream
	CvCapture* capture = cvCaptureFromCAM(0);
        if (! capture)
        {
            fprintf(stderr, "Capture failed.\n");
            exit(0);
        }
	IplImage* frame = cvQueryFrame( capture ); 
	return Mat(frame);
}
