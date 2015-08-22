/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 8, 2015
** Description: Book.cpp
** A book class which can be used with Patron and Library classes
** Implementation file.
*********************************************************************/
#include "Book.hpp"

/*********************************************************************
** Sets idCode, title, and author for a Book object using arguments
** Since this information does not change, they are set directly
** Initializes checkedOutBy and RequestedBy to null and sets the
** location to ON_SHELF
*********************************************************************/
Book::Book(std::string idc, std::string t, std::string a)
{
	idCode = idc;
	title = t;
	author = a;
	setCheckedOutBy(NULL); 	// New book not yet checked out by a patron
	setRequestedBy(NULL);	// New book not yet requested by a patron
	setLocation(ON_SHELF);	// New book starts on the shelf
}

/*********************************************************************
** Returns the check out length - how long a book can be checked out
** Used in calculation of fees by Library class function
*********************************************************************/
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH; // This static const defined in Book.hpp
}


/*********************************************************************
** Returns the idCode - unique identifier for a book. Two otherwise
** identical books should have a unique idCode
*********************************************************************/
std::string Book::getIdCode()
{
	return idCode; 
}


/*********************************************************************
** Returns the title of the book. Two books can have the same title
** (Library can have more than one literal copy of same book, e.g.)
*********************************************************************/
std::string Book::getTitle()
{
	return title;
}


/*********************************************************************
** Returns the author of the book
*********************************************************************/
std::string Book::getAuthor()
{
	return author;
}


/*********************************************************************
** Returns the location of the book (ON_SHELF, ON_HOLD_SHELF, or
** CHECKED_OUT).
*********************************************************************/
Locale Book::getLocation()
{
	return location;
}


/*********************************************************************
** Updates the location of the book to one of the enum values in .hpp
** Options are: ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT
*********************************************************************/
void Book::setLocation(Locale loc)
{
	location = loc;
}


/*********************************************************************
** Returns a pointer to the patron that has checked out this book
*********************************************************************/
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}


/*********************************************************************
** Updates checkedOutBy to pointer to patron to whom a Book has been 
** checked out. NULL indicates nobody has checked out the book.
*********************************************************************/
void Book::setCheckedOutBy(Patron* person)
{
	checkedOutBy = person;
}


/*********************************************************************
** Returns a pointer to the Patron that has requested this book.
** Only one patron may request a book at a time. A book can go on hold
** even if another patron currently has it checked out.
*********************************************************************/
Patron* Book::getRequestedBy()
{
	return requestedBy;
}


/*********************************************************************
** Updates the pointer to Patron, requestedBy. NULL indicates nobody
** currently requests the book be held.
*********************************************************************/
void Book::setRequestedBy(Patron* person)
{
	requestedBy = person;
}


/*********************************************************************
** Returns the date the book was checked out of the library. This is
** reset when the book is returned.
*********************************************************************/
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}


/*********************************************************************
** This function is called by the Library class when a book is checked
** out. It is passed the currentDate of the calling Library object.
*********************************************************************/
void Book::setDateCheckedOut(int date)
{
	dateCheckedOut = date;
}