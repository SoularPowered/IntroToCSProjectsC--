/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 8, 2015
** Description: Book.cpp
** A book class which can be used with Patron and Library classes
** Implementation file.
*********************************************************************/
#include "Patron.hpp"


/*********************************************************************
** Creates a Patron with a unique idNum and a name. Sets fineAmount
** to 0 as a new Patron should have no fine.
*********************************************************************/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0;
}

/*********************************************************************
** Returns the unique patron idNum assigned to a Patron
*********************************************************************/
std::string Patron::getIdNum()
{
	return idNum;
}

/*********************************************************************
** Returns the patron's name. Not necessarily unique.
*********************************************************************/
std::string Patron::getName()
{
	return name;
}

/*********************************************************************
** Returns a vector containing all of the books currently checked out
** by the Patron object
*********************************************************************/
std::vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}

/*********************************************************************
** Adds a book to a Patron object's vector of checkedOutBooks
*********************************************************************/
void Patron::addBook(Book* book)
{
	checkedOutBooks.push_back(book);
}

/*********************************************************************
** Removes a specified book from the vector of checkedOutBooks
*********************************************************************/
void Patron::removeBook(Book* book)
{
	// Scan the list of checkedOut books and erase the element if found
	for (int i = 0; i < checkedOutBooks.size(); i++)
	{
		if (checkedOutBooks.at(i) == book)
		{
			checkedOutBooks.erase(checkedOutBooks.begin() + i);
		}
	}
}

/*********************************************************************
** Returns the current fineAmount value
*********************************************************************/
double Patron::getFineAmount()
{
	return fineAmount;
}

/*********************************************************************
** Increments or decrements the fineAmount by the amount passed
** Note that adding a negative will decrease the amount so this should
** be handled fine by a single statement.
*********************************************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}