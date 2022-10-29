#include <string>

class Student
{
private:
    // username, password, max copies, max time, list of copies borrowed
    string username, password;
    int copies, borrowTime;
    string[] listOfCopies;

public:
    Student(string u, string p, int c, int t, string[] loc);
};
