/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 8, 2015
** Description: Book.cpp
** A book class which can be used with Patron and Library classes
** Implementation file.
*********************************************************************/
#include "Library.hpp"

/*********************************************************************
** Constructor. Initializes currentDate to 0.
*********************************************************************/
Library::Library()
{
	currentDate = 0;
}


/*********************************************************************
** Adds the book to the holdings vector
*********************************************************************/
void Library::addBook(Book* book)
{
	holdings.push_back(book);
}


/*********************************************************************
** Adds the patron to the members vector
*********************************************************************/
void Library::addPatron(Patron* patron)
{
	members.push_back(patron);
}


/*********************************************************************
** Handles the checking out of a book to a patron
*********************************************************************/
std::string Library::checkOutBook(std::string pID, std::string bID)
{
	// Few strings to hold the error messages that can be returned
	std::string errBookNotFound = "book not found", errPatronNotFound = "patron not found",
				errBookCheckedOut = "book already checked out", errBookOnHold = "book on hold by other patron",
				checkOutSuccess = "check out successful";

	// if the specified Book is not in the Library, return "book not found"
	Book* book = getBook(bID);
	if (book == NULL)
	{
		return errBookNotFound;
	}

	// if the specified Patron is not in the Library, return "patron not found"
	Patron* patron = getPatron(pID);
	if (patron == NULL)
	{
		return errPatronNotFound;
	}

	// if the specified Book is already checked out, return "book already checked out"
	if (book->getLocation() == CHECKED_OUT)
	{
		return errBookCheckedOut;
	}

	// if the specified Book is on hold by another Patron, return "book on hold by other patron"
	if (book->getRequestedBy() != NULL && book->getRequestedBy() != patron)
	{
		return errBookOnHold;
	}
	
	// otherwise update the Book's checkedOutBy, dateCheckedOut and Location; 
	book->setCheckedOutBy(patron);
	book->setDateCheckedOut(currentDate);
	book->setLocation(CHECKED_OUT);

	// if the Book was on hold for this Patron, update requestedBy; 
	if (book->getRequestedBy() == patron)
	{
		book->setRequestedBy(NULL); // ensures another patron can request the book while this patron has it checked out!
	}

	// update the Patron's checkedOutBooks;
	patron->addBook(book);

	// return "check out successful"
	return checkOutSuccess;
}


/*********************************************************************
** Handles the return of a book to the library
*********************************************************************/
std::string Library::returnBook(std::string bID)
{
	std::string errBookNotFound = "book not found", errBookNotCheckedOut = "book already in library",
				returnSuccess = "return successful";

	// if the specified Book is not in the Library, return "book not found"
	Book* book = getBook(bID);
	if (book == NULL)
	{
		return errBookNotFound;
	}

	// if the Book is not checked out, return "book already in library"
	if (book->getLocation() != CHECKED_OUT)
	{
		return errBookNotCheckedOut;
	}
	
	// update the Patron's checkedOutBooks;
	Patron* patron = book->getCheckedOutBy();
	patron->removeBook(book);

	// update the Book's location depending on whether another Patron has requested it; 
	if (book->getRequestedBy() != NULL) // somebody has requested the book
	{
		book->setLocation(ON_HOLD_SHELF); // put it on hold shelf
	}
	else // requestedBy is NULL, means nobody has it on hold, so just put it back on shelf
	{
		book->setLocation(ON_SHELF);
	}

	//update the Book's checkedOutBy; 
	book->setCheckedOutBy(NULL); // once book is returned, its currently checked out by no one

	//return "return successful"
	return returnSuccess;
}


/*********************************************************************
** Handles requests to place books on hold
*********************************************************************/
std::string Library::requestBook(std::string pID, std::string bID)
{
	std::string errBookNotFound = "book not found", errPatronNotFound = "patron not found",
				errBookOnHold = "book on hold by other patron", requestSuccess = "request successful";

	// if the specified Book is not in the Library, return "book not found"
	Book* book = getBook(bID);
	if (book == NULL)
	{
		return errBookNotFound;
	}

	// if the specified Patron is not in the Library, return "patron not found"
	Patron* patron = getPatron(pID);
	if (patron == NULL)
	{
		return errPatronNotFound;
	}

	// if the specified Book is already requested by another Patron, return "book on hold by other patron"
	if (book->getRequestedBy() != NULL && book->getRequestedBy() != patron)
	{
		return errBookOnHold;
	}

	// update the Book's requestedBy 
	book->setRequestedBy(patron);

	// if the Book is on the shelf, update its location to on hold;
	if (book->getLocation() == ON_SHELF)
	{
		book->setLocation(ON_HOLD_SHELF);
	} 

	// return "request successful"
	return requestSuccess;
}


/*********************************************************************
** Handles the payment of fines by patrons. Takes as a parameter the
** amount that is being paid (not the negative of that amount)
*********************************************************************/
std::string Library::payFine(std::string pID, double payment)
{
	std::string errPatronNotFound = "patron not found", paymentSuccess = "payment successful";

	// if the specified Patron is not in the Library, return "patron not found"
	Patron* patron = getPatron(pID);
	if (patron == NULL)
	{
		return errPatronNotFound;
	}

	// use amendFine to update the Patron's fine; return "payment successful"
	patron->amendFine(-payment); // pass the negative value to decrement the fine by payment amount
	return paymentSuccess;
}


/*********************************************************************
** Increments the day and updates the fees for all patrons with 
** overdue books.
** If a book is checked out on day 0, then on day 1, the patron has 
** had it for 1 day.  On day 21, the patron has had it for 21 days, so
** it is still not overdue.  On day 22, the book is overdue and fines 
** will be charged.
** Note: Could refactor this code to iterate through the library's
**   list of holdings, check if each book is checked out- if so, check 
**   if its overdue. Then pull the member in & update fine.
*********************************************************************/
void Library::incrementCurrentDate()
{
	// increment current date
	currentDate++;

	Patron* member = NULL; 				// used to access patrons of the library and get their checkedOutBooks
	Book* book = NULL; 					// used to access individual books in each patrons list
	std::vector<Book*> checkedBooks; 	// "catches" the entire list of checkedOutBooks of each patron

	int daysHeld = 0; 					// used to hold # days a book held and compare to CHECK_OUT_LENGTH for fees

	// increase each Patron's fines by 10 cents for each overdue Book they have checked out (using amendFine)
	for (int i = 0; i < members.size(); i++)
	{
		member = members.at(i); 						// grab the Patron at element i of members vector
		checkedBooks = member->getCheckedOutBooks(); 	// grab vector of members checkedOutBooks

		// iterate over their list of books and increment their fineAmount using amendFine if book is late
		for (int j = 0; j < checkedBooks.size(); j ++)
		{
			book = checkedBooks.at(j); // grab the book
			daysHeld = currentDate - book->getDateCheckedOut();
			if (daysHeld > Book::CHECK_OUT_LENGTH)
			{
				member->amendFine(.10);
			}
		}
	}
}


/*********************************************************************
** Searchers the members and returns pointer to a Patron.
** If the Patron is not a member, returns NULL.
*********************************************************************/
Patron* Library::getPatron(std::string pID)
{
	for (int i = 0; i < members.size(); i++)
	{
		if (members.at(i)->getIdNum() == pID)
		{
			return members.at(i);
		}
	}
	// if not found, return NULL pointer
	return NULL;
}


/*********************************************************************
** Searches the holdings and returns pointer to a book.
** If the book is not found (by ID code) then it returns NULL
*********************************************************************/
Book* Library::getBook(std::string bID)
{
	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings.at(i)->getIdCode() == bID)
		{
			return holdings.at(i);
		}
	}
	// if not found, return NULL pointer
	return NULL;
}