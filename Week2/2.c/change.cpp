/*********************************************************************
** Author: Shawn S Hillyer
** Date: 06.28.2015
** Description: Project 2.c - change.cpp
** 				Prints to screen the smallest number of coins and
**				their deonominations (Q,D,N,P) that can be used to
**				represent a value between 0 and 99
*********************************************************************/

#include <iostream>

int main()
{
	int cents = 0, // input from user. We are expecting val of 0 to 99 but no way to validate input using what we've covered thus far
		quarters = 0, dimes = 0, nickels = 0, pennies = 0;

	// Get input
	std::cout << "Please enter an amount in cents less than a dollar." << std::endl;
	std::cin >> cents;

	// Calculate the coins. Purposefully using int division, as we only want int results and drop any remainder. Partial coins do not make sense in this context.
	quarters = cents / 25; 		// Start by determining max # of quarters we can use
	cents -= (quarters * 25); 	// subtract the cents represented by the quantity of the quarters we've calculated
	dimes = cents / 10; 		// Do the same with dimes, the next-largest denomination
	cents -= (dimes * 10); 		// less the cents represented by the dimes...
	nickels = cents / 5; 		// Then nickels
	cents -= (nickels * 5); 	// less cents represented by nickels
	pennies = cents; 			// whatever value of cents left must be the pennies; also, (cents / 1) would always == cents

	// Print the results per the specifications of the program description 2.c
	std::cout << "Your change will be: " << std::endl;
	std::cout << "Q: " << quarters << std::endl;
	std::cout << "D: " << dimes << std::endl;
	std::cout << "N: " << nickels << std::endl;
	std::cout << "P: " << pennies << std::endl;

	return 0;
}