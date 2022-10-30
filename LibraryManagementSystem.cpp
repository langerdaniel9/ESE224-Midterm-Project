#include "Book.h"
#include "Person.h"

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

void getUsers(vector<Person> usersList);
void getBooks(vector<Book> bookCatalog);
Person login(vector<Person> usersList);
int date(time_t zeroTime);
void studentLoop(Person user, vector<Book> bookCatalog, time_t zeroTime);
void teacherLoop(Person user, vector<Book> bookCatalog, time_t zeroTime);

int main()
{
    // Data to be read in from text files
    vector<Book> bookCatalog;
    vector<Person> usersList;

    // Read in data from student.txt and book.txt
    getUsers(usersList);
    getBooks(bookCatalog);

    // Login system, can log in and log out on the same run
    Person currentUser;
    while (true)
    {
        currentUser = login(usersList);
        time_t zeroTime = time(NULL);

        if (currentUser.type() == "Student") // This may need to be changed whenever .type() is implemented
        {
            studentLoop(currentUser, bookCatalog, zeroTime);
        }
        else if (currentUser.type() == "Teacher") // This may need to be changed whenever .type() is implemented
        {
            teacherLoop(currentUser, bookCatalog, zeroTime);
        }
        else
        {
            cerr << "userType is invalid" << endl;
            exit(5);
        }
    }
}

void getUsers(vector<Person> usersList)
{
    // Do file I/O, filename is usersList.txt

    /* Take in data line by line
    The format will be
    Role(0=student, 1=teacher)  user_name   password
    */

    // If current line is a student, create new student with those attributes and push to the vector

    // Else if it is a teacher, create new teacher with those attributes and push to the vector

    // When everything is done, close the file and return

    return;
}

void getBooks(vector<Book> bookCatalog)
{
    // Do file I/O, filename is booksList.txt

    /* Take in data line by line
    The format will be
    ISBN    Title  Author  Category    Num_of_copies
    */

    // For each line push a new Book object to the vector with the correct attributes

    // When everything is done, close the file and return

    return;
}

Person login(vector<Person> usersList)
{
    /* while(true){
    // Prompt for username/ ask if they want to shutdown system

    // If shutdown system, exit
    // exit(0);

    // Else prompt for password

    // Run through usersList and check if such a user exists

    // If exists, return that user

    // If not, print an error and say try again

    }*/
}

int date(time_t zeroTime)
{
    // How many real life seconds it takes for a virtual day to pass
    int dayLength = 5;
    time_t currentTime = time(NULL);
    return (currentTime - zeroTime) / dayLength;
}

void studentLoop(Person user, vector<Book> bookCatalog, time_t zeroTime)
{
    while (true)
    {
        cout << "Welcome back, Student\n"
             << "It has been " << date(zeroTime) << "days\n\n"
             << "Please choose:\n"
             << "1 -- Search Book\n"
             << "2 -- Borrow Book\n"
             << "3 -- Return Book\n"
             << "4 -- Renew Book\n"
             << "0 -- Log Out\n"
             << endl;

        int choice;
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid input" << endl;
            // Reset cin and clear the failbit
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (choice)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            // Search Book
            user.search(bookCatalog);
            break;
        }
        case 2:
        {
            // Borrow Book
            user.borrow(bookCatalog);
            break;
        }
        case 3:
        {
            // Return Book
            user.return (bookCatalog);
            break;
        }
        case 4:
        {
            // Renew Book
            user.renew(bookCatalog);
            break;
        }

        default:
        {
            cout << "Something went wrong, please try again" << endl;
            break;
        }
        }
    }
}

void teacherLoop(Person user, vector<Book> bookCatalog, time_t zeroTime)

{
    while (true)
    {
        cout << "Welcome back, Teacher\n"
             << "It has been " << date(zeroTime) << "days\n\n"
             << "Please choose:\n"
             << "1 -- Search Book\n"
             << "2 -- Borrow Book\n"
             << "3 -- Return Book\n"
             << "4 -- Renew Book\n"
             << "5 -- Request New Book\n"
             << "6 -- Delete Existing Book\n"
             << "0 -- Log Out\n"
             << endl;

        int choice;
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid input" << endl;
            // Reset cin and clear the failbit
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (choice)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            // Search Book
            user.search(bookCatalog);
            break;
        }
        case 2:
        {
            // Borrow Book
            user.borrow(bookCatalog);
            break;
        }
        case 3:
        {
            // Return Book
            user.return (bookCatalog);
            break;
        }
        case 4:
        {
            // Renew Book
            user.renew(bookCatalog);
            break;
        }
        case 5:
        {
            // Request new book
            user.request(bookCatalog);
            break;
        }
        case 6:
        {
            // Delete book from vector
            user.delete(bookCatalog);
            break;
        }

        default:
        {
            cout << "Something went wrong, please try again" << endl;
            break;
        }
        }
    }
}