//#include <iostream>
//#include <string>
#include "Library.hpp"

//void printBook(Book &);
//void printPatron(Patron &);
//void printVectorOfBooks(std::vector<Book*>, Patron &);

int main()
{
	/*
	// Create a Library
	Library lib;

	// Create some books
	Book b1("001", "Finders Keepers", "Stephen King");
	Book b2("002", "Losers Weepers", "Larry King");
	Book b3("003", "How to Lose a Finder in 10 Days", "Melissa McCarthy");
	Book b4("004", "Harry Potter IV" , "Famouse Arthur");
	Book b5("005", "Mission Unlikely 6" , "Timothy Cruze");
	Book b6("006", "Sixth Sense" , "N Might Chamalon");
	Book b7("007", "Seven going on Seventy" , "William Shakesitup");
	Book b8("008", "Resistance is Futile" , "JL Picard");
	Book b9("009", "Not Another Soup For the Teenage Soul!", "S.S. Hillyer");
	Book b10("010", "This Is The End", "Finito Torres");

	// Create some patrons
	Patron p1("001", "Billy Bob Thorton");
	Patron p2("002", "Angelina Jolie");
	Patron p3("003", "Jack Black");
	Patron p4("004", "Tony Stark");
	Patron p5("005", "Bruce Banner");
	Patron p6("006", "Bruce Wayne");
	Patron p7("007", "Chris Hemsworth");
	Patron p8("008", "Benjamin Button");
	Patron p9("009", "Howard Stern");
	Patron p10("010", "Alice N. Wunderlinde");

	// Now populate the library with the patrons and books
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addBook(&b4);
	lib.addBook(&b5);
	lib.addBook(&b6);
	lib.addBook(&b7);
	lib.addBook(&b8);
	lib.addBook(&b9);
	lib.addBook(&b10);

	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.addPatron(&p3);
	lib.addPatron(&p4);
	lib.addPatron(&p5);
	lib.addPatron(&p6);
	lib.addPatron(&p7);
	lib.addPatron(&p8);
	lib.addPatron(&p9);
	lib.addPatron(&p10);

	std::cout << "Library created, Books created and added, Patrons created and added." << std::endl;

	// Tony Stark is a Jerk and checks out almost all the books
	std::cout << lib.checkOutBook("004", "001") << std::endl;
	std::cout << lib.checkOutBook("004", "002") << std::endl;
	std::cout << lib.checkOutBook("004", "003") << std::endl;
	std::cout << lib.checkOutBook("004", "004") << std::endl;
	std::cout << lib.checkOutBook("004", "005") << std::endl;
	std::cout << lib.checkOutBook("004", "006") << std::endl;
	std::cout << lib.checkOutBook("004", "007") << std::endl;
	std::cout << lib.checkOutBook("004", "008") << std::endl;
	std::cout << lib.checkOutBook("004", "009") << std::endl;
	
	// bruce banner is busy but calls in and reserves the last one
	std::cout << lib.requestBook("005", "010") << std::endl;

	// error checking
	std::cout << "Expect book not found, patron not found, checked out already, on hold: " << std::endl;
	std::cout << lib.checkOutBook("004", "999") << std::endl; // bad book id
	std::cout << lib.checkOutBook("999", "001") << std::endl; // bad patron id
	std::cout << lib.checkOutBook("009", "002") << std::endl; // book checked out already
	std::cout << lib.checkOutBook("002", "010") << std::endl; // on hold

	// Howard Stern (p9) wants book 10 and calls ahead to get it as well
	std::cout << "Expect already on hold" << std::endl;
	std::cout << lib.requestBook("009", "010") << std::endl;


	// Print out Iron Man's list of books he wants to read...
	std::vector<Book*> tonyBooks = p4.getCheckedOutBooks();
	printVectorOfBooks(tonyBooks, p4);

	// Bruce Banner picks up his book, Howard stern then calls and reserves it
	std::cout << "Bruce Banner checks out and stern reserves... should be success. " << std::endl;
	std::cout << lib.checkOutBook("005", "010") << std::endl;
	std::cout << lib.requestBook("009", "010") << std::endl;

	// Tony Start returns a few books
	std::cout << lib.returnBook("004") << std::endl;
	std::cout << lib.returnBook("006") << std::endl;
	std::cout << lib.returnBook("008") << std::endl;
	std::cout << "Returning a non existant book, expect not found: " << std::endl;
	std::cout << lib.returnBook("999") << std::endl;
	std::cout << "Returning a book that's already checked in, expect book already in library: " << std::endl;
	std::cout << lib.returnBook("004") << std::endl;

	// Return the book on hold, 010, from bruce (p5) and then have somebody other than howard stern try and check it out
	std::cout << "Expect return success, then already on hold, then success " << std::endl;
	std::cout << lib.returnBook("010") << std::endl;
	std::cout << lib.checkOutBook("003", "010") << std::endl;
	std::cout << lib.checkOutBook("009", "010") << std::endl;

	// error test the requestBook
	std::cout << "Expect book not found" << std::endl;
	std::cout << lib.requestBook("999", "001") << std::endl;

	// Print out the holdings of all patrons
	std::vector<Book*> catchBooks;
	catchBooks = p1.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p1);
	catchBooks = p2.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p2);
	catchBooks = p3.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p3);
	catchBooks = p4.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p4);	
	catchBooks = p5.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p5);	
	catchBooks = p6.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p6);	
	catchBooks = p7.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p7);	
	catchBooks = p8.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p8);	
	catchBooks = p9.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p9);	
	catchBooks = p10.getCheckedOutBooks();
	printVectorOfBooks(catchBooks, p10);	

	// Increment day 21 times so that currentDay = 21, then make sure patrons have no fines.
	for (int i = 0; i < 21; i++) 
	{
		lib.incrementCurrentDate();
	}
	std::cout << "INCREMENTED 21 TIMES - NO FEES ??" << std::endl;
	std::cout << "p1.getFineAmount(): " << p1.getFineAmount() << std::endl;
	std::cout << "p2.getFineAmount(): " << p2.getFineAmount() << std::endl;
	std::cout << "p3.getFineAmount(): " << p3.getFineAmount() << std::endl;
	std::cout << "p4.getFineAmount(): " << p4.getFineAmount() << std::endl;
	std::cout << "p5.getFineAmount(): " << p5.getFineAmount() << std::endl;
	std::cout << "p6.getFineAmount(): " << p6.getFineAmount() << std::endl;
	std::cout << "p7.getFineAmount(): " << p7.getFineAmount() << std::endl;
	std::cout << "p8.getFineAmount(): " << p8.getFineAmount() << std::endl;
	std::cout << "p9.getFineAmount(): " << p9.getFineAmount() << std::endl;
	std::cout << "p10.getFineAmount(): " << p10.getFineAmount() << std::endl;

	lib.incrementCurrentDate();
	std::cout << "incremented 1 more time... .10 for each book?" << std::endl;
	std::cout << "p1.getFineAmount(): " << p1.getFineAmount() << std::endl;
	std::cout << "p2.getFineAmount(): " << p2.getFineAmount() << std::endl;
	std::cout << "p3.getFineAmount(): " << p3.getFineAmount() << std::endl;
	std::cout << "p4.getFineAmount(): " << p4.getFineAmount() << std::endl;
	std::cout << "p5.getFineAmount(): " << p5.getFineAmount() << std::endl;
	std::cout << "p6.getFineAmount(): " << p6.getFineAmount() << std::endl;
	std::cout << "p7.getFineAmount(): " << p7.getFineAmount() << std::endl;
	std::cout << "p8.getFineAmount(): " << p8.getFineAmount() << std::endl;
	std::cout << "p9.getFineAmount(): " << p9.getFineAmount() << std::endl;
	std::cout << "p10.getFineAmount(): " << p10.getFineAmount() << std::endl;

	lib.incrementCurrentDate();
	std::cout << "incremented 1 more time... .20 for each book?" << std::endl;
	std::cout << "p1.getFineAmount(): " << p1.getFineAmount() << std::endl;
	std::cout << "p2.getFineAmount(): " << p2.getFineAmount() << std::endl;
	std::cout << "p3.getFineAmount(): " << p3.getFineAmount() << std::endl;
	std::cout << "p4.getFineAmount(): " << p4.getFineAmount() << std::endl;
	std::cout << "p5.getFineAmount(): " << p5.getFineAmount() << std::endl;
	std::cout << "p6.getFineAmount(): " << p6.getFineAmount() << std::endl;
	std::cout << "p7.getFineAmount(): " << p7.getFineAmount() << std::endl;
	std::cout << "p8.getFineAmount(): " << p8.getFineAmount() << std::endl;
	std::cout << "p9.getFineAmount(): " << p9.getFineAmount() << std::endl;
	std::cout << "p10.getFineAmount(): " << p10.getFineAmount() << std::endl;

	// Okay now pay some fines
	std::cout << "Expect first to say patron not found..." << std::endl;
	std::cout << lib.payFine("999", 500);
	std::cout << lib.payFine("004", 1.00) << " p4 paid 1.00" << std::endl;
	
	std::cout << "p1.getFineAmount(): " << p1.getFineAmount() << std::endl;
	std::cout << "p2.getFineAmount(): " << p2.getFineAmount() << std::endl;
	std::cout << "p3.getFineAmount(): " << p3.getFineAmount() << std::endl;
	std::cout << "p4.getFineAmount(): " << p4.getFineAmount() << std::endl;
	std::cout << "p5.getFineAmount(): " << p5.getFineAmount() << std::endl;
	std::cout << "p6.getFineAmount(): " << p6.getFineAmount() << std::endl;
	std::cout << "p7.getFineAmount(): " << p7.getFineAmount() << std::endl;
	std::cout << "p8.getFineAmount(): " << p8.getFineAmount() << std::endl;
	std::cout << "p9.getFineAmount(): " << p9.getFineAmount() << std::endl;
	std::cout << "p10.getFineAmount(): " << p10.getFineAmount() << std::endl;
*/
	return 0;
}

/*

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

void printVectorOfBooks(std::vector<Book*> books, Patron &p)
{
	if (books.empty())
	{
		return;
	}
	std::cout << "***************" << std::endl;
	std::cout << "Patron << " << p.getName() << " has the following books checked out: " << std::endl;

	for (int i = 0; i < books.size(); i++)
	{
		std::cout << books.at(i)->getIdCode() << " " << books.at(i)->getTitle() << std::endl;
	}
	std::cout << "***************" << std::endl;
}
*/