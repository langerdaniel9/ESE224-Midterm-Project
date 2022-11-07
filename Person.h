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
    string type;
    string userName;
    string password;
    int maxCopies;
    int maxLoanTime;
    vector<Book> copiesBorrowed;

public:
    Person();
    void searchBook();
    void quickSort(vector<Book> lib, int low, int high);
    int partition(vector<Book> lib, int low, int high);
};

/////////////////
/*Student class*/
/////////////////
class Student : public Person
{
private:
    // max copies, max time
    maxCopies = 5;
    maxLoanTime = 30;
public:
    Student();                      // Constructors
    Student(string type, string u, string p, int c, int t, vector<Book> loc);
};

/////////////////
/*Teacher class*/
/////////////////
class Teacher : public Person
{
private:
    // max copies, max time
    maxCopies = 10;
    maxLoanTime = 50;
public:
    Teacher();
    Teacher(string type, string u, string p, int c, int t, vector<Book> loc);
};