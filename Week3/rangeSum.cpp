/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.04.15
** Description:  Project 3.b - rompts the user to enter two integers 
** 				 and then adds up all the integers between them
**				 (inclusive) and displays the total
*********************************************************************/

#include <iostream>

int main()
{
	long input1 = 0, input2 = 0, highVal = 0, lowVal = 0; 

	// Get the two integers from user and store in 2 vars
	std::cout << "Please enter two integers." << std::endl;
	std::cin >> input1;
	std::cin >> input2;

	// Assign the higher of the two to highVal, lower to lowVal
	if (input1 > input2)
	{
		highVal = input1;
		lowVal = input2;
	}

	// Do the opposite assignment if input2 bigger... however, in this case, I also
	else if ((input2 > input1) || (input2 == input1)) 
	{
		highVal = input2; 
		lowVal = input1; 
	} 

	long accumulator = 0; // used to calculate the total

	do // using a do statement because I want to execute at least once if vals same
	{
		accumulator += lowVal; 	// add the lowest value to accumulator
		lowVal++;				// increment 1 int value up to and inclusive of highVal
	} while (lowVal <= highVal);

	std::cout << "The sum of the values in that range is:" << std::endl;
	std::cout << accumulator << std::endl;

	return 0;
}