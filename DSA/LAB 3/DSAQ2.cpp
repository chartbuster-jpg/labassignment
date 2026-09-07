#include <bits/stdc++.h>
using namespace std;

int main()
{

    int ch, l, r, c,ll, lr, lc, base, size, i, j, k, address;

     cout << "Enter input as the following: 1.Number of layers 2.Number of rows 3.Number of columns \n ";
     cout<<"4.Lower bound of layer 5.Lower bound of row \n" ;
    cout<< "6.Lower Bound of column 7.Base address 8.Size 9.Layer Index 10.Row Index 11.Column Index\n" ;
    cin >> r >> c >> l >> ll>> lr >> lc >> base >> size >> i >> j >> k;
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
            address = base + ((i - lr)*l*c + (j - lc)*l + (k-ll)) * size;
            cout << "The address is ";
            cout<< address << endl ; 
            break;
        case 2:
            address = base + ((j - lc) *r + (i - lr) + (k-ll)*r*c) * size;
             cout << "The address is ";
            cout<< address << endl; 
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