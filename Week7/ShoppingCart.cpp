/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 1, 2015
** Description: ShoppingCart.cpp
** Implementation of ShoppingCart class
*********************************************************************/
#include "ShoppingCart.hpp"

/*********************************************************************
** Description: Default constructor
** Sets all of the Item* pointers to point to NULL and sets the 
** arrayEnd to 0. This means that the first element added will have
** arrayEnd 1, and the last (100th) element will have arrayEnd 100.
** This is NOT the same as the index of the last element (that would
** be arrayEnd - 1.)
*********************************************************************/
ShoppingCart::ShoppingCart()
{
	for (int i = 0; i < 100; i++)
	{
		items[i] = NULL; // make all elements point to NULL
	}
	setArrayEnd(0); // End of the array starts at 0. 
}

/*********************************************************************
** Description: Set the arrayEnd to the passed value. Basic setter
** Will not allow a value to be set to negative or > 100
** Because arrayEnd starts at 0, it actually means that the last ele
** of the array with an Item is (arrayEnd - 1).
** Called by ShoppingCart::addItem()
*********************************************************************/
void ShoppingCart::setArrayEnd(int end)
{
	if (end < 0) // end of the array can never be negative
		arrayEnd = 0;
	else if (end > 100) // nor will it exceed 100 elements
		arrayEnd = 100; 
	else // otherwise, set it to the appropriate value.
		arrayEnd = end;
}

/*********************************************************************
** Description: Returns the arrayEnd member variable's value
*********************************************************************/
int ShoppingCart::getArrayEnd()
{
	return arrayEnd;
}

/*********************************************************************
** Description: Add an item by accepting the address of that object.
** If the ShoppingCart is full (already 100 items stored) then this
** function will return false and will not attempt to write outside
** the bounds of the array, nor increment arrayEnd.
*********************************************************************/
bool ShoppingCart::addItem(Item* newItem)
{
	if (arrayEnd >= 100) // Prevents overflow out of array
	{
		return false; // returns false to calling code to indicate failure
	}
	else
	{
		items[arrayEnd] = newItem; // arrayEnd is the index of the next NULL pointer, so add our item to the element at this position
		setArrayEnd(++arrayEnd); // increment the arrayEnd then pass it to the setter for bounds checking purposes
		return true; // signal success to calling code
	}

}

/*********************************************************************
** Description: Returns the total price of all items in the Shopping
** Cart. Starts at element 0 and stops 1 shy of the arrayEnd, which
** actually signifies to next empty element. If array is full, will
** stop accumulating at the end of the array.
*********************************************************************/
double ShoppingCart::totalPrice()
{
	double totalPrice = 0; // Set an accumulator to 0
	double itemCost; // holds cost of a single item in array - used for readability only

	/* Loop through the array of items and add the cost of each 
	which is (quantity * price) to totalCost */
	for (int i = 0; i < arrayEnd; i++)
	{
		/* Use -> because each array element is only a pointer to an object.
		items[i]->getPrice() is equiv to *(item).getPrice(), which is the same as 
		"call member function getPrice() on the Item pointed to by items[i]" */
		itemCost = items[i]->getPrice() * items[i]->getQuantity();
		totalPrice += itemCost;
	}

	return totalPrice;
}
