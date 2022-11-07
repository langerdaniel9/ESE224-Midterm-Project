#include <iostream>
#include "Person.h"
#include "Book.h"

using namespace std;

////////////////////
/*For Person class*/
////////////////////

// .type() function that returns a string either "Student" or "Teacher"

// Search book
void Person::searchBook() {
	// Sorting Library (vector of Books)
	vector<Book> library;							 // can be commented out for actual vector of book (library)
	for (int i = 0; i < library.size() - 1; i++) {					// sorting by title
		for (int j = 0; j < (library.size() - 1 - i); j++) {
			int titleCompare = library.at(j).title.compare(library.at(j + 1).title);
			if (titleCompare > 0) {
				swap(library.at(j), library(j + 1));
			}
		}
	}

	quickSort(library, library.begin(), library.end());			// sorting by ID??

	int searchChoice;
	cout << "How do you want to search your book?: (Pick one of the four options:)" << endl;
	cout << "(1) - ISBN" << endl;
	cout << "(2) - title" << endl;
	cout << "(3) - category" << endl;
	cout << "(4) - ID" << endl;
	cin >> searchChoice;

	switch (searchChoice) {
	case 1:
		string inputISBN;
		cout << "What's your book's ISBN value?: ";
		getline(cin, inputISBN);
		for (int i = 0; i < library.size(); i++) {
			if (library.at(i).getIsbn() == inputISBN) {
				printBook(library.at(i));					// printing book function (i think from Book class)
			}
		}

		break;
	case 2:
		string inputTitle;
		cout << "What's your book's title?: ";
		getline(cin, inputTitle);
		for (int i = 0; i < library.size(); i++) {
			if (library.at(i).getTitle() == inputTitle) {
				printBook(library.at(i));					// printing book function (i think from Book class)
			}
		}

		break;
	case 3:
		string inputCategory;
		cout << "What's your book's category?: ";
		getline(cin, inputCategory);
		for (int i = 0; i < library.size(); i++) {
			if (library.at(i).getCategory() == inputCategory) {
				printBook(library.at(i));					// printing book function (i think from Book class)
			}
		}

		break;
	case 4:
		int inputID;
		cout << "What's your book's ID?: ";
		cin >> inputID;
		for (int i = 0; i < library.size(); i++) {
			if (library.at(i).getId() == inputID) {
				printBook(library.at(i));					// printing book function (i think from Book class)
			}
		}

		break;
	default:
		cout << "That's not a valid option! Try again!" << endl;
		break;

	}
}

void Person::quickSort(vector<Book> lib, int low, int high) {
	if (low < high) {
		int pi = partition(lib, low, high);

		// recursive call on the left of pivot
		quickSort(lib, low, pi - 1);

		// recursive call on the right of pivot
		quickSort(lib, pi + 1, high);
	}
}

int Person::partition(vector<Book> lib, int low, int high) {
	// partition starting from first element; 
	// then comparing each element by the last element in the array

	int i = low - 1;                        // i => index of first array (array lower than "high" value)

	Book temp;
	for (int j = low; j < high; j++) {      // j => index of second array (array greater than "high" value)
		if (lib.at(j).ID <= lib.at(high).getId()) {
			i++;

			temp = lib.at(j);
			lib.at(j) = lib.at(i);
			lib.at(i) = temp;
		}
	}

	// Swapping the "high" value to where it needs to be 
	temp = lib.at(high);
	lib.at(high) = lib.at(i + 1);
	lib.at(i + 1) = temp;

	// returns the index of where the "high" value is
	return i + 1;
}

// Borrow book

// Return book

// Renew book

// Get() and set() for attributes
	// Getters
string Person::getUser() {
	return userName;
}

string Person::getPass() {
	return password;
}

int Person::getCopies() {
	return maxCopies;
}

int Person::getTime() {
	return maxLoanTime;
}

vector<Book> Person::getList() {
	return copiesBorrowed;						// ???
}

// Setters
void Person::setUser(string u) {
	userName = u;
}

void Person::getPass(string p) {
	password = p;
}

void Person::getCopies(int c) {
	maxCopies = c;
}

void Person::getTime(int t) {
	maxLoanTime = t;
}

void Person::getList(vector<Book> loc) {
	copiesBorrowed = loc;						// ???
}

// Overload '<<' and '>>' ???

/////////////////////
/*For Student Class*/
/////////////////////

// Does student class have exclusive functions? I dont think anything actually goes here

/////////////////////
/*For Teacher Class*/
/////////////////////

// Request new book copy

// Delete existing copy