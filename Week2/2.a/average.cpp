/*********************************************************************
** Author: Shawn S Hillyer
** Date: 06.28.2015
** Description: Project 2.a - average.cpp
** 				This program averages 5 numbers input by user and
**				prints the result to the screen
*********************************************************************/

#include <iostream>

int main()
{
	// Declare variables
	double	num1 = 0, num2 = 0,	num3 = 0, num4 = 0, num5 = 0, 	// We haven't covered arrays yet so need to use 5 numbers
			average = 0;						// Will store the calculated average of the numbers
	/*  I initialize all to 0 or another logical value as necessary so that I have no unexpected values floating around in my vars */
	
	// Prompt user to input the 5 values
	std::cout << "Please enter five numbers." << std::endl;
	std::cin >> num1 >> num2 >> num3 >> num4 >> num5; // cin will read each value in separated by whitespace, presumably \n but the specifications to not allow me to specific to user anything more

	// Calculate the average as sum of numbers (num1 + num2 + ... + numN) / n, in this case n = 5
	average = (num1 + num2 + num3 + num4 + num5) / 5;

	// Display the result
	std::cout << "The average of those numbers is: " << std::endl << average << std::endl;

	return 0; // to indicate that program terminated succesfully.
}