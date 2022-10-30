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
    string getUser();						    // Getters
    string getPass();
    int getCopies();
    int getTime();
    string[] getList();                             // ????
    void setUser(string u);						// Setters
    void setPass(string p);
    void setCopies(int c);
    void setTime(int t);
    void setList(string[] loc);                     // ????

};
