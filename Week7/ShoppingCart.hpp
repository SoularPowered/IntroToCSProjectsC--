/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 1, 2015
** Description: ShoppingCart.hpp
** This class is a Shopping Cart that can hold up to 100 items, stored
** by reference in an array of pointers to Item, another custom class.
** The default constructor points all of the array to null and the
** addItem function will return false if an attempt to call the 
** function fails because it would exceed the bounds of the array.
** totalPrice uses the arrayEnd to add up all of the items qty*price
*********************************************************************/

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "Item.hpp"

class ShoppingCart
{
private:
	Item* items[100]; // array that can hold up to 100 Item pointers
	int arrayEnd;

public:
	// Constructors
	ShoppingCart();

	// Setters (Mutators)
	void setArrayEnd(int);

	// Getters (Accessors)
	int getArrayEnd();

	// Other
	bool addItem(Item*);
	double totalPrice();
};

#endif