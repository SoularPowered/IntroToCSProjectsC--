/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.11.2015
** Description: smallSort.cpp (4.b) contains a function smallSort that
**      accepts three int values and updates their values so that they
**      are in ascending order where a < b < c
*********************************************************************/


/*********************************************************************
** Description: smallSort() arranges the 3 arguments passed in ascending
**  			order
*********************************************************************/
void smallSort(int& a, int& b, int& c)
{
	int min, mid, max; // to assign the lowest, middle, and max

	// handle all cases where a is smallest
	if (a <= b && a <= c) 
	{
		min = a;
		if (b <= c)
		{
			mid = b;
			max = c;
		}
		else
		{
			mid = c;
			max = b;
		}
	}

	// handle cases where b is smallest
	else if (b <= a && b <= c)
	{
		min = b;
		if (a <= c)
		{
			mid = a;
			max = c;
		}
		else
		{
			mid = c;
			max = a;
		}
	}

	// handles cases where c is smallest (all other cases)
	else
	{
		min = c;
		if (a < b)
		{
			mid = a;
			max = b;
		}
		else
		{
			mid = b;
			max = a;
		}
	}

	// assign the a, b, c with min, mid, and max back so the values in correct order
	a = min; 
	b = mid;
	c = max; 
}