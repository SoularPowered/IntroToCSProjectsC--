#include <iostream>
#include <string>
#include "Library.hpp"

void printBook(Book &);
void printPatron(Patron &);
void printVectorOfBooks(std::vector<Book*>);

int main()
{

	/////////////////////////
	// Test the Book class //
	/////////////////////////

	//  Constructor:	Book::Book(std::string idc, std::string t, std::string a)
	Book b1("001", "Finders Keepers", "Stephen King");
	Book b2("002", "Losers Weepers", "Larry King");
	Book b3("003", "How to Lose a Finder in 10 Days", "Melissa McCarthy");
	Book b4("004", "Not Another Soup For the Teenage Soul!", "S.S. Hillyer");

	// Getters are being called in printBook() for each book
/*	printBook(b1);
	printBook(b2);
	printBook(b3);
	printBook(b4);
*/
	// Test a few setters....
/*	b1.setLocation(ON_HOLD_SHELF);
	std::cout << "called b1.setLocation(ON_HOLD_SHELF).";
	if (b1.getLocation() == ON_HOLD_SHELF)
		std::cout << "b1.getLocation() returns true for ON_HOLD_SHELF check! Good." << std::endl;
	b2.setLocation(CHECKED_OUT);
	if (b2.getLocation() == CHECKED_OUT)
		std::cout << "b2.getLocation() returns true for CHECKED_OUT check! Good." << std::endl;
	if (b1.getLocation() == CHECKED_OUT)
		std::cout << "b1.getLocation() returns false for CHECKED_OUT check! Good." << std::endl;
	b2.setLocation(CHECKED_OUT);
	if (b2.getLocation() == ON_HOLD_SHELF)
		std::cout << "b2.getLocation() returns false for ON_HOLD_SHELF check! Good." << std::endl;
*/
	// unable to test getCheckedOutBy directly; same for getRequested by.

	// also, test getCheckedOut and setDateChecked out as part of the other class impelmentations as appropriate

	////////////////////////////
	// Test  the Patron class //
	////////////////////////////

	// Constructor: Patron::Patron(std::string idn, std::string n)
	Patron p1("001", "Billy Bob Thorton");
	Patron p2("002", "Angelina Jolie");
	Patron p3("003", "Jack Black");
	Patron p4("004", "Tony Stark");

	// test Patron getters and print out all values 
/*	printPatron(p1);
	printPatron(p2);
	printPatron(p3);
	printPatron(p4); 
*/
	// add some books to patrons
/*	p1.addBook(&b1);
	p2.addBook(&b1);
	p2.addBook(&b2);
	p3.addBook(&b1);
	p3.addBook(&b2);
	p3.addBook(&b3);
	p4.addBook(&b1);
	p4.addBook(&b2);
	p4.addBook(&b3);
	p4.addBook(&b4);
*/
	// std::vector<Book*> getCheckedOutBooks()
	// get the checkedOutBooks vectors one by one and print the vectors
/*	std::vector<Book*> catchBooks;
	std::cout << "Catching books for p1 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p1.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p2 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p2.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p3 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p3.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p4 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p4.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
*/
	// now remove some books and print the vectors 
/*	p1.removeBook(&b1);
	p2.removeBook(&b2);
	p3.removeBook(&b3);
	p4.removeBook(&b4);
*/
	// get the checkedOutBooks vectors one by one and print the vectors
/*	std::cout << "Catching books for p using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p1.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p2 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p2.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p3 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p3.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p4 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p4.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
*/

	/////////////////////////////
	// Test  the Library class //
	/////////////////////////////

	// Test default (and only) constructor
	std::cout << "Creating a Library..." << std::endl;
	Library lib;

	// Add pointers to books to the Library::holdings vector
	std::cout << "Adding all books to the library holdings..." << std::endl;
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addBook(&b4);

	// Add pointers to patrons to the Library::members vector
	std::cout << "Adding all patrons the the library members..." << std::endl;
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.addPatron(&p3);
	lib.addPatron(&p4);

	// Check getPatron and getBook to see if they accurately return NULL or & of the objects
	Book* pBook = NULL;
	pBook = lib.getBook("001");
	if (pBook)
		std::cout << "Book found: " << pBook->getIdCode() << " (title: " << pBook->getTitle() << ")" << std::endl;
	else
		std::cout << "Book not found, returned NULL." << std::endl;
	
	pBook = lib.getBook("002");
	if (pBook)
		std::cout << "Book found: " << pBook->getIdCode() << " (title: " << pBook->getTitle() << ")" << std::endl;
	else
		std::cout << "Book not found, returned NULL." << std::endl;
	
	pBook = lib.getBook("003");
	if (pBook)
		std::cout << "Book found: " << pBook->getIdCode() << " (title: " << pBook->getTitle() << ")" << std::endl;
	else
		std::cout << "Book not found, returned NULL." << std::endl;
	
	pBook = lib.getBook("004");
	if (pBook)
		std::cout << "Book found: " << pBook->getIdCode() << " (title: " << pBook->getTitle() << ")" << std::endl;
	else
		std::cout << "Book not found, returned NULL." << std::endl;
	
	pBook = lib.getBook("005");
	if (pBook)
		std::cout << "Book found: " << pBook->getIdCode() << " (title: " << pBook->getTitle() << ")" << std::endl;
	else
		std::cout << "Book not found, returned NULL." << std::endl;

	// Check getPatron and getBook to see if they accurately return NULL or & of the objects
	Patron* pPatron = NULL;
	pPatron = lib.getPatron("001");
	if (pPatron)
		std::cout << "Patron found: " << pPatron->getIdNum() << " (name: " << pPatron->getName() << ")" << std::endl;
	else
		std::cout << "Patron not found, returned NULL." << std::endl;

	pPatron = lib.getPatron("002");
	if (pPatron)
		std::cout << "Patron found: " << pPatron->getIdNum() << " (name: " << pPatron->getName() << ")" << std::endl;
	else
		std::cout << "Patron not found, returned NULL." << std::endl;

	pPatron = lib.getPatron("003");
	if (pPatron)
		std::cout << "Patron found: " << pPatron->getIdNum() << " (name: " << pPatron->getName() << ")" << std::endl;
	else
		std::cout << "Patron not found, returned NULL." << std::endl;

	pPatron = lib.getPatron("004");
	if (pPatron)
		std::cout << "Patron found: " << pPatron->getIdNum() << " (name: " << pPatron->getName() << ")" << std::endl;
	else
		std::cout << "Patron not found, returned NULL." << std::endl;

	pPatron = lib.getPatron("005");
	if (pPatron)
		std::cout << "Patron found: " << pPatron->getIdNum() << " (name: " << pPatron->getName() << ")" << std::endl;
	else
		std::cout << "Patron not found, returned NULL." << std::endl;


	// Try checking out a book...
	std::cout << "Checking out book 001 to patron 001... expect success!" << std::endl << lib.checkOutBook("001", "001") << std::endl;
	std::cout << "Checking out book 001 to patron 002... expect already checked out: " << std::endl << lib.checkOutBook("002", "001") << std::endl;
	std::cout << "Checking out book 005 to patron 001... expect book not found: " << std::endl << lib.checkOutBook("001", "005") << std::endl;
	std::cout << "Checking out book 002 to patron 005... expect patron not found: " << std::endl << lib.checkOutBook("005", "002") << std::endl;
	std::cout << "Checking out book 002 to patron 002... expect success!" << std::endl << lib.checkOutBook("002", "002") << std::endl;
	std::cout << "Checking out book 003 to patron 003... expect success!" << std::endl << lib.checkOutBook("003", "003") << std::endl;
	std::cout << "Checking out book 004 to patron 004... expect success!" << std::endl << lib.checkOutBook("004", "004") << std::endl;

	std::vector<Book*> catchBooks;
	std::cout << "Catching books for p1 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p1.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p2 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p2.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p3 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p3.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p4 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p4.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);

	// Return books test
	std::cout << "Returning book 001... expect success: " << lib.returnBook("001") << std::endl;
	std::cout << "Returning book 001... expect book already in library: " << lib.returnBook("001") << std::endl;
	std::cout << "Returning book 999... expect book not found: " << lib.returnBook("999") << std::endl;
	std::cout << "Returning book 002... expect success: " << lib.returnBook("002") << std::endl;
	


	// Make sure books are correct status (books 1 and 2 on shelf, 3 and 4 checked out, etc.)
	printBook(b1);
	printBook(b2);
	printBook(b3);
	printBook(b4);

	// Put the books on hold (1 and 2 should be availble)
	std::cout << "Patron 001 requesting book 001. Expect success... " << lib.requestBook("001", "001") << std::endl;
	std::cout << "Patron 002 requesting book 001. Expect already on hold..." << lib.requestBook("002", "001") << std::endl;
	std::cout << "Patron 001 requesting book 999. Expect book not found..." << lib.requestBook("001", "999") << std::endl;
	std::cout << "Patron 005 requesting book 001. Expect patron not found..." << lib.requestBook("999", "001") << std::endl;
	std::cout << "Patron 001 requesting book 001 AGAIN. Expect success..." << lib.requestBook("001", "001") << std::endl;
	std::cout << "Patron 002 requesting book 004. Expect success..." << lib.requestBook("002", "004") << std::endl;
	std::cout << "Patron 003 requesting book 004. Expect already on hold..." << lib.requestBook("003", "004") << std::endl;

	// TEST checkOutBook if book is on hold
	lib.returnBook("004");
	std::cout << "Patron 001 trying to check out book 004. Expect already on hold... " << lib.checkOutBook("001", "004") << std::endl;
	std::cout << "Patron 002 trying to check out book 004. Expect success... " << lib.checkOutBook("002", "004") << std::endl;

	// Test fine payment using patron 4 (this will be an overpayment scenario)
//	std::cout << lib.payFine("004", 5.50) << std::endl;
	std::cout << "Patron 004 has paid $5.50. Current fine amount: " << p4.getFineAmount() << std::endl;
	std::cout << "Patron 999 doesn't exist... trying to pay fine... " << lib.payFine("999", 100.00) << std::endl;


	// Increment day 21 times so that currentDay = 21, then make sure patrons have no fines.
	for (int i = 0; i < 21; i++) 
	{
		lib.incrementCurrentDate();
	}
	
	std::cout << "Catching books for p1 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p1.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p2 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p2.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p3 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p3.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);
	
	std::cout << "Catching books for p4 using .getCheckedOutBooks(). Then printing values: " << std::endl;
	catchBooks = p4.getCheckedOutBooks();
	printVectorOfBooks(catchBooks);

	std::cout << "INCREMENTED 21 TIMES - NO FEES ??" << std::endl;
	std::cout << "p1.getFineAmount(): " << p1.getFineAmount() << std::endl;
	std::cout << "p2.getFineAmount(): " << p2.getFineAmount() << std::endl;
	std::cout << "p3.getFineAmount(): " << p3.getFineAmount() << std::endl;
	std::cout << "p4.getFineAmount(): " << p4.getFineAmount() << std::endl;

	lib.incrementCurrentDate();
	std::cout << "incremented 1 more time... .10 for each book?" << std::endl;
	std::cout << "p1.getFineAmount(): " << p1.getFineAmount() << std::endl;
	std::cout << "p2.getFineAmount(): " << p2.getFineAmount() << std::endl;
	std::cout << "p3.getFineAmount(): " << p3.getFineAmount() << std::endl;
	std::cout << "p4.getFineAmount(): " << p4.getFineAmount() << std::endl;

	lib.incrementCurrentDate();
	std::cout << "incremented 1 more time... .20 for each book?" << std::endl;
	std::cout << "p1.getFineAmount(): " << p1.getFineAmount() << std::endl;
	std::cout << "p2.getFineAmount(): " << p2.getFineAmount() << std::endl;
	std::cout << "p3.getFineAmount(): " << p3.getFineAmount() << std::endl;
	std::cout << "p4.getFineAmount(): " << p4.getFineAmount() << std::endl;


	return 0;
}

void printBook(Book &b)
{
	// 	int Book::getCheckOutLength()
	std::cout << "b.getCheckOutLength() call returns (expect 21): " << b.getCheckOutLength() << std::endl;

	//	std::string Book::getIdCode()
	std::cout << "b.getIdCode() call returns: " << b.getIdCode() << std::endl;

	//	std::string Book::getTitle()
	std::cout << "b.getTitle() call returns: " << b.getTitle() << std::endl;

	//	std::string Book::getAuthor()
	std::cout << "b.getAuthor() call returns: " << b.getAuthor() << std::endl;

	//	Locale Book::getLocation()
	std::cout << "b.getLocation() call returns: " << b.getLocation() << std::endl;

	//	Locale Book::getLocation()
	std::cout << "b.getLocation() call returns: " << b.getLocation() << std::endl;
}

void printPatron(Patron &p)
{
	std::cout << "***************" << std::endl;
	// std::string getIdNum()
	std::cout << "p.getIdNum() call returns: " << p.getIdNum() << std::endl;

    // std::string getName()
    std::cout << "p.getName() call returns: " << p.getName() << std::endl;

     // double getFineAmount()
    std::cout << "getFineAmount() call returns: " << p.getFineAmount() << std::endl;
    std::cout << "***************" << std::endl;
}

void printVectorOfBooks(std::vector<Book*> books)
{
	std::cout << "***************" << std::endl;
	std::cout << "Patron has the following books checked out: " << std::endl;

	for (int i = 0; i < books.size(); i++)
	{
		std::cout << books.at(i)->getIdCode() << " " << books.at(i)->getTitle() << std::endl;
	}
	std::cout << "***************" << std::endl;
}