/*********************************************************************
** Author: Shawn S Hillyer
** Date: July 19, 2015
** Description: LineSegment.hpp
** This class allows for the definition of a line segment on the 
** Cartesian plane. Each LineSegment consists of two Points which can
** call their respective member functions to enable user to determine
** the length and slope of the line segment.
*********************************************************************/
#ifndef POINT_HPP
#define POINT_HPP
#include "Point.hpp"

class LineSegment
{
private:
	Point end1;
	Point end2;

public:
	// Constructors
	LineSegment(Point, Point);

	// Setters (Mutators)
	void setEnd1(Point);
	void setEnd2(Point);

	// Getters (Accessors)
	Point getEnd1();
	Point getEnd2();

	// Calculations
	double length();
	double slope();
};
#endif