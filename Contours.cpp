#include "stdafx.h"
#include "Contours.h"
#include <vector>
#include "opencv2/features2d/features2d.hpp"

bool contourAreaComparer(const vector<Point>& a, const vector<Point>& b) {
   return contourArea(a) > contourArea(b);
}


void GetContours(Mat image, vector<vector<Point> >& out_contours, vector<Vec4i>& out_hierarchy)
{
		findContours(image, out_contours, out_hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0,0));
}

vector<vector<Point> > GetTargetContours(const vector<vector<Point> >& all_contours, const vector<Vec4i>& hierarchy)
{

	//get the areas
	vector<double> areas;
	vector<vector<Point> > contours_poly;
	for(unsigned int i = 0; i < all_contours.size(); i++)
	{
		vector<Point> poly;
		approxPolyDP(all_contours[i], poly, 4, true);
		contours_poly.push_back(poly);
	}
	//get the biggest
	std::sort(contours_poly.begin(), contours_poly.end(), contourAreaComparer);

	vector<vector<Point> > ret;

	if(contours_poly.size() > 0)
	{
		double maxsize = contourArea(contours_poly[0]);
		for(int i = 0; i < contours_poly.size(); i++){
			if(contourArea(contours_poly[i]) >= maxsize * AREA_RATIO)
				ret.push_back(contours_poly[i]);
		}
	}



	return ret;
}