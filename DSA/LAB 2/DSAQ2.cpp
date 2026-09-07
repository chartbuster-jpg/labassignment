#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    int a[10][10], b[10][10], c[10][10]; 
    int r, col, i, j, k, ch, key; 
    int sum, Diag1, Diag2, largest, smallest, found; 
    cin >> r >> col; 
    do { 
        cout << "1. Create Matrix\n"; 
        cout << "2. Generate Random Matrix\n"; 
        cout << "3. Display Matrix\n"; 
        cout << "4. Display Memory Address\n"; 
        cout << "5. Row Sum\n"; 
        cout << "6. Column Sum\n"; 
        cout << "7. Diagonal Sum\n"; 
        cout << "8. Largest and Smallest\n"; 
        cout << "9. Transpose\n"; 
        cout << "10. Add Two Matrices\n"; 
        cout << "11. Multiply Two Matrices\n"; 
        cout << "12. Search Element\n"; 
        cout << "13. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> ch; 
        switch (ch) { 
            case 1: 
                for (i = 0; i < r; i++) 
                    for (j = 0; j < col; j++) 
                        cin >> a[i][j]; 
                break; 
            case 2: 
                for (i = 0; i < r; i++) 
                    for (j = 0; j < col; j++) 
                        a[i][j] = rand() % 100 + 1; 
                break; 
            case 3: 
                for (i = 0; i < r; i++) { 
                    for (j = 0; j < col; j++) 
                        cout << a[i][j] << " "; 
                    cout << endl; 
                } 
                break; 
            case 4: 
                for (i = 0; i < r; i++) 
                    for (j = 0; j < col; j++) 
                        cout << "a[" << i << "][" << j << "] = " << &a[i][j] << endl; 
                break; 
            case 5: 
                for (i = 0; i < r; i++) { 
                    sum = 0; 
                    for (j = 0; j < col; j++) 
                        sum += a[i][j]; 
                    cout << "Row " << i << " Sum = " << sum << endl; 
                } 
                break; 
            case 6: 
                for (j = 0; j < col; j++) { 
                    sum = 0; 
                    for (i = 0; i < r; i++) 
                        sum += a[i][j]; 
                    cout << "Column " << j << " Sum = " << sum << endl; 
                } 
                break; 
            case 7: 
                if (r == col) { 
                    Diag1 = Diag2 = 0; 
                    for (i = 0; i < r; i++) { 
                        Diag1 += a[i][i]; 
                        Diag2 += a[i][r - i - 1]; 
                    } 
                    cout << Diag1 <<" " << Diag2<< endl; 
                }
                break; 
            case 8: 
                largest = smallest = a[0][0]; 
                for (i = 0; i < r; i++) 
                    for (j = 0; j < col; j++) { 
                        if (a[i][j] > largest) largest = a[i][j]; 
                        if (a[i][j] < smallest) smallest = a[i][j]; 
                    } 
                cout << largest << " " << smallest << endl; 
                break; 
            case 9: 
                for (i = 0; i < col; i++) { 
                    for (j = 0; j < r; j++) 
                        cout << a[j][i] << " "; 
                    cout << endl; 
                } 
                break; 
            case 10: 
                for (i = 0; i < r; i++) 
                    for (j = 0; j < col; j++) 
                        cin >> b[i][j]; 
                cout << "Addition:\n"; 
                for (i = 0; i < r; i++) { 
                    for (j = 0; j < col; j++) { 
                        c[i][j] = a[i][j] + b[i][j]; 
                        cout << c[i][j] << " "; 
                    } 
                    cout << endl; 
                } 
                break; 
            case 11: 
                for (i = 0; i < r; i++) 
                    for (j = 0; j < col; j++) 
                        cin >> b[i][j]; 
                for (i = 0; i < r; i++) { 
                    for (j = 0; j < col; j++) { 
                        c[i][j] = 0; 
                        for (k = 0; k < col; k++) 
                            c[i][j] += a[i][k] * b[k][j]; 
                    } 
                } 
                cout << "Multiplication:\n"; 
                for (i = 0; i < r; i++) { 
                    for (j = 0; j < col; j++) 
                        cout << c[i][j] << " "; 
                    cout << endl; 
                } 
                break; 
            case 12: 
                cin >> key; 
                found = 0; 
                for (i = 0; i < r; i++) { 
                    for (j = 0; j < col; j++) { 
                        if (a[i][j] == key) { 
                            cout << "Found at Row " << i << " Column " << j << endl; 
                            found = 1; 
                        } 
                    } 
                } 
                if (!found) cout << "Element Not Found.\n"; 
                break; 
            case 13: 
                cout << "Exit\n"; 
                break; 
            default: 
                cout << "No Choice!\n"; 
        } 
    } while (ch != 13); 
    return 0; 
}
