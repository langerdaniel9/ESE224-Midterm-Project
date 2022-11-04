#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Book.h"

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

vector<string> Student::getList() {
	return listOfCopies;						// ???
}

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

void Student::getList(vector<string> loc) {
	listOfCopies = loc;						// ???
}
 

// Search book
void Student::searchBook() {
	// Sorting Library (vector of Books)
	vector<Book> library;							 // can be commented out for actual vector of book (library)
	for (int i = 0; i < library.size() - 1; i++) {					// sorting by title
		for (int j = 0; j < (library.size() - 1 - i); j++) {
//			int titleCompare = library.at(j).title.compare(library.at(j + 1).title);
//			if (titleCompare > 0) {
//				swap(library.at(j), library(j + 1));
//			}
		}
	}
	
	quickSort(library, library.begin(), library.end());
	
	int searchChoice;
	cout << "How do you want to search your book?: (Pick one of the four options:)" << endl;
	cout << "(1) - ISBN" << endl;
	cout << "(2) - title" << endl;
	cout << "(3) - category" << endl;
	cout << "(4) - ID" << endl;
	cin >> searchChoice;

	switch (searchChoice) {
		case 1: 
			string ISBN;
			cout << "What's your ISBN value?: ";
			getline(cin, ISBN);

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
	}

}

void Student::quickSort(vector<Book> lib, int low, int high) {

}

// Borrow book

// Return book

// Renew book

// Log out

// Get() and set() for attributes

// Overload '<<' and '>>' ???