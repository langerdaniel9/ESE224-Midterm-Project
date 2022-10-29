#include <iostream>
#include "Student.h"

using namespace std;

// Constructors
Student::Student(string u, string p, int c, int t, string[] loc) {
	username = u;
	password = p;

	if ((c >= 0) && (c <= 10)) {
		copies = c;
	}

	if ((t >= 0) && t <= 50) {
		borrowTime = t;
	}

	listOfCopies = loc;				// ??? (Is this how you do this?)
}



// Search book

// Borrow book

// Return book

// Renew book

// Log out

// Get() and set() for attributes

// Overload '<<' and '>>' ???