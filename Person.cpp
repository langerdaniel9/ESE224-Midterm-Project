#include <iostream>
#include "Person.h"
#include "Book.h"

using namespace std;

////////////////////
/*For Person class*/
////////////////////

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
void Person::searchBook(vector<Book> bookCatalog)
{
	int searchChoice;
	cout << "What category do you want to search by:" << endl;
	cout << "(1) - ISBN" << endl;
	cout << "(2) - Title" << endl;
	cout << "(3) - Category" << endl;
	cout << "(4) - ID" << endl;
	cin >> searchChoice;

	vector<Book> searchMatches;

	switch (searchChoice)
	{
	case 1:
	{
		string inputISBN;
		cout << "What's your book's ISBN value?: ";
		cin >> inputISBN;
		// FIXME - Uses exact match for isbn, needs to be partial match (try using find)
		for (int i = 0; i < bookCatalog.size(); i++)
		{
			if (bookCatalog.at(i).getIsbn() == inputISBN)
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
		// FIXME - Uses exact match for isbn, needs to be partial match (try using find)
		for (int i = 0; i < bookCatalog.size(); i++)
		{
			if (bookCatalog.at(i).getTitle() == inputTitle)
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
		// FIXME - Uses exact match for isbn, needs to be partial match (try using find)
		for (int i = 0; i < bookCatalog.size(); i++)
		{
			if (bookCatalog.at(i).getCategory() == inputCategory)
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
		// FIXME - Uses exact match for isbn, needs to be partial match (try using find)
		for (int i = 0; i < bookCatalog.size(); i++)
		{
			if (bookCatalog.at(i).getId() == inputID)
			{
				// Books with matching criteria get pushed to search results vector
				searchMatches.push_back(bookCatalog.at(i));
			}
		}
		break;
	}
	default:
	{
		cout << "That's not a valid option! Try again!" << endl;
		break;
	}
	}

	// TODO - Sort searchMatches

	// Print searchMatches
	if (searchMatches.size() > 0)
	{
		cout << "Books that match your search critera:" << endl;
		for (Book searchResult : searchMatches)
		{
			cout << searchResult;
		}
	}
	else
	{
		cout << "There were no books that match that search critera, try again with a different search." << endl;
	}
}

// Borrow book
void Person::borrowBook(vector<Book> bookCatalog, int zeroTime)
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
	this->copiesBorrowed.push_back(toBeBorrowed);

	for (int i = 0; i < bookCatalog.size(); i++)
	{
		if (bookCatalog.at(i).getId() == toBeBorrowed.getId())
		{
			int currentTime = date(zeroTime); // TODO - check if this works
			bookCatalog.at(i).setStartDate(currentTime);
			bookCatalog.at(i).setExpDate(currentTime + this->getMaxLoanTime());
			bookCatalog.at(i).setReaderName(this->getUserName());
		}
	}
}

// Return book
void Person::returnBook(vector<Book> bookCatalog)
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
	for (int i = 0; i < this->getBooksBorrowed().size(); i++)
	{
		if (this->getBooksBorrowed().at(i).getId() == id)
		{
			this->getBooksBorrowed().erase(this->getBooksBorrowed().begin() + i);
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
}

// Renew book
void Person::renewBook()
{
	cout << "Here are all the books you are currently borrowing:" << endl;

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
		   << "Max loan time:\t" << person.getMaxLoanTime() << " days" << endl;

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

string Student::getType()
{
	return "Student";
}

/////////////////////
/*For Teacher Class*/
/////////////////////

string Teacher::getType()
{
	return "Teacher";
}

// Request new book copy
void Teacher::requestBook(vector<Book> bookCatalog, int &idCount)
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
	cout << "Your requested book has been added to the library." << endl;
}

// Delete existing copy
void Teacher::deleteBook(vector<Book> bookCatalog)
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
}