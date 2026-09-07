#include <bits/stdc++.h>
using namespace std;

int main()
{

    int ch, r, c, lr, lc, base, size, i, j, address;

    cout << "Enter input as the following: 1.Number of rows 2.Number of columns 3.Lower Bound of row\n ";
    cout<< "4.Lower Bound of column 5.Base address 6.Size 7.Row Index 8.Column Index\n" ;
    cin >> r >> c >> lr >> lc >> base >> size >> i >> j;
    cout << "Enter the choice ";

    do
    {

        cout << "1. Row-Major order\n";
        cout << "2. Column-Major order\n";
        cout << "3. Exit\n";

        cin >> ch;

        switch (ch)
        {

        case 1:
            address = base + ((i - lr) *c + (j - lc)) * size;
            cout << "The address is ";
            cout<< address << endl ; 
            break;
        case 2:
            address = base + ((j - lc) *r + (i - lr)) * size;
             cout << "The address is ";
            cout<< address << endl ; 
			break;

        case 3:
            cout << "Exit";
            break ; 

        default:
            cout << "No Choice!\n";
            break ; 
        }

    } while (ch != 3);

    return 0;
}