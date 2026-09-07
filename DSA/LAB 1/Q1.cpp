#include <iostream>
using namespace std;

int main() {
    int a[100];
    int n, ch, i, pos, val;
    int comp, shift;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (i = 0; i < n; i++)
        cin >> a[i];
    do {
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Kth Position\n";
        cout << "4. Insert Before Kth Position\n";
        cout << "5. Insert After Kth Position\n";
        cout << "6. Delete First Element\n";
        cout << "7. Delete Last Element\n";
        cout << "8. Delete Kth Position\n";
        cout << "9. Delete Given Element\n";
        cout << "10. Delete Element Not Present\n";
        cout << "11. Display Array\n";
        cout << "12. Exit\n";
        cout << "Enter choice ";
        cin >> ch;
        comp = 0;
        shift = 0;
        switch (ch) {
            case 1:
                if (n >= 100) {
                    cout << "Array Overflow\n";
                    break;
                }
                cout << "Enter element ";
                cin >> val;
                for (i = n; i > 0; i--) {
                    a[i] = a[i - 1];
                    shift++;
                }
                a[0] = val;
                n++;
                break;
            case 2:
                if (n >= 100) {
                    cout << "Array Overflow\n";
                    break;
                }
                cout << "Enter element ";
                cin >> val;
                a[n] = val;
                n++;
                break;
            case 3:
                if (n >= 100) {
                    cout << "Array Overflow\n";
                    break;
                }
                cout << "Enter position ";
                cin >> pos;
                cout << "Enter element ";
                cin >> val;
                for (i = n; i >= pos; i--) {
                    a[i] = a[i - 1];
                    shift++;
                }
                a[pos - 1] = val;
                n++;
                break;
            case 4:
                if (n >= 100) {
                    cout << "Array Overflow\n";
                    break;
                }
                cout << "Enter K ";
                cin >> pos;
                cout << "Enter element: ";
                cin >> val;
                for (i = n; i >= pos - 1; i--) {
                    a[i] = a[i - 1];
                    shift++;
                }
                a[pos - 2] = val;
                n++;
                break;
            case 5:
                if (n >= 100) {
                    cout << "Array Overflow\n";
                    break;
                }
                cout << "Enter K ";
                cin >> pos;
                cout << "Enter element: ";
                cin >> val;
                for (i = n; i > pos; i--) {
                    a[i] = a[i - 1];
                    shift++;
                }
                a[pos] = val;
                n++;
                break;
            case 6:
                if (n <= 0) {
                    cout << "Array Underflow\n";
                    break;
                }
                for (i = 0; i < n - 1; i++) {
                    a[i] = a[i + 1];
                    shift++;
                }
                n--;
                break;
            case 7:
                if (n <= 0) {
                    cout << "Array Underflow\n";
                    break;
                }
                n--;
                break;
            case 8:
                if (n <= 0) {
                    cout << "Array Underflow\n";
                    break;
                }
                cout << "Enter position: ";
                cin >> pos;
                for (i = pos - 1; i < n - 1; i++) {
                    a[i] = a[i + 1];
                    shift++;
                }
                n--;
                break;
            case 9: {
                bool found = false;
                cout << "Enter element to delete: ";
                cin >> val;
                for (i = 0; i < n; i++) {
                    comp++;
                    if (a[i] == val) {
                        found = true;
                        for (int j = i; j < n - 1; j++) {
                            a[j] = a[j + 1];
                            shift++;
                        }
                        n--;
                        cout << "Element Deleted\n";
                        break;
                    }
                }
                if (!found) cout << "Element Not Found\n";
                break;
            }
            case 10: {
                bool found = false;
                cout << "Enter element: ";
                cin >> val;
                for (int i = 0; i < n; i++) {
                    comp++;
                    if (a[i] == val) {
                        found = true;
                        break;
                    }
                }
                if (found) cout << "Element Present\n";
                else cout << "Element Not Present\n";
                break;
            }
            case 11:
                cout << "Array: ";
                for (i = 0; i < n; i++)
                    cout << a[i] << " ";
                cout << endl;
                break;
            case 12:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
        if (ch >= 1 && ch <= 10) {
            cout << "Comparisons = " << comp << endl;
            cout << "Shifts = " << shift << endl;
        }
    } while (ch != 12);
    return 0;
}
