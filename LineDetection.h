#ifndef _LINEDETECTION_H
#define _LINEDETECTION_H

#include "opencv2/imgproc/imgproc.hpp"

int const lowThreshold = 20;
int const  ratio = 3;
int const kernel_size = 3;

Mat DetectEdges(const Mat& filtered_grey);

Mat DetectLines(const Mat& edges);


#endif