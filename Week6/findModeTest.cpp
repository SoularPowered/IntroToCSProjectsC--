// findModeTest.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

std::vector<int> findMode(int numbers[], int size);

int main()
{
	srand(time(0));
	const int SIZE = 100;
	int quickArray[SIZE];

	std::cout << "Values before: ";
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			quickArray[i] = i;
		else
			quickArray[i] = -i;
		std::cout << quickArray[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::sort(quickArray, quickArray + SIZE);

	std::cout << "Values after sort: ";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << quickArray[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::vector<int> result = findMode(quickArray, SIZE);

	std::cout << "Mode(s): ";
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	std::cin.get();
	return 0;
}