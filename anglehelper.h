#pragma once

#define PI 3.14159265359
#define PIHALF 1.57079632679

#include <math.h>

inline double min(double a, double b)
{
	return a < b ? a : b;
};

inline double max(double a, double b)
{
	return a > b ? a : b;
};

inline double angleDistance(double firstAngle, double secondAngle)
  {
        double difference = secondAngle - firstAngle;
        while (difference < -PI) difference += 2*PI;
        while (difference > PI) difference -= 2*PI;
        return difference;
 };

inline double angleDistanceAbs(double firstAngle, double secondAngle)
{
	return abs(angleDistance(firstAngle, secondAngle));
};

inline double rightAngleDistanceAbs(double firstAngle, double secondAngle)
{
	return min(angleDistanceAbs(firstAngle, secondAngle), angleDistanceAbs(firstAngle, secondAngle + PIHALF));
};





