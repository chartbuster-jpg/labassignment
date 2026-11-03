#include <iostream>
#include <new>
using namespace std;

int main()
{
    int n = 0;
    int *arr = nullptr;

    try
    {
        cout << "Enter array size: ";
        cin >> n;

        if(n <= 0)
            throw n;

        arr = new int[n];

        cout << "Enter elements: ";
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "Array: ";
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    catch(int)
    {
        cout << "Invalid array size!";
    }
    catch(const bad_alloc&)
    {
        cout << "Memory allocation failed!";
    }

    delete[] arr;
   
}