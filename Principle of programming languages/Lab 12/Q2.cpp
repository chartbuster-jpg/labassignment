#include <iostream>
#include <thread>
using namespace std;

void even()
{
    cout << "Even: ";
    for(int i = 2; i <= 20; i += 2)
        cout << i << " ";
    cout << endl;
}

void odd()
{
    cout << "Odd: ";
    for(int i = 1; i <= 20; i += 2)
        cout << i << " ";
    cout << endl;
}

int main()
{
    thread t1(even);
    thread t2(odd);

    t1.join();
    t2.join();

    cout << "Both threads finished.";

    return 0;
}