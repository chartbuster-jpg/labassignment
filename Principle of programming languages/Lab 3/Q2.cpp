#include <iostream>
using namespace std;

int main()
{

    int array[100];

    int n;
    cout << "Enter number of elements in array: " << endl;
    cin >> n;

    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> *(array + i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (*(array + i) > *(array + j))
            {

                int temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << endl;

    return 0;
}
