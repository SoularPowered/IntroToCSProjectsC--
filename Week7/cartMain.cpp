/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 1, 2015
** Description: CartMain.cpp
** Testing client for ShoppingCart and Item classes
*********************************************************************/
#include "ShoppingCart.hpp"
#include <iostream>
#include <string>

void printItem(Item&, std::string);
void setItem(Item&, std::string, double, int);
char intToChar(int);
std::string intToStr(int, std::string);

std::string intToStr(int n, std::string s)
{
	if ((n / 10) != 0) {
		s = intToStr((n / 10), s);
	}
	int intDigit = n % 10;
	char charDigit = intToChar(intDigit);

	s.append(1, charDigit);
	return s;
}

char intToChar(int i)
{
	char character = (i + 48); // char is stored as bytes
	return character;
} // 48 is the offset in ascii to have i + 48 = '0'; sequential up to digit 9

int main()
{

	// Test Item Constructors
	Item item1; // no arguments
	Item item2("Item 2 Name", 2.00, 2); // pass the 3 arguments (string, double, int)

	// Test getters by calling printItem
	printItem(item1, "item1");
	printItem(item2, "item2");

	// Test setters by calling setItem
	setItem(item1, "Item 1 New Name", 1.00, 1);
	printItem(item1, "item1");

	// Test ShoppingCart constructor
	std::cout << "Creating a test cart..." << std::endl;
	ShoppingCart testCart1; // default constructor

	// Test adding an item to array...
	std::cout << "Adding item1..." << std::endl;
	testCart1.addItem(&item1);
	std::cout << "Total price is: " << testCart1.totalPrice() << std::endl;

	std::cout << "Adding item2..." << std::endl;
	testCart1.addItem(&item2);
	std::cout << "Total price is: " << testCart1.totalPrice() << std::endl;


	// Test code from assignment description
	Item a("affadavit", 179.99, 12);
	printItem(a, "a");
    Item b("Bildungsroman", 0.7, 20);
    printItem(b, "b");
    Item c("capybara", 4.5, 6);
    printItem(c, "c");
	Item d("dirigible", 0.05, 16);
	printItem(d, "d");
	ShoppingCart sc1;
	sc1.addItem(&a);
	sc1.addItem(&b);
	sc1.addItem(&c);
	sc1.addItem(&d);
	double diff = sc1.totalPrice();
	std::cout << "sc1.totalPrice() is: " << diff << std::endl;

	// Now, we're going to make at least 100 items in an array and then add them all to the cart...

	ShoppingCart sc1;
	double totalPrice = 0;
	std::string itemName;

	Item myItems[200];
	
	int i = 0;
	do
	{
		std::cout << "totalPrice before this add: " << sc1.totalPrice() << std::endl;
		itemName.clear();
		itemName = "myItem[";
		std::string ind = "";
		ind = intToStr(i, ind);
		itemName.append(ind);
		itemName.append("]");
		myItems[i].setName(itemName);
		myItems[i].setPrice(i * .1357);
		myItems[i].setQuantity(i+1);
		printItem(myItems[i], itemName);
	} while (sc1.addItem(&myItems[i++]));

	totalPrice = sc1.totalPrice();
	std::cout << "totalPrice after adding all items: " << totalPrice << std::endl;

	return 0;
}



void printItem(Item& i, std::string itemName)
{
	std::cout << itemName << ".get() tests: " << std::endl;
	std::cout << itemName << ".getName() returns: " << i.getName() << std::endl;
	std::cout << itemName << ".getPrice() returns: " << i.getPrice() << std::endl;
	std::cout << itemName << ".getQuantity() returns: " << i.getQuantity() << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;
}

void setItem(Item& i, std::string name, double price, int quantity)
{
	std::cout << "Calling setName(" << name << ")." << std::endl;
	i.setName(name);
	
	std::cout << "Calling setPrice(" << price << ")." << std::endl;
	i.setPrice(price);

	std::cout << "Calling setQuantity(" << quantity << ")." << std::endl;
	i.setQuantity(quantity);
	
}