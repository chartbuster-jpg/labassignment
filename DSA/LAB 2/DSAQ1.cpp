#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100], b[100], c[200], d[200];
    int n, m, choice, i, j, find, temp, found;

    cout << "Enter size of first array: ";
    cin >> n;

    do
    {

        cout << "1. Generate Random Numbers & Display\n";
        cout << "2. Linear Search\n";
        cout << "3. Reverse Array\n";
        cout << "4. Merge Two Arrays\n";
        cout << "5. Concatenate Two Arrays\n";
        cout << "6. Remove Duplicates\n";
        cout << "7. Display Index, Value and Address\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            for (i = 0; i < n; i++)
                a[i] = rand() % 100 + 1;

            cout << "Array: ";
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            break;

        case 2:
            cout << "Enter element to search: ";
            cin >> find;

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (a[i] == find)
                {
                    cout << "Found at index " << i << endl;
                    found = 1;
                    break;
                }
            }

            if (!found)
                cout << "Element not found.\n";
            break;

        case 3:
            for (i = 0; i < n / 2; i++)
            {
                temp = a[i];
                a[i] = a[n - i - 1];
                a[n - i - 1] = temp;
            }

            cout << "Reversed Array: ";
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            break;

        case 4:
            cout << "Enter size of second array: ";
            cin >> m;

            cout << "Enter elements:\n";
            for (i = 0; i < m; i++)
                cin >> b[i];

            for (i = 0; i < n; i++)
                c[i] = a[i];

            for (j = 0; j < m; j++)
                c[i++] = b[j];

            cout << "Merged Array: ";
            for (i = 0; i < n + m; i++)
                cout << c[i] << " ";
            cout << endl;
            break;

        case 5:
            cout << "Enter size of second array: ";
            cin >> m;

            cout << "Enter elements:\n";
            for (i = 0; i < m; i++)
                cin >> b[i];

            for (i = 0; i < n; i++)
                d[i] = a[i];

            for (i = 0; i < m; i++)
                d[n + i] = b[i];

            cout << "Concatenated Array: ";
            for (i = 0; i < n + m; i++)
                cout << d[i] << " ";
            cout << endl;
            break;

        case 6:
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n;)
                {
                    if (a[i] == a[j])
                    {
                        for (int k = j; k < n - 1; k++)
                            a[k] = a[k + 1];
                        n--;
                    }
                    else
                        j++;
                }
            }

            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            break;

        case 7:
          
            for (i = 0; i < n; i++)
                cout <<"index"<< i << "value " << a[i] << "Address " << &a[i] << endl;
            break;

        case 8:
            cout << "Game Over\n";
            break;

        default:
            cout << "No Choice!\n";
        }

    } while (choice != 8);

    return 0;
}