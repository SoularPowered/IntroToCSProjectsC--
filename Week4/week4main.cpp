#include <iostream>
#include <string>

using namespace std;
double fallDistance (double);
void smallSort(int&, int&, int&);
int hailstone(int value);

int main()
{
	cout << "TESTING: fallDistance.cpp " << endl;

	double distance;
	for (int t = 0; t < 20; t++)
	{
		distance = fallDistance(t);
		cout << "Time is: " << t << "    Distance is: " << distance << " meters." << endl;
	}

	cout << "TESTING: smallSort.cpp " << endl;

    int a = -10;
    int b = 0;
    int c = 10;
    smallSort(a, b, c);
    cout << a << ", " << b << ", " << c << endl;

    a = -11;
    b = 11;
    c = 0;
    smallSort(a, b, c);
    cout << a << ", " << b << ", " << c << endl;

    a = 0;
    b = -12;
    c = 12;
    smallSort(a, b, c);
    cout << a << ", " << b << ", " << c << endl;


    a = 0;
    b = 13;
    c = -13;
    smallSort(a, b, c);
    cout << a << ", " << b << ", " << c << endl;


    a = 14;
    b = 0;
    c = -14;
    smallSort(a, b, c);
    cout << a << ", " << b << ", " << c << endl;

    a = 15;
    b = -15;
    c = 0;
    smallSort(a, b, c);
    cout << a << ", " << b << ", " << c << endl;



	cout << "TESTING: hailstone.cpp " << endl;

	int count;

	cout << "Passing 5: " << hailstone(5) << endl;
	cout << "Passing 1: " << hailstone(1) << endl;
	cout << "Passing 10: " << hailstone(10) << endl;
	cout << "Passing 3: " << hailstone(3) << endl;

	return 0;
}