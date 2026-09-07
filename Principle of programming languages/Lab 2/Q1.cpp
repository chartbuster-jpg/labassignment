#include <iostream>
using namespace std;

int main()
{
    int order;
    int max = 0;

    cout << " Enter order and elements of array ";
    cin >> order;
    int array[order];
    int length = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < order; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < length; i++)
    {
        if (array[i] >= max)
        {
            max = array[i];
        }
    }
    cout << " The pairs whose sum is less than maximum element are following";
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            int sum = array[i] + array[j];
            if (sum < max)
            {
                cout << array[i] << " " << array[j] << " " << endl;
            }
        }
    }
}
