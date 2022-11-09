
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

void getUsers(vector<Person> usersList);
void getBooks(vector<Book> bookCatalog, int &idcount);
Person login(vector<Person> usersList);
int date(time_t zeroTime);
void studentLoop(Person user, vector<Book> bookCatalog, time_t zeroTime);
void teacherLoop(Person user, vector<Book> bookCatalog, time_t zeroTime, int &idCount);

int main()
{
    // Data to be read in from text files
    vector<Book> bookCatalog;
    vector<Person> usersList;

    // Read in data from student.txt and book.txt
    int idCount = 0;
    getUsers(usersList);
    getBooks(bookCatalog, idCount);

    // Login system, can log in and log out on the same run
    Person currentUser;

    //////////////////
    time_t zeroTime = time(NULL);
    studentLoop(currentUser, bookCatalog, zeroTime);
    //////////////////

    while (true)
    {
        currentUser = login(usersList);
        time_t zeroTime = time(NULL);

        if (currentUser.getType() == "Student")
        {
            studentLoop(currentUser, bookCatalog, zeroTime);
        }
        else if (currentUser.getType() == "Teacher")
        {
            teacherLoop(currentUser, bookCatalog, zeroTime, idCount);
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
    // Written by Ethan Garcia, some comments by Daniel
    // Do file I/O, filename is usersList.txt
    ifstream fin("userList.txt");
    if (fin.fail())
    {
        cerr << "error opening userList" << endl;
        exit(1);
    }

    /* Ethan's edit, It will be done variable by variable since each Person has 3 fields that need to be read.
     *
     * The format will be
     * Role(0=student, 1=teacher)  user_name   password
     */

    // If current line is a student, create new student with those attributes and push to the vector
    // Else if it is a teacher, create new teacher with those attributes and push to the vector

    int rolein;
    string userin;
    string passwordin;
    while (!(fin.eof()))
    {
        fin >> rolein >> userin >> passwordin;
        // obtained information for one user, start creating Person
        if (rolein == 0) // for student
        {
            // assign values and attributes to temp student
            Student temp(userin, passwordin);
            // push to vector
            usersList.push_back(temp);
        }
        if (rolein == 1) // for teacher
        {
            // assign values and attributes to temp teacher
            Teacher temp(userin, passwordin);
            // push to vector
            usersList.push_back(temp);
        }
    }
    // When everything is done, close the file and return
    fin.close();
}

void getBooks(vector<Book> bookCatalog, int &idcount)
{
    // Written by Ethan Garcia, with comments by Daniel
    // Do file I/O, filename is booksList.txt
    ifstream fin("booksList.txt");
    if (fin.fail())
    {
        cerr << "error opening booksList" << endl;
        exit(1);
    }
    /*  Ethan's edit, file input will be done variable by variable,since there is always a constant
     *  amount of fields that needs be read.
     *
     * The format will be
     * ISBN    Title  Author  Category    Num_of_copies
     */
    string isbnin;
    string titlein;
    string authorin;
    string catagoryin;
    string copyin;
    while (!fin.eof())
    {
        // For each line push a new Book object to the vector with the correct attributes
        fin >> isbnin >> titlein >> authorin >> catagoryin >> copyin;
        // If there are multiple copies
        for (int i = 0; i < stoi(copyin); i++)
        {
            Book temp(idcount, isbnin, titlein, authorin, catagoryin);
            idcount++;
            bookCatalog.push_back(temp);
        }
    }
    // When everything is done, close the file and return
    fin.close();
}

Person login(vector<Person> usersList)
// written by Ethan Garcia, with some comments by Daniel
{
    while (true)
    {
        // Prompt for username/ ask if they want to shutdown system
        cout << "Please enter a user name or press 0 to log out:" << endl;
        string userin;
        string passwordin;
        cin >> userin;
        // If shutdown system, exit
        if (userin == "0")
        {
            cout << "Logging out..." << endl;
            exit(0);
        }
        else
        {
            // Else prompt for password
            cout << "Please enter a password:" << endl;
            cin >> passwordin;
            for (int i = 0; i < usersList.size(); i++)
            {
                // Check if user at i matches the username and password input
                // If exists, return that user
                if ((usersList.at(i).getUserName() == userin) && (usersList.at(i).getPassword() == passwordin))
                {
                    cout << "Account found. Logging in..." << endl;
                    return usersList.at(i);
                }
            }
            // If not, print an error and say try again
            cout << "Account not found. Please try again" << endl;
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
            // user.search(bookCatalog, zeroTime);
            cout << "You have entered search" << endl;
            break;
        }
        case 2:
        {
            // Borrow Book
            // user.borrow(bookCatalog);
            cout << "You have entered borrow" << endl;
            break;
        }
        case 3:
        {
            // Return Book
            // user.bookReturn(bookCatalog);
            cout << "You have entered return" << endl;
            break;
        }
        case 4:
        {
            // Renew Book
            // user.renew(bookCatalog);
            cout << "You have entered renew" << endl;
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

void teacherLoop(Person user, vector<Book> bookCatalog, time_t zeroTime, int &idCount)

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
            // user.search(bookCatalog);
            break;
        }
        case 2:
        {
            // Borrow Book
            // user.borrow(bookCatalog);
            break;
        }
        case 3:
        {
            // Return Book
            // user.bookReturn(bookCatalog);
            break;
        }
        case 4:
        {
            // Renew Book
            // user.renew(bookCatalog);
            break;
        }
        case 5:
        {
            // Request new book
            // user.request(bookCatalog, idCount);
            break;
        }
        case 6:
        {
            // Delete book from vector
            // user.delete(bookCatalog);
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