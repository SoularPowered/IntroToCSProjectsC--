/*********************************************************************
** Author: Shawn S Hillyer
** Date: August 8, 2015
** Description: Library.hpp
** A book class which can be used with Patron and Library classes
** This header file was provided by the instructor - implementation
** was authored by Shawn.
*********************************************************************/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>
#include "Patron.hpp"

class Library
{
private:
    std::vector<Book*> holdings;
    std::vector<Patron*> members;
    int currentDate;
public:
    Library();
    void addBook(Book*);
    void addPatron(Patron*);
    std::string checkOutBook(std::string pID, std::string bID);
    std::string returnBook(std::string bID);
    std::string requestBook(std::string pID, std::string bID);
    std::string payFine(std::string pID, double payment);
    void incrementCurrentDate();
    Patron* getPatron(std::string pID);
    Book* getBook(std::string bID);
};

#endif