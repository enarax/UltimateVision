#include "stdafx.h"
#include "LineDetection.h"

Mat DetectEdges(const Mat& filtered_grey)
{
	Mat detected;
		Canny( filtered_grey, detected, lowThreshold, lowThreshold*ratio, kernel_size );
	return detected;
}