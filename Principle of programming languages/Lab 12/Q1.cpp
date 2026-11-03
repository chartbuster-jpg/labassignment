#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int age, size;
    float marks;

    try
    {
        cin >> name >> age >> marks >> size;

        if(age < 1 || age > 100)
            throw age;

        if(marks < 0 || marks > 100)
            throw marks;

        if(size <= 0)
            throw string("Invalid array size");

        cout << "Record is valid";
    }
    catch(int)
    {
        cout << "Invalid age";
    }
    catch(float)
    {
        cout << "Invalid marks";
    }
    catch(string e)
    {
        cout << e;
    }

   
}