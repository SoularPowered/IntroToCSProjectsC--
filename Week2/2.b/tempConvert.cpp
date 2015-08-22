/*********************************************************************
** Author: Shawn S Hillyer
** Date: 06.28.2015
** Description: Project 2.b - tempConvert.cpp
** 				Converts a temperature input as Celsius and
** 				displays its value express as Fahrenheit
*********************************************************************/

#include <iostream>

int main()
{
	// Variable declarations
	const double K = 9.0 / 5.0;  // mathematical constant representing 9/5, stored as a double to force expresion to calculate as a double later. I know this isn't strictly necessary the way I've implemented the expression...
	double celsius = 0, fahrenheit = 0; 

	// Get input from user
	std::cout << "Please enter a Celsius temperature." << std::endl;
	std::cin >> celsius;

	// Calculate the Fahrenheit equivalent
	fahrenheit = K * celsius + 32;

	// Display the Fahrenheit value
	std::cout << "The equivalent Fahrenheit temperature is: " << std::endl;
	std::cout << fahrenheit << std::endl;

	return 0;
}
