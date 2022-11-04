#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book() {
	id = 0;
	isbn = "";
	title = "";
	author = "";
	category = "";
	readerName = "";
	startDate = 0;
	expDate = 0;
}

Book::Book(int id, string isbn, string title, string author, string, category) {
	this->id = id;
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->category = category;
	readerName = "";
	startDate = 0;
	expDate = 0;
}

// ******************** ACCESSORS ********************

string Book::getIsbn() {
	return isbn;
}

string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

string Book::getCategory() {
	return category;
}

int Book::getId() {
	return id;
}

string Book::getReaderName() {
	return readerName;
}

int Book::getStartDate() {
	return startDate;
}

int Book::getExpDate() {
	return expDate;
}


// ******************** MUTATORS ********************

void Book::setIsbn(string isbn) {
	this->isbn = isbn;
}

void Book::setTitle(string title) {
	this->title = title;
}

void Book::setAuthor(string author) {
	this->author = author;
}

void Book::setCategory(string category) {
	this->category = category;
}

void Book::setId(int id) {
	this->id = id;
}

void Book::setReaderName(string readerName) {
	this->readerName = readerName;
}

void Book::setStartDate(int startDate) {
	this->startDate = startDate;
}

void Book::setExpDate(int expDate) {
	this->expDate = expDate;
}


// ******************** OPERATION OVERLOADING ********************

ostream& Book::operator <<(ostream& output, const Book& book) {
	string studentname = "NONE";
	if (!book) {
		return output;
	}
	if (book.getReader()) {
		studentname = book.getReader();
	}
	output << "ID:\t" << book.getId() << endl
		<< "ISBN:\t" << book.getIsbn() << endl
		<< "Title:\t" << book.getTitle() << endl
		<< "Author:\t" << book.getAuthor() << endl
		<< "Category:\t" << book.getCategory() << endl
		<< "Reader:\t" << studentname << endl
		<< "Start Date:\t" << book.getStartDate() << endl
		<< "Expires:\t" << book.getExpDate() << endl;
}

istream& operator >>(istream& input, Book& book) {
	int id, startDate, expDate;
	string isbn, title, author, category, readerName;
	input >> id >> isbn >> title >> author >> category 
		>> readerName >> startDate >> expDate;
	book.setId(id);
	book.setIsbn(isbn);
	book.setTitle(title);
	book.setAuthor(author);
	book.setCategory(category);
	book.setReaderName(readerName);
	book.setStartDate(startDate);
	book.setExpDate(expDate);
}