#include <iostream>
using namespace std;

int main()
{
    int order;
    int mostfrequent = 1;

    cout << " Enter order and elements of array ";
    cin >> order;
    int array[order];
    int length = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < order; i++)
    {
        cin >> array[i];
    }

    int num = array[0];

    for (int i = 0; i < length; i++)
    {
        int count = 0;

        for (int j = 0; j < length; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }

        cout << "Frequency of " << array[i] << " is " << count << "\n";
        if (count >= mostfrequent)
        {
            mostfrequent = count;
            num = array[i];
        }
    }

    cout << " Most frequent number is " << num << " \n";
    return 0;
}