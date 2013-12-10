#include "stdafx.h"
#include "ColorFilter.h"
#include "Settings.h"

#define UINT8 unsigned char

Mat FilterImage(Mat image)
{
	Mat hsv;

	//convert to HSV
	cvtColor(image, hsv, CV_BGR2HSV);

	//get the channels;
	vector<Mat> v_channel(3);
	split(hsv,v_channel);
	//treshold
	for(int y = 0; y<hsv.rows; y++)
	{
		for(int x = 0; x<hsv.cols; x++){
			Point ref(x, y);
			UINT8 h, s, v;
			h = v_channel[0].at<UINT8>(ref);
			s = v_channel[1].at<UINT8>(ref);
			v = v_channel[2].at<UINT8>(ref);
			//treshold
			if(v < MINVALUE) //value is low
				hsv.at<Vec3b>(ref) = Vec3b();

			if(h < MINHUE || h > MAXHUE) //hue is not within limits
				hsv.at<Vec3b>(ref) = Vec3b();

			if(s < MINSATURATION || s > MAXSATURATION) //saturation not within limits
				hsv.at<Vec3b>(ref) = Vec3b();

			if(x == 360 && y == 240)
			{
				int a = 1;
			}
		}
	}

	//convert back to BGR
	Mat backcvt;
	cvtColor(hsv, backcvt, CV_HSV2BGR);

	return backcvt;
}