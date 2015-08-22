/*********************************************************************
** Author: Shawn Hillyer
** Date: 07.27.2015
** Description: A test client to use with group assignment to test classes
*********************************************************************/

#include <iostream>
#include "Point.hpp"

void printPoint(Point &p);

int main()
{
    // Client tests Point::getXCoord and Point::getYCoord during the call to perintPoint
	//test Point default constructor
    std::cout << "Testing constructor - default value of 0, 0." << std::endl;

    Point defaultPoint;
    printPoint(defaultPoint);

    // test Point argument constructor
    const double testX = 13.3, testY = 24.5;
    std::cout << "Testing constructor - args " << testX << ", " << testY << std::endl;

    Point argPoint(testX, testY);
    printPoint(argPoint);
    
    // test setXCoord and setYCoord

    argPoint.setXCoord(10);
    argPoint.setYCoord(0);
    std::cout << "Changing values to 10 and 0 for argPoint... " << std::endl;
    printPoint(argPoint);

    // test distanceTo using 0,0 (defaultPoint) and 10, 0 (argPoint)

    std::cout << "The distance from defaultPoint at: " << std::endl;
    printPoint(defaultPoint);
    std::cout << "and argPoint at: " << std::endl;
    printPoint(argPoint);
    std::cout << "is: " << defaultPoint.distanceTo(argPoint) << std::endl;

    // Set some new objects manually
    double x1, y1, x2, y2;
    std::cout << "Enter object 1 x:";
    std::cin >> x1;
    std::cout << "Enter object 1 y:";
    std::cin >> y1;

    std::cout << "Enter object 2 x:";
    std::cin >> x2;
    std::cout << "Enter object 2 y:";
    std::cin >> y2;

    Point point1(x1, y1);
    Point point2(x2, y2);

    std::cout << "The distance from point1 at: " << std::endl;
    printPoint(point1);
    std::cout << "and point2 at: " << std::endl;
    printPoint(point2);
    std::cout << "is: " << point1.distanceTo(point2) << std::endl;
/*
    // test LineSegment class

	LineSegment ls1(point1, point2);
	double length = ls1.length();
	double slope = ls1.slope();

	std::cout << "The length is " << length << std::endl;
	std::cout << "The slope is " << slope << std::endl;

    // Test infinity slope
    point1.setXCoord(0);
    point1.setYCoord(0);
    point2.setXCoord(0);
    point2.setYCoord(100);

    LineSegment infinityLine(point1, point2);
    length = infinityLine.length();
    slope = infinityLine.slope();

    std::cout << "The length is (should be 100) " << length << std::endl;
    std::cout << "The slope is (should be infinity) " << slope << std::endl;

    // Test zero slope
    point1.setXCoord(0);
    point1.setYCoord(0);
    point2.setXCoord(-100);
    point2.setYCoord(0);

    LineSegment zeroSlopeLine(point1, point2);
    length = zeroSlopeLine.length();
    slope = zeroSlopeLine.slope();

    std::cout << "The length is (should be 100) " << length << std::endl;
    std::cout << "The slope is (should be 0 or -0)" << slope << std::endl;

    //test both of the above with inverted signs
    // Test infinity slope
    point1.setXCoord(0);
    point1.setYCoord(0);
    point2.setXCoord(0);
    point2.setYCoord(-100);

    LineSegment infinityLine2(point1, point2);
    length = infinityLine2.length();
    slope = infinityLine2.slope();

    std::cout << "The length is (should be 100) " << length << std::endl;
    std::cout << "The slope is (should be infinity) " << slope << std::endl;

    // Test zero slope
    point1.setXCoord(0);
    point1.setYCoord(0);
    point2.setXCoord(100);
    point2.setYCoord(0);

    LineSegment zeroSlopeLine2(point1, point2);
    length = zeroSlopeLine2.length();
    slope = zeroSlopeLine2.slope();

    std::cout << "The length is (should be 100) " << length << std::endl;
    std::cout << "The slope is (should be 0 or -0)" << slope << std::endl;

*/
    return 0;
}

// tests getXCoord and getYCoord for any Point object
void printPoint(Point &point)
{
	std::cout << "xCoord: " << point.getXCoord() << std::endl;
	std::cout << "yCoord: " << point.getYCoord() << std::endl;
}