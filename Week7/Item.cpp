/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 1, 2015
** Description: Item.cpp
** Class Item includes standard getters and setters to define an obj
** with a name, a price, and a quantity. No input validation is
** included in the class.
*********************************************************************/
#include "Item.hpp"

/*********************************************************************
** Description: Default constructor
** sets name to "", price to 0.0 and quantity to 0.
*********************************************************************/
Item::Item()
{
	setName("");
	setPrice(0.0);
	setQuantity(0);
}

/*********************************************************************
** Description: Constructor with arguments. Calls appropriate setters.
*********************************************************************/
Item::Item(std::string name, double price, int quantity)
{
	setName(name);
	setPrice(price);
	setQuantity(quantity);
}

/*********************************************************************
** Description: Sets the name of the Item.
*********************************************************************/
void Item::setName(std::string name)
{
	this->name = name;
}

/*********************************************************************
** Description: Sets the price of the Item.
*********************************************************************/
void Item::setPrice(double price)
{
	this->price = price;
}

/*********************************************************************
** Description: Sets the quantity of the Item.
*********************************************************************/
void Item::setQuantity(int quantity)
{
	this->quantity = quantity;
}

/*********************************************************************
** Description: Returns name of the Item.
*********************************************************************/
std::string Item::getName()
{
	return name;
}

/*********************************************************************
** Description: Returns price of the Item.
*********************************************************************/
double Item::getPrice()
{
	return price;
}

/*********************************************************************
** Description: Returns quantity of the Item.
*********************************************************************/
int Item::getQuantity()
{
	return quantity;
}