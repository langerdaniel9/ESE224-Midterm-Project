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
private:
    // Only used locally within Person.h
    // void quickSort(vector<Book> lib, int low, int high);
    // int partition(vector<Book> lib, int low, int high);

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
    // Will never need to change max copies allowed
    // Will never need to change max loan time
    // Will not use setter function to change copies borrowed
    // Operator Overloading //
    friend ostream &operator<<(ostream &output, Book &book);
    friend istream &operator>>(istream &input, Book &book);
    // Main functions //
    string getType(); // Overloaded in both student and teacher
    void searchBook(vector<Book> bookCatalog);
    void borrowBook(vector<Book> bookCatalog, int zeroTime);
    void returnBook(vector<Book> bookCatalog);
    void renewBook();
};

/////////////////
/*Student class*/
/////////////////
class Student : public Person
{
private:
    // max copies, max time
    int maxCopies = 5;
    int maxLoanTime = 30;

public:
    Student(string initUserName, string initPassword);
    string getType();
};

/////////////////
/*Teacher class*/
/////////////////
class Teacher : public Person
{
private:
    // max copies, max time
    int maxCopies = 10;
    int maxLoanTime = 50;

public:
    Teacher(string initUserName, string initPassword);
    string getType();
    void requestBook(vector<Book> bookCatalog, int &idCount);
    void deleteBook(vector<Book> bookCatalog);
};