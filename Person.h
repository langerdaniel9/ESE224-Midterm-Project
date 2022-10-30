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
};

/////////////////
/*Student class*/
/////////////////
class Student : public Person
{
private:
    // max copies, max time
public:
    Student();
};

/////////////////
/*Teacher class*/
/////////////////
class Teacher : public Person
{
private:
    // max copies, max time
public:
    Teacher();
};