#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base
{
public:
    ~Derived()
    {
        cout << "Derived destructor called" << endl;
    }
};

int main()
{
    Base *ptr = new Derived();

    cout << "int main" << endl;

    delete ptr;

}