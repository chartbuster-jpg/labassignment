
#include <iostream>
using namespace std;

class Student
{
public:
    int id;
    char name[50];

    void reg()
    {
        cin >> id >> name;
    }
};

class Exam : public Student
{
public:
    int marks[5];
    int total = 0;

    void mark()
    {
        total = 0;
        for(int i = 0; i < 5; i++)
        {
            cin >> marks[i];
            total = total + marks[i];
        }
    }
};

class Result : public Exam
{
public:
    float percent;

    void per()
    {
        percent = (total / 500.0) * 100;
    }

    void display()
    {
        cout << id << " " << name << " ";
        for(int i = 0; i < 5; i++)
            cout << marks[i] << " ";

        cout << percent << "%";
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    Result r[100];

    for(int i = 0; i < n; i++)
    {
        r[i].reg();
        r[i].mark();
        r[i].per();
    }

    for(int i = 0; i < n; i++)
        r[i].display();

    return 0;
}
