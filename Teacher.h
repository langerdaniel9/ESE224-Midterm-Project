#include <string>

class Teacher
{
private:
    // same as student but with different number of copies and borrowing time
    string username, password;
    int copies, borrowTime;
    string[] listOfCopies;

public:
    Teacher(string u, string p, int c, int t, string[] loc);
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
