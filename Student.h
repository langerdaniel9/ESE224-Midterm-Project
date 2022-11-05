#include <string>
#include <vector>

class Student
{
private:
    // username, password, max copies, max time, list of copies borrowed
    string username, password;
    int copies, borrowTime;
    vector<string> listOfCopies;

public:
    Student(string u, string p, int c, int t, string[] loc);
    string getUser();						    // Getters
    string getPass();
    int getCopies();
    int getTime();
    vector<string> getList();                             
    void setUser(string u);						// Setters
    void setPass(string p);
    void setCopies(int c);
    void setTime(int t);
    void setList(vector<string> loc);                     // ????

    void searchBook();
    void quickSort(vector<Book> lib, int low, int high);
    int partition(vector<Book> lib, int low, int high);
};
