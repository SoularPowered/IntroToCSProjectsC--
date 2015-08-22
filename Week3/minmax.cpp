/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.05.15
** Description:  Project 3.c - Asks user how many integers they would
** 		like to enter. After all entered, should display the largest
**		and smallest of those numbers.
*********************************************************************/

#include <iostream>

int main()
{
	// Variable declarations
	int qtyIntegers = 0; 		// how many integers user wants to input
	long  	inputInteger = 0, 	// holds current input to compare to current min/max
			minInt = 0, 		// to store lowest value entered
			maxInt = 0;   		// to store highest value entered

	// Get quantity of integers to input from user		
	std::cout << "How many integers would you like to enter?" << std::endl;
	std::cin >> qtyIntegers;

	// Handle invalid input
	while (qtyIntegers < 1) 
	{
		std::cout << "You must choose to enter at least 1 integer." << std::endl;
		std::cout << "How many integers would you like to enter?" << std::endl;
		std::cin >> qtyIntegers;
	}
	
	// Handle singular vs. plural verbiage for a single integer vs multiple
	if (qtyIntegers == 1) 
	{
		std::cout << "Please enter an integer." << std::endl;
	}
	else
	{
		std::cout << "Please enter " << qtyIntegers << " integers." << std::endl;
	}

	// Get first integer and store its value into minInput and
	std::cin >> inputInteger;
	minInt = maxInt = inputInteger;

	// start counter i = 1 because we already collected first input
	for (int i = 1; i < qtyIntegers; i++) 
	{
		std::cin >> inputInteger;

		if (inputInteger > maxInt)
		{
			 maxInt = inputInteger; 
		}
		else if (inputInteger < minInt)
		{
			minInt = inputInteger;
		}
	}
	
	// Print results
	std::cout << "min: " << minInt << std::endl;
	std::cout << "max: " << maxInt << std::endl;

	return 0;
}
