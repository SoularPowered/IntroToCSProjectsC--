/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description:  fallDistance.cpp (4.a)
** Contains a function that accepts time and returns the distance
**         d = 1/2 * g * t^2
** Where gravity is 9.8 meters per second squared (9.8 N)
*********************************************************************/

/*********************************************************************
** Description: fallDistance() accepts the falling time, t, and
** returns the distance, a double
*********************************************************************/
double fallDistance (double t)
{
	double distance;
	const double G = 9.8; // constant for force of gravity on earth
	distance = (1.0/2.0) * G * t * t;

	return distance;
}