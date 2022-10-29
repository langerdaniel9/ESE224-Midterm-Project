#include <iostream>
#include "Teacher.h"

using namespace std;

// Constructors
Teacher::Teacher(string u, string p, int c, int t, string[] loc) {
	username = u;
	password = p;

	if ((c >= 0) && (c <= 5)) {
		copies = c;
	}

	if ((t >= 0) && t <= 30) {
		borrowTime = t;
	}

	listOfCopies = loc;				// ??? (Is this how you do this?)
}

// Search book

// Borrow book

// Return book

// Renew book

// Log out

// Request new book copy

// Delete existing copy

// Get() and set() for attributes

// Overload '<<' and '>>' ???