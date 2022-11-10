
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;
struct toReturn
{
    string type;
    int index;
};
void getUsers(vector<Student> &studentList, vector<Teacher> &teacherList);
void getBooks(vector<Book> &bookCatalog, int &idcount);
toReturn login(vector<Student> &studentList, vector<Teacher> &teacherList);
// int date(time_t zeroTime);
void studentLoop(Student user, vector<Book> bookCatalog, time_t &zeroTime);
void teacherLoop(Teacher user, vector<Book> bookCatalog, time_t &zeroTime, int &idCount);

int main()
{
    // Data to be read in from text files
    vector<Book> bookCatalog;
    vector<Person> usersList;
    vector<Student> studentList;
    vector<Teacher> teacherList;

    // Read in data from student.txt and book.txt
    int idCount = 0;
    getUsers(studentList, teacherList);
    getBooks(bookCatalog, idCount);

    // Login system, can log in and log out on the same run

    while (true)
    {
        string type;
        int index;
        toReturn vals = login(studentList, teacherList);
        type = vals.type;
        index = vals.index;
        time_t zeroTime = time(NULL);

        if (type == "Student")
        {
            Student currentUser = studentList.at(index);
            studentLoop(currentUser, bookCatalog, zeroTime);
        }
        else if (type == "Teacher")
        {
            Teacher currentUser = teacherList.at(index);
            teacherLoop(currentUser, bookCatalog, zeroTime, idCount);
        }
        else
        {
            cerr << "userType is invalid" << endl;
            exit(5);
        }
    }
}

void getUsers(vector<Student> &studentList, vector<Teacher> &teacherList)
{
    // Written by Ethan Garcia, some comments by Daniel
    // Do file I/O, filename is usersList.txt
    fstream fin("usersList.txt");
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
        string temp;
        getline(fin, temp);
        // obtained information for one user, start creating Person
        if (rolein == 0) // for student
        {
            // assign values and attributes to temp student
            Student temp(userin, passwordin);
            // push to vector
            studentList.push_back(temp);
        }
        if (rolein == 1) // for teacher
        {
            // assign values and attributes to temp teacher
            Teacher temp(userin, passwordin);
            // push to vector
            teacherList.push_back(temp);
        }
    }
    // When everything is done, close the file and return
    fin.close();
}

void getBooks(vector<Book> &bookCatalog, int &idcount)
{
    // Written by Ethan Garcia, with comments by Daniel
    // Do file I/O, filename is booksList.txt
    fstream fin("booksList.txt");
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
        string temp;
        getline(fin, temp);

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

toReturn login(vector<Student> &studentList, vector<Teacher> &teacherList)
// written by Ethan Garcia, with some comments by Daniel
{

    while (true)
    {
        // Prompt for username/ ask if they want to shutdown system
        cout << "Please enter a user name or press 0 to shut down LMS:" << endl;
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
            for (int i = 0; i < studentList.size(); i++)
            {
                // Check if user at i matches the username and password input
                // If exists, return that user
                if ((studentList.at(i).getUserName() == userin) && (studentList.at(i).getPassword() == passwordin))
                {
                    cout << "Account found. Logging in..." << endl;
                    return toReturn{"Student", i};
                }
            }

            for (int i = 0; i < teacherList.size(); i++)
            {
                // Check if user at i matches the username and password input
                // If exists, return that user
                if ((teacherList.at(i).getUserName() == userin) && (teacherList.at(i).getPassword() == passwordin))
                {
                    cout << "Account found. Logging in..." << endl;
                    return toReturn{"Teacher", i};
                }
            }
            // If not, print an error and say try again
            cout << "Account not found. Please try again" << endl;
        }
    }
}

// int date(time_t zeroTime)
// {
//     // How many real life seconds it takes for a virtual day to pass
//     int dayLength = 5;
//     time_t currentTime = time(NULL);
//     return (currentTime - zeroTime) / dayLength;
// }

void studentLoop(Student user, vector<Book> bookCatalog, time_t &zeroTime)
{
    while (true)
    {
        int currentDate = date(zeroTime);
        cout << "Welcome back, Student\n"
             << "It has been " << currentDate << " days\n\n"
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
            user.searchBook(bookCatalog);
            break;
        }
        case 2:
        {
            // Borrow Book
            user.borrowBook(bookCatalog, zeroTime);
            break;
        }
        case 3:
        {
            // Return Book
            user.returnBook(bookCatalog);
            break;
        }
        case 4:
        {
            // Renew Book
            user.renewBook();
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

void teacherLoop(Teacher user, vector<Book> bookCatalog, time_t &zeroTime, int &idCount)

{
    while (true)
    {
        int currentDate = date(zeroTime);
        cout << "Welcome back, Teacher\n"
             << "It has been " << currentDate << " days\n\n"
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
            user.searchBook(bookCatalog);
            break;
        }
        case 2:
        {
            // Borrow Book
            user.borrowBook(bookCatalog, zeroTime);
            break;
        }
        case 3:
        {
            // Return Book
            user.returnBook(bookCatalog);
            break;
        }
        case 4:
        {
            // Renew Book
            user.renewBook();
            break;
        }
        case 5:
        {
            // Request new book
            user.requestBook(bookCatalog, idCount);
            break;
        }
        case 6:
        {
            // Delete book from vector
            user.deleteBook(bookCatalog);
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