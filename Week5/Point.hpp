/*********************************************************************
** Author: Shawn S Hillyer
** Date: July 19, 2015
** Description: Point.hpp
** This class can be used to designate a point on the Cartesian plane 
** system. It is able to report the distance between two points. 
** The "get" functions are const because they do not modify any member
** variables. distanceTo() also const as it accepts a const and calls
** get functions; requires them to be const.
*********************************************************************/
#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
	double xCoord;
	double yCoord;
public:
	// Constructors
	Point();
	Point(double, double);

	// Setters (mutators)
	void setXCoord(double);
	void setYCoord(double);

	// Getters (accessors)
	double getXCoord();
	double getYCoord();

	// Calculations
	double distanceTo(const Point&);
};
#endif