#include "stdafx.h"

#include "anglehelper.h"
#include "GetImage.h"
#include "ColorFilter.h"
#include "LineDetection.h"
#include "Contours.h"

#define UINT8 unsigned char


RNG rng(12345);



 
/**
* @function main
*/
int main( int argc, const char** argv )
{

	CvCapture* capture = cvCaptureFromCAM(0);
        if (! capture)
        {
            fprintf(stderr, "Cannot capture from webcam.\n");
            exit(0);
        }

 
while (true)
{
 
	// create a window to display detected faces
	cvNamedWindow("Sample Program", CV_WINDOW_AUTOSIZE);
 
	Mat src = GetImageFromWebcam(capture);
	Mat blurred;
	GaussianBlur(src, blurred, Size(BLURSIZE, BLURSIZE), 1.0);
	Mat filtered = FilterImage(blurred);
	Mat filtered_grey;
	cvtColor(filtered, filtered_grey, CV_BGR2GRAY);

	//detect the rectangle
	//detect edges
	Mat detected_edges;
	DetectEdges(filtered_grey);

	//contours
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	GetContours(filtered_grey, contours, hierarchy);
	
	vector<vector<Point> > target = GetTargetContours(contours, hierarchy);
	Mat drawing = Mat::zeros(filtered_grey.size(), CV_8UC3);
	for(unsigned int i = 0; i < target.size(); i++){
		drawContours( drawing, target , i, Scalar(255,255,255,225), 2, 8, hierarchy, 0, Point() );
	}

	//detect lines
	/*Mat dst;
	vector<Vec4i> validlines;
	HoughLinesP(filtered_grey, validlines, 1, CV_PI/180, 50, 100, 10 );

	//draw em'
	for( size_t i = 0; i < validlines.size(); i++ )
	{
			Vec4i l = validlines[i];
			line( filtered, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
	}

	//get and draw the aim target
		
	double avg_x = 0, avg_y = 0;
	for( size_t i = 0; i < validlines.size(); i++ )
	{
		Vec4i l = validlines[i];
			avg_x += l[0] + l[2];
			avg_y += l[1] + l[3];
	}
	avg_x /= validlines.size()*2;
	avg_y /= validlines.size()*2;
	circle(filtered, Point(avg_x, avg_y), 8, Scalar(0,0,255), 2, CV_AA);*/
		


	//imshow("Sample Program", filtered);
	imshow("Sample Program", drawing);
 
	int c = cvWaitKey(10);
	if( (char)c == 27 ) { exit(0); }
 
}
 
// clean up and release resources
//cvReleaseImage(&frame);
 
return 0;
 
}
