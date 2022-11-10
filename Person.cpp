#include <iostream>
#include <string>
#include <algorithm>
#include "Person.h"
#include "Book.h"

using namespace std;

////////////////////
/*For Person class*/
////////////////////

int date(time_t &zeroTime)
{
	// How many real life seconds it takes for a virtual day to pass
	int dayLength = 5;
	time_t currentTime = time(NULL);
	return ((currentTime - zeroTime) / dayLength);
}

// Getters and Setters //

// Getters
string Person::getUserName()
{
	return this->userName;
}

string Person::getPassword()
{
	return this->password;
}

int Person::getMaxCopies()
{
	return this->maxCopies;
}

int Person::getMaxLoanTime()
{
	return maxLoanTime;
}

vector<Book> Person::getBooksBorrowed()
{
	return this->copiesBorrowed;
}

// Setters
void Person::setUserName(string newUserName)
{
	this->userName = newUserName;
}

void Person::setPassword(string newPassword)
{
	this->password = newPassword;
}

// Search book

int partition(vector<Book> lib, int low, int high)
{
	// partition starting from first element;
	// then comparing each element by the last element in the array

	int i = low - 1; // i => index of first array (array lower than "high" value)

	Book temp;
	for (int j = low; j < high; j++)
	{ // j => index of second array (array greater than "high" value)
		if (lib.at(j).getId() <= lib.at(high).getId())
		{
			i++;

			swap(lib.at(i), lib.at(j));
		}
	}

	// Swapping the "high" value to where it needs to be
	temp = lib.at(high);
	lib.at(high) = lib.at(i + 1);
	lib.at(i + 1) = temp;

	// returns the index of where the "high" value is
	return i + 1;
}

void quickSort(vector<Book> lib, int low, int high)
{
	if (low < high)
	{
		int pi = partition(lib, low, high);

		// recursive call on the left of pivot
		quickSort(lib, low, pi - 1);

		// recursive call on the right of pivot
		quickSort(lib, pi + 1, high);
	}
}

void Person::searchBook(vector<Book> &bookCatalog)
{
	int searchChoice;
	cout << "What category do you want to search by:" << endl;
	cout << "(1) - ISBN" << endl;
	cout << "(2) - Title" << endl;
	cout << "(3) - Category" << endl;
	cout << "(4) - ID" << endl;
	cin >> searchChoice;

	vector<Book> searchMatches;
	searchMatches.clear();

	switch (searchChoice)
	{
	case 1:
	{
		string inputISBN;
		cout << "What's your book's ISBN value?: ";
		cin >> inputISBN;
		for (int i = 0; i < bookCatalog.size(); i++)
		{
			// At least a partial match on isbn
			if (bookCatalog.at(i).getIsbn().find(inputISBN) != string::npos)
			{
				// Books with matching criteria get pushed to search results vector
				searchMatches.push_back(bookCatalog.at(i));
			}
		}

		break;
	}
	case 2:
	{
		string inputTitle;
		cout << "What's your book's title?: ";
		cin >> inputTitle;
		for (int i = 0; i < bookCatalog.size(); i++)
		{
			// At least a partial match on title
			if (bookCatalog.at(i).getTitle().find(inputTitle) != string::npos)
			{
				// Books with matching criteria get pushed to search results vector
				searchMatches.push_back(bookCatalog.at(i));
			}
		}
		break;
	}
	case 3:
	{
		string inputCategory;
		cout << "What's your book's category?: ";
		cin >> inputCategory;
		for (int i = 0; i < bookCatalog.size(); i++)
		{
			// At least a partial match on category
			if (bookCatalog.at(i).getCategory().find(inputCategory) != string::npos)
			{
				// Books with matching criteria get pushed to search results vector
				searchMatches.push_back(bookCatalog.at(i));
			}
		}
		break;
	}
	case 4:
	{
		int inputID;
		cout << "What's your book's ID?: ";
		cin >> inputID;
		// Binary Search
		int lo = 0, hi = bookCatalog.size() - 1;
		int mid;
		while (hi - lo > 1)
		{
			int mid = (hi + lo) / 2;
			if (bookCatalog[mid].getId() < inputID)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid;
			}
		}
		if (bookCatalog[lo].getId() == inputID)
		{
			searchMatches.push_back(bookCatalog.at(lo));
		}
		else if (bookCatalog[hi].getId() == inputID)
		{
			searchMatches.push_back(bookCatalog.at(hi));
		}

		break;
	}
	default:
	{
		cout << "That's not a valid option! Try again!" << endl;
		break;
	}
	}

	// Separate searchMatches into two separate vectors, one for available books and one for unavailable
	vector<Book> availableMatches;
	vector<Book> unavailableMatches;
	availableMatches.clear();
	unavailableMatches.clear();

	for (int i = 0; i < searchMatches.size(); i++)
	{
		if (searchMatches.at(i).getReaderName() == "")
		{
			// If nobody has checked out this book -> it is available
			availableMatches.push_back(searchMatches.at(i));
		}
		else
		{
			unavailableMatches.push_back(searchMatches.at(i));
		}
	}

	// Sort availableMatches
	// sorting by title
	if (availableMatches.size() >= 2)
	{
		for (int i = 0; i < availableMatches.size() - 1; i++)
		{
			for (int j = 0; j < (availableMatches.size() - i - 1); j++)
			{
				int titleCompare = availableMatches.at(j).getTitle().compare(availableMatches.at(j + 1).getTitle());
				if (titleCompare > 0)
				{
					swap(availableMatches.at(j), availableMatches.at(j + 1));
				}
			}
		}

		// sorting by ID
		quickSort(availableMatches, 0, availableMatches.size() - 1);
	}

	// Sort unavailableMatches
	for (int i = 0; i < unavailableMatches.size(); i++)
	{
		for (int j = 0; j < unavailableMatches.size() - i; j++)
		{
			if (unavailableMatches.at(i).getExpDate() > unavailableMatches.at(j).getExpDate())
			{
				swap(unavailableMatches.at(i), unavailableMatches.at(j));
			}
		}
	}

	// Combine the two back together into one finished, sorted vector
	searchMatches.clear();
	for (int i = 0; i < availableMatches.size(); i++)
	{
		searchMatches.push_back(availableMatches.at(i));
	}
	for (int i = 0; i < unavailableMatches.size(); i++)
	{
		searchMatches.push_back(unavailableMatches.at(i));
	}

	// Print searchMatches
	if (searchMatches.size() > 0)
	{
		cout << endl
			 << "Books that match your search critera:" << endl
			 << endl;
		for (Book searchResult : searchMatches)
		{
			cout << searchResult;
		}
	}
	else
	{
		cout << endl
			 << "There were no books that match that search critera, try again with a different search." << endl
			 << endl;
	}
}

// Borrow book
void Person::borrowBook(vector<Book> &bookCatalog, time_t &zeroTime)
{
	// Check if there are overdue books
	int currentTime = date(zeroTime);
	vector<Book> expiredBooks;
	bool expired = false;
	for (int i = 0; i < this->getBooksBorrowed().size(); i++)
	{
		if (this->getBooksBorrowed().at(i).getExpDate() < currentTime)
		{
			expired = true;
			expiredBooks.push_back(this->getBooksBorrowed().at(i));
		}
	}
	if (expired)
	{
		cout << "You have books that are already past due, return those before borrowing more. Your expired books are:" << endl;
		for (Book book : expiredBooks)
		{
			cout << book;
		}
	}

	int inputID;
	cout << "What is the ID of the book you wish to borrow: ";
	cin >> inputID;

	// Check if that ID exists in bookCatalog and that there are available copies
	bool exists = false;
	bool available = false;
	Book toBeBorrowed;

	for (int i = 0; i < bookCatalog.size(); i++)
	{
		if (bookCatalog.at(i).getId() == inputID)
		{
			exists = true;
			// If book exists in bookCatalog, check if it is already being borrowed by someone else
			if (bookCatalog.at(i).getReaderName() == "")
			{
				available = true;
				toBeBorrowed = bookCatalog.at(i);
			}
		}
	}
	if (!exists)
	{
		cout << "That ID does not exist in the library, double check the ID and try again" << endl;
		return;
	}
	if (!available)
	{
		cout << "There are no more copies of this book left, try again after some time has passed" << endl;
		return;
	}

	// Next check if the user is over their maxCopies limit
	if (this->getBooksBorrowed().size() > this->getMaxCopies())
	{
		cout << "You cannot borrow any more books, since you are already at your limit" << endl;
		return;
	}

	// If all of the conditions are met, add the book to copiesBorrowed and change the attributes of the book
	toBeBorrowed.setStartDate(currentTime);
	toBeBorrowed.setExpDate(currentTime + this->getMaxLoanTime());
	toBeBorrowed.setReaderName(this->getUserName());
	this->copiesBorrowed.push_back(toBeBorrowed);

	for (int i = 0; i < bookCatalog.size(); i++)
	{
		if (bookCatalog.at(i).getId() == toBeBorrowed.getId())
		{
			int currentTime = date(zeroTime);
			bookCatalog.at(i).setStartDate(currentTime);
			bookCatalog.at(i).setExpDate(currentTime + this->getMaxLoanTime());
			bookCatalog.at(i).setReaderName(this->getUserName());
		}
	}
}

// Return book
void Person::returnBook(vector<Book> &bookCatalog)
{
	cout << "Here are all the books you are currently borrowing:" << endl;

	for (Book book : this->getBooksBorrowed())
	{
		cout << book;
	}

	cout << "What is the ID of the book you would like to return?" << endl;
	int id;
	cin >> id;

	// Remove book from users 'borrowed books' list
	for (int i = 0; i < this->copiesBorrowed.size(); i++)
	{
		if (this->copiesBorrowed.at(i).getId() == id)
		{
			this->copiesBorrowed.erase(this->copiesBorrowed.begin() + i);
		}
	}

	// Change the properties of the returned book to reflect that it is available
	for (int i = 0; i < bookCatalog.size(); i++)
	{
		if (bookCatalog.at(i).getId() == id)
		{
			bookCatalog.at(i).setStartDate(-1);
			bookCatalog.at(i).setExpDate(-1);
			bookCatalog.at(i).setReaderName("");
		}
	}
	cout << endl;
}

// Renew book
void Person::renewBook()
{
	if (this->getBooksBorrowed().size() == 0)
	{
		cout << "You are not currently borrowing any books." << endl
			 << endl;
		return;
	}

	cout << "Here are all the books you are currently borrowing:" << endl
		 << endl;

	for (Book book : this->getBooksBorrowed())
	{
		cout << book;
	}

	cout << "What is the ID of the book you would like to renew?" << endl;
	int id;
	cin >> id;

	for (int i = 0; i < this->getBooksBorrowed().size(); i++)
	{
		if (this->getBooksBorrowed().at(i).getId() == id)
		{
			this->getBooksBorrowed().at(i).setExpDate(this->getBooksBorrowed().at(i).getExpDate() + this->getMaxLoanTime());
		}
	}
}

// Operator Overloading //
ostream &operator<<(ostream &output, Person &person)
{
	string password;
	for (int i = 0; i < person.getPassword().length(); i++)
	{
		password.append("*");
	}
	output << "Username:\t" << person.getUserName() << endl
		   << "Password:\t" << password << endl
		   << "Borrowing limit:\t" << person.getMaxCopies() << " books" << endl
		   << "Max loan time:\t" << person.getMaxLoanTime() << " days" << endl
		   << endl;

	return output;
}

istream &operator>>(istream &input, Person &person)
{
	string userName, password;
	input >> userName >> password;
	person.setUserName(userName);
	person.setPassword(password);

	return input;
}

/////////////////////
/*For Student Class*/
/////////////////////

Student::Student(string initUserName, string initPassword)
{
	this->userName = initUserName;
	this->password = initPassword;
	this->maxCopies = 5;
	this->maxLoanTime = 30;
}

/////////////////////
/*For Teacher Class*/
/////////////////////

Teacher::Teacher(string initUserName, string initPassword)
{
	this->userName = initUserName;
	this->password = initPassword;
	this->maxCopies = 10;
	this->maxLoanTime = 50;
}

// Request new book copy
void Teacher::requestBook(vector<Book> &bookCatalog, int &idCount)
{
	// Get isbn, title, author, and category of new book
	string isbn;
	string title;
	string author;
	string catagory;
	cout << "What is the ISBN of the new book (no spaces): ";
	cin >> isbn;
	cout << "What is the title of the new book(no spaces): ";
	cin >> title;
	cout << "What is the author of the new book (no spaces): ";
	cin >> author;
	cout << "What is the category of the new book (no spaces): ";
	cin >> catagory;

	Book temp(idCount, isbn, title, author, catagory);
	idCount++;
	bookCatalog.push_back(temp);
	cout << "Your requested book has been added to the library." << endl
		 << endl;
}

// Delete existing copy
void Teacher::deleteBook(vector<Book> &bookCatalog)
{
	int inputID;
	cout << "What is the ID of the book you wish to delete: ";
	cin >> inputID;

	// Check if that ID exists in bookCatalog and that there are available copies
	bool exists = false;
	bool available = false;
	Book toBeDeleted;

	for (int i = 0; i < bookCatalog.size(); i++)
	{
		if (bookCatalog.at(i).getId() == inputID)
		{
			exists = true;
			// If book exists in bookCatalog, check if it is already being borrowed by someone else
			if (bookCatalog.at(i).getReaderName() == "")
			{
				available = true;
				toBeDeleted = bookCatalog.at(i);
			}
		}
	}
	if (!exists)
	{
		cout << "That ID does not exist in the library, double check the ID and try again" << endl;
		return;
	}
	if (!available)
	{
		cout << "That book is currently being borrowed by somebody, please wait until it is returned to delete it." << endl;
		return;
	}

	// If all of the conditions are met, delete the book from bookCatalog

	for (int i = 0; i < bookCatalog.size(); i++)
	{
		if (bookCatalog.at(i).getId() == toBeDeleted.getId())
		{
			bookCatalog.erase(bookCatalog.begin() + i);
			break;
		}
	}

	cout << "Book has been deleted" << endl
		 << endl;
}