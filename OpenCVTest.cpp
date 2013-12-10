#include "stdafx.h"

#include "anglehelper.h"
#include "GetImage.h"
#include "ColorFilter.h"
#include "Settings.h"

#define UINT8 unsigned char


RNG rng(12345);

int lowThreshold = 20;
int const  ratio = 3;
int const kernel_size = 3;

 
/**
* @function main
*/
int main( int argc, const char** argv )
{
 
while (true)
{
 
	// create a window to display detected faces
	cvNamedWindow("Sample Program", CV_WINDOW_AUTOSIZE);
	  //createTrackbar( "Min Threshold:", "Sample program", &lowThreshold, 100, nullptr );
 
	Mat src = GetImageFromWebcam();
	Mat blurred;
	GaussianBlur(src, blurred, Size(BLURSIZE, BLURSIZE), 1.0);
	

	Mat filtered = FilterImage(blurred);

	
	Mat filtered_grey;
	cvtColor(filtered, filtered_grey, CV_BGR2GRAY);

	//detect the rectangle
	//detect edges
	Mat detected_edges;
	Canny( filtered_grey, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );


	//contours
	vector<vector<Point> > contours;
	vector<vector<Point> > contours_poly;
	vector<Vec4i> hierarchy;
	findContours(filtered_grey, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0,0));
		//get the areas
		vector<double> areas;
		for(unsigned int i = 0; i < contours.size(); i++)
		{
			vector<Point> poly;
			approxPolyDP(contours[i], poly, 10, true);
			contours_poly.push_back(poly);
			areas.push_back(contourArea(poly));
		}
	//draw the biggest
	int biggest_index = -1;
	int biggest_area = 0;
	for(unsigned int i = 0; i < areas.size(); i++)
	{
		if(areas[i] > biggest_area)
		{
			biggest_area = areas[i];
			biggest_index = i;
		}
	}
		Mat drawing = Mat::zeros( filtered_grey.size(), CV_8UC3 );
		drawContours( drawing, contours_poly, biggest_index, Scalar(255,255,255,225), 2, 8, hierarchy, 0, Point() );

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
		

	//precorner
	/*Mat features;

	//corner detection

  int blockSize = 2;
  int apertureSize = 7;
  double k = 0.04;
  Mat corners;

  /// Detecting corners
  cornerHarris( features, corners, blockSize, apertureSize, k, BORDER_DEFAULT );

  /// Normalizing

  Mat corners_norm, corners_norm_scaled;
  normalize( corners, corners_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
  convertScaleAbs( corners_norm, corners_norm_scaled );

  /// Drawing a circle around corners
  for( int j = 0; j < corners_norm.rows ; j++ )
     { for( int i = 0; i < corners_norm.cols; i++ )
          {
            if( (int) corners_norm.at<float>(j,i) > 200 )
              {
               circle( features, Point( i, j ), 5,  Scalar(255,255,255,255), 2, 8, 0 );
              }
          }
     }
	
	*/
	
	//imshow("Sample Program", features);
	//imshow("Sample Program", filtered);
	imshow("Sample Program", drawing);
 
	int c = cvWaitKey(10);
	if( (char)c == 27 ) { exit(0); }
 
}
 
// clean up and release resources
//cvReleaseImage(&frame);
 
return 0;
 
}
