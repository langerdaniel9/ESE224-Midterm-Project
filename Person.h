#pragma once

#include <string>
#include <vector>

#include "Book.h"

using namespace std;

////////////////
/*Person class*/
////////////////
class Person
{

protected:
    // Attributes that both Student and Teacher share
    string userName;
    string password;
    int maxCopies;
    int maxLoanTime;
    vector<Book> copiesBorrowed;

public:
    // Getters //
    string getUserName();
    string getPassword();
    int getMaxCopies();
    int getMaxLoanTime();
    vector<Book> getBooksBorrowed();
    // Setters //
    void setUserName(string);
    void setPassword(string);
    // Operator Overloading //
    friend ostream &operator<<(ostream &output, Book &book);
    friend istream &operator>>(istream &input, Book &book);
    // Main functions //
    void searchBook(vector<Book> &bookCatalog);
    void borrowBook(vector<Book> &bookCatalog, time_t &zeroTime);
    void returnBook(vector<Book> &bookCatalog);
    void renewBook(vector<Book> &bookCatalog);
};

/////////////////
/*Student class*/
/////////////////
class Student : public Person
{
private:
public:
    Student(string initUserName, string initPassword);
};

/////////////////
/*Teacher class*/
/////////////////
class Teacher : public Person
{
private:
public:
    Teacher(string initUserName, string initPassword);
    void requestBook(vector<Book> &bookCatalog, int &idCount);
    void deleteBook(vector<Book> &bookCatalog);
};
