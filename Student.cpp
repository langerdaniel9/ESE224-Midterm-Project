lsmdlkclksdmc#include <iostream>
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

// Getters
string Student::getUser() {
	return username;
}

string Student::getPass() {
	return password;
}

int Student::getCopies() {
	return copies;
}

int Student::getTime() {
	return borrowTime;
}

//string[] Student::getList() {
//	return listOfCopies;						// ???
//}

// Setters
void Student::setUser(string u) {
	username = u;
}

void Student::getPass(string p) {
	password = p;
}

void Student::getCopies(int c) {
	copies = c;
}

void Student::getTime(int t) {
	borrowTime = t;
}

//void Student::getList(string[] loc) {
//	listOfCopies = loc;						// ???
//}
 

// Search book


// Borrow book

// Return book

// Renew book

// Log out

// Get() and set() for attributes

// Overload '<<' and '>>' ???