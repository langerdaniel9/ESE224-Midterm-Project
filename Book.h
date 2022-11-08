#pragma once

#include <string>

class Book
{
private:
    // isbn, title, author, category, id, readers name, start date, return date,
    string isbn;
    string title;
    string author;
    string category;
    int id;
    string readerName;
    int startDate;
    int expDate;

public:
    Book();
    Book(int id, string isbn, string title, string author, string category);

    // ********** ACCESSORS **********
    string getIsbn();
    string getTitle();
    string getAuthor();
    string getCategory();
    int getId();
    string getReaderName();
    int getStartDate();
    int getExpDate();

    // ********** MUTATORS **********
    void setIsbn(string isbn);
    void setTitle(string title);
    void setAuthor(string author);
    void setCategory(string category);
    void setId(int id);
    void setReaderName(string readerName);
    void setStartDate(int startDate);
    void setExpDate(int expDate);

    // ********** OPERATION OVERLOADING **********
    friend ostream &operator<<(ostream &output, Book &book);
    friend istream &operator>>(istream &input, Book &book);
};