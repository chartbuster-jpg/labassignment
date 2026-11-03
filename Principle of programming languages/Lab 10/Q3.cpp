#include <iostream>
using namespace std;

class Number
{
public:
    int x;

    Number operator + (Number n)
    {
        Number t;
        t.x = x + n.x;
        return t;
    }

    Number operator * (Number n)
    {
        Number t;
        t.x = x * n.x;
        return t;
    }

    Number operator - (Number n)
    {
        Number t;
        t.x = x - n.x;
        return t;
    }
};

int main()
{
    Number obj1, obj2, obj3, obj4;

    cout << "Enter four numbers: ";
    cin >> obj1.x >> obj2.x >> obj3.x >> obj4.x;

    obj1 = obj1 + obj2 * obj3 - obj4;

    cout << "Result: " << obj1.x;

  
}