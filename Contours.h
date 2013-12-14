#ifndef _CONTOURS_H
#define _CONTOURS_H

#include <vector>
#include "opencv2/core/core.hpp"

#define AREA_RATIO .1


void GetContours(Mat image, vector<vector<Point> >& out_contours, vector<Vec4i>& out_hierarchy);

vector<vector<Point> > GetTargetContours(const vector<vector<Point> >& all_contours, const vector<Vec4i>& hierarchy);


#endif