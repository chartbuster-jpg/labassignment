#include <iostream>
using namespace std;

class Employee
{
public:
    int salary;
    int hours;

    void AddInfo()
    {
        cin >> salary;
        cin >> hours;
    }

    void AddSal()
    {
        if(salary < 500)
            salary = salary + 10;
    }

    void AddWork()
    {
        if(hours > 6)
            salary = salary + 5;
    }
};

int main() {
   
    Employee e;

    cout << "Enter salary and working hours: ";
    e.AddInfo();
    e.AddSal();
    e.AddWork();

    cout << "Salary: " << e.salary;

}