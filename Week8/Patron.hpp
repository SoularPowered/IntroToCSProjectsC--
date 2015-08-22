/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 8, 2015
** Description: Patron.hpp
** A book class which can be used with Patron and Library classes
** This header file was provided by the instructor - implementation
** was authored by Shawn Hillyer in separate .cpp file.
*********************************************************************/

#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>
#include "Book.hpp"

//class LibraryItem;

class Patron
{
private:
    std::string idNum;
    std::string name;
    std::vector<Book*> checkedOutBooks;
    double fineAmount;
public:
    Patron(std::string idn, std::string n);
    std::string getIdNum();
    std::string getName();
    std::vector<Book*> getCheckedOutBooks();
    void addBook(Book* b);
    void removeBook(Book* b);
    double getFineAmount();
    void amendFine(double amount);
};

#endif