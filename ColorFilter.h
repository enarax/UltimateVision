#ifndef _COLORFILTER_H
#define _COLORFILTER_H

#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

#ifdef WEBCAM
//webcam
#define BLURSIZE 3
#define MINVALUE 35
#define MINHUE 80
#define MAXHUE 90
#define MINSATURATION 120
#define MAXSATURATION 255
#else
//robotcam - TBD
#define BLURSIZE 3
#define MINVALUE 64
#define MINHUE 160
#define MAXHUE 200
#define MINSATURATION 50
#define MAXSATURATION 100
#endif


Mat FilterImage(const Mat& image);

#endif
