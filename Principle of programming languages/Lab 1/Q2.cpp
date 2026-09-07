#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        bool dup = false;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                dup = true;
                break;
            }
        }
        if (dup == false)
        {
            cout << a[i];
        }
    }
    return 0;
}