/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description:  hailstone.cpp (4.c)
** Initiates a hailstone sequence and returns number of steps it takes
** to initially reach the value 1
*********************************************************************/

/*********************************************************************
** Description: hailstone() accepts a positive integer and begins a
** sequence of calculations (if int is even, divide by 2,
** if odd, multiply by 3 and add one; then, repeat until
** hitting 1.
** Function returns the number of steps it takes to reach 1
*********************************************************************/
int hailstone(int value)
{
	int counter = 0; // to store the count and return to caller

	while (value != 1) // only manipulate if value is not 1
	{
		if (value % 2 == 0) // if number even
		{
			value /= 2;
		}
		else // else it's odd
		{
			value = (value * 3) + 1;
		}
		counter++;
	}
	return counter; 
}