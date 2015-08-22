/*********************************************************************
** Author: Shawn S Hillyer
** Date: July 19, 2015
** Description: Point.cpp
** Implementation for Point class in Point.hpp
*********************************************************************/
#include "Point.hpp"
#include <cmath>

/*********************************************************************
** Description: CONSTRUCTOR
** Point::Point() is default constructor. Sets coordinates to 0, 0.
*********************************************************************/
Point::Point()
{
	setXCoord(0);
	setYCoord(0);
} 

/*********************************************************************
** Description: CONSTRUCTOR
** Point::Point(double, double) sets xCoord and yCoord to the passed
** values by calling set functions.
*********************************************************************/
Point::Point(double xCoordIn, double yCoordIn)
{
	setXCoord(xCoordIn);
	setYCoord(yCoordIn);
}

/*********************************************************************
** Description: SETTERS
** Setter functions. Updates the xCoord and yCoord member variables
*********************************************************************/
void Point::setXCoord(double xCoordIn)
{
	xCoord = xCoordIn;
}

void Point::setYCoord(double yCoordIn)
{
	yCoord = yCoordIn;
}

/*********************************************************************
** Description: GETTERS
** Getter functions. Returns the values stored in member variables
*********************************************************************/ 
double Point::getXCoord()
{
	return xCoord;
}

double Point::getYCoord()
{
	return yCoord;
}

/*********************************************************************
** Description:
** distanceTo() calculates the distance between the calling
** instance of Point and the argument Point object, referred to by 
** pointB
** Per Pythagoras Theorum, the distance between two points P and Q is:
** square root ( (x sub 2 - x sub 1)^2 + (y sub 2 - y sub 1)^2 )
** square root of the sum of (the change in x) squared 
** plus (change in y) squared
*********************************************************************/
double Point::distanceTo(const Point& pointB)
{
	double distance, changeInXSqrd, changeInYSqrd;

	/* changeInXSqrd and changeInYSqrd calculated separately to make formula for
	distance more readable. Also note, pointB is sub 2, calling Point object is sub 1 */
	changeInXSqrd = pow(pointB.xCoord - xCoord, 2);
	changeInYSqrd = pow(pointB.yCoord - yCoord, 2); 
	
	distance = sqrt(changeInXSqrd + changeInYSqrd);

	return distance;
}