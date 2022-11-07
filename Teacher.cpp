#include <iostream>
#include "Teacher.h"

using namespace std;

// Constructors
Teacher::Teacher(string u, string p, int c, int t, string[] loc) {
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

// Getters
string Teacher::getUser() {
	return username;
}

string Teacher::getPass() {
	return password;
}

int Teacher::getCopies() {
	return copies;
}

int Teacher::getTime() {
	return borrowTime;
}

vector<string> Teacher::getList() {
	return listOfCopies;						// ???
}

// Setters
void Teacher::setUser(string u) {
	username = u;
}

void Teacher::getPass(string p) {
	password = p;
}

void Teacher::getCopies(int c) {
	copies = c;
}

void Teacher::getTime(int t) {
	borrowTime = t;
}

void Teacher::getList(vector<string> loc) {
	listOfCopies = loc;						// ???
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