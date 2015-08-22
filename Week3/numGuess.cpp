/*********************************************************************
** Author: Shawn S. Hillyer
** Date:   07.04.15
** Description:  Project 3.a - number guessing game
*********************************************************************/

#include <iostream>

int main()
{
	long 	numberToGuess = 0, 	
			playerGuess = 0;
	unsigned guessCounter = 0;	// counter will increment during while loop

	// Get number that player/user will later guess
	std::cout << "Enter the number for the player to guess." << std::endl;
	std::cin >> numberToGuess;

	// Get input for guess before later entering the loop
	std::cout << "Enter your guess." << std::endl;
	
	do // while playerGuess != numberToGuess
	{
		std::cin >> playerGuess;

		if (playerGuess > numberToGuess) // if the guess is higher than the number to guess
		{
			std::cout << "Too high - try again." << std::endl;
		}
		else if (playerGuess < numberToGuess) 
		{
			std::cout << "Too low - try again." << std::endl;
		}

		guessCounter++; // increment counter after every guess regardless of high/low/right
	} while (playerGuess != numberToGuess);

	std::cout << "You guessed it in " << guessCounter << " tries." << std::endl;

	return 0;
}