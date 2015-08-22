/*********************************************************************
** Author: 	Shawn S Hillyer
** Dcate:	July 25, 2015
** Description: findMode.cpp
** Contains the function findMode() which accepts an array of type int
** and the size of the array (as an int) as constants and returns a
** vector containing the mode of the number set arranged in ascending
** order (without duplicate listings of the mode).
*********************************************************************/
#include <vector>
#include <algorithm> // required for std::sort()

// Prototype for helper function
int countOccurences(std::vector<int> nums, int size, int i, int &lastIndex);

/*********************************************************************
** Description: findMode()
** findMode returns a vector containing the mode or modes in ascending
** order. Requires the address of the array and the size as arguments.
*********************************************************************/
std::vector<int> findMode(int numbers[], int size)
{

	/* Copy the array into a vector then sort it to make our counting
	faster & presorts numbers before pushing to mode vector later */
	std::vector<int> numVect;
	for (int i = 0; i < size; i++)
	{
		numVect.push_back(numbers[i]);
	}
	std::sort(numVect.begin(), numVect.end());

	int maxCount = 0, 	// most occurences of any element of the vector
		valueCount, 	// how many times the value in current index was found
		nextIndex;		// used to skip over elements we've already counted (because vector is presorted)

	// Iterate over the sorted vector, counting each different value until we know the most any given value occurs
	for (int i = 0; i < size; i = nextIndex)
	{
		valueCount = countOccurences(numVect, size, i, nextIndex);
		// if the number just counted occured the most, store its count in maxCount
		if (valueCount > maxCount)
		{
			maxCount = valueCount;
		}
	}

	// Iterate again, then store value at numVect[i] into the mode vector if it was one of the values that occured the most often
	std::vector<int> mode; // used to store the mode
	for (int i = 0; i < size; i = nextIndex)
	{
		valueCount = countOccurences(numVect, size, i, nextIndex);

		if (valueCount == maxCount)
		{
			mode.push_back(numVect[i]); // will only push any given value once, since we skipped duplicates, and already sorted
		}
	}
	return mode; // container has all modes in sorted order with no duplicates
}

/*********************************************************************
** Description: countOccurences()
** searches a sorted vector for the value at index [i] and counts
** how many times it occurs. Stops counting when a value is not equal
** to the search value
*********************************************************************/
int countOccurences(std::vector<int> nums, int size, int i, int &nextIndex)
{
	int occurences = 0;
	int searchValue = nums[i]; // store here since we update i during the while lop
	// Iterate until exceed bounds of the vector or move to a new number in sorted vector
	while (i < size && (nums[i] == searchValue)) 
	{
		occurences++;
		nextIndex = ++i; //  update so the calling function knows the next index to count from
	}
	return occurences;
}