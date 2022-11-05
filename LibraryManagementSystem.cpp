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
    //Written by Ethan Garcia, some comments by Daniel
    // Do file I/O, filename is usersList.txt
    ifstream fin("userList.txt");
    if (fin.fail()) {
        cerr << "error opening userList" << endl;
        exit(1);
    }
    /* 
    * Ethan's edit, It will be done variable by variable since each Person has 3 fields that need to be read.
    * 
    * 
    The format will be
    Role(0=student, 1=teacher)  user_name   password
    */
    // If current line is a student, create new student with those attributes and push to the vector
    // Else if it is a teacher, create new teacher with those attributes and push to the vector
    int rolein;
    string userin;
    string passwordin
    while (!fin.eof) {
        fin >> rolein;
        fin >> userin;
        fin >> passwordin;
        //obtained information for one user, start creating Person
        //for student
        if (rolin == 0) {
            Student temp; 
            //assign values and attributes to temp student
            temp.settype(0); //this may not be neccessary for creation of student
            temp.setuserName(userin);
            temp.setpassword(passwordin);
            //Does there need to be methods to initialize the maxCopies,maxLoanTime, and copiesBorrowed?
            usersList.push_back(temp); //push to vector
        }
        if (rolin == 1) {
            Teacher temp;
            //assign values and attributes to temp teacher
            temp.settype(1); //this may not be neccessary for creation of teacher
            temp.setuserName(userin);
            temp.setpassword(passwordin);
            //Does there need to be methods to initialize the maxCopies,maxLoanTime, and copiesBorrowed?
            userList.pushback(temp); //push to vector
        }
    }
    fin.close();
    // When everything is done, close the file and return
    return;
}

void getBooks(vector<Book> bookCatalog)
{
    //Written by Ethan Garcia, with comments by Daniel
    // Do file I/O, filename is booksList.txt
    ifstream fin("booksList.txt");
    if (fin.fail()) {
        cerr << "error opening booksList" << endl;
        exit(1);
    }
    /* 
    *  Ethan's edit, file input will be done variable by variable,since there is always a constant
    *  amount of fields that needs be read.
    * 
    * 
    * 
    * 
    The format will be
    ISBN    Title  Author  Category    Num_of_copies
    */
    int idcount = 0;
    string isbnin;
    string titlein;
    string authorin;
    string catagoryin;
    string copyin;
    while (!fin.eof()) {
        // For each line push a new Book object to the vector with the correct attributes
        fin >> isbnin;
        fin >> titlein;
        fin >> authorin;
        fin >> catagoryin;
        fin >> copyin;
        for (int i = 0; i < copyin; i++) {
            Book temp(idcount, isbnin, titlein, autorin, catagoryin);
            idcount++;
            bookCatalog.push_back(temp);
        }
    }
    fin.close();
    // When everything is done, close the file and return
    return;
}

Person login(vector<Person> usersList)
//written by Ethan Garcia, with some comments by Daniel
{
    while (true) {
        // Prompt for username/ ask if they want to shutdown system
        cout << "please enter a user name or press 0 to log out:" << endl;
        string userin;
        string passwordin;
        cin >> userin;
        // If shutdown system, exit
        // exit(0);
        if (userin == "0") {
            cout << "logging out..." << endl;
            exit(0);
        }
        else {
            // Else prompt for password
            cout << "please enter a password:" << endl;
            cin >> passwordin;
            for (int i = 0; i < usersList.size(); i++) {
                //check if user at i matches the username and password input
                // If exists, return that user
                if ((usersList.at(i).getuserName() == userin) && (usersList.at(i).getpassword() == passwordin) {
                    cout << "Account found. Logging in..." << endl;
                    return userList.at(i);
                }
            }
            // If not, print an error and say try again
            cout << "Account not found. Please try again"<< endl;

        }
    }
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