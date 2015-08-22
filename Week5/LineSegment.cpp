/*********************************************************************
** Author: Shawn S Hillyer
** Date: July 19, 2015
** Description: LineSegment.cpp
** Implementation for LineSegment class in LineSegment.hpp
*********************************************************************/
#include "LineSegment.hpp"

/*********************************************************************
** Description: CONSTRUCTOR
** LineSegment::LineSegment is default constructor. Calls setters
** to pass the Point object values into the member variables
*********************************************************************/
LineSegment::LineSegment(Point end1in, Point end2in)
{
	setEnd1(end1in);
	setEnd2(end2in);
}

/*********************************************************************
** Description:  SETTERS
** Setter functions. Updates the xCoord and yCoord member variables
*********************************************************************/
void LineSegment::setEnd1(Point end1in)
{
	end1 = end1in;
}

void LineSegment::setEnd2(Point end2in)
{
	end2 = end2in;
}

/*********************************************************************
** Description: GETTERS
** Getter functions. Returns the values stored in member variables
*********************************************************************/ 
Point LineSegment::getEnd1()
{
	return end1;		
}

Point LineSegment::getEnd2()
{
	return end2;
}

/*********************************************************************
** Description:
** length() returns the length of the LineSegment by calculating the
** distance between the two endpoints and returning that value.
*********************************************************************/ 
double LineSegment::length()
{
	double length;

	length = end1.distanceTo(end2);

	return length;
}

/*********************************************************************
** Description:
** length() returns the slope of the LineSegment dividing the change
** in the y coordinates divided by change in x coordinates
*********************************************************************/ 
double LineSegment::slope()
{
	double slope, changeInX, changeInY; 

	// Problem subdivided to make formula easier to read
	changeInX = end2.getXCoord() - end1.getXCoord();
	changeInY = end2.getYCoord() - end1.getYCoord();
	slope = changeInY / changeInX; 

	return slope;
}