/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 1, 2015
** Description: Item.hpp
** Item is a simple object type which holds a name, price, and 
** quantity. The total cost of an individual Item would be
** the price * quantity, but this is not implemented (rather, this is
** done by ShoppingCart class, which uses this class.)
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item
{
private:
	std::string name;
	double price; // price per unit
	int quantity; // quantity of units
public:
	// Constructors
	Item();
	Item(std::string, double, int);

	// Setters (Mutators)
	void setName(std::string);
	void setPrice(double);
	void setQuantity(int);

	// Getters (Accessors)
	std::string getName();
	double getPrice();
	int getQuantity();
};

#endif