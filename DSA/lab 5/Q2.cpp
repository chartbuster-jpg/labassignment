#include <iostream>
using namespace std;

struct Vehicle {
    int reg, year;
    string owner, type;
    float price;
};

void add(Vehicle &v) {
    cin >> v.reg >> v.owner >> v.type >> v.year >> v.price;
}

void display(Vehicle v) {
    cout << v.reg << " " << v.owner << " "
         << v.type << " " << v.year << " "
         << v.price << endl;
}

int search(Vehicle v[], int n, int r) {
    for (int i = 0; i < n; i++)
        if (v[i].reg == r) return i;
    return -1;
}

int main() {
    Vehicle v[50];
    int n = 0, ch, r, p;

    do {
        cout << "\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\n";
        cin >> ch;

        if (ch == 1)
            add(v[n++]);

        else if (ch == 2)
            for (int i = 0; i < n; i++) display(v[i]);

        else if (ch == 3) {
            cin >> r;
            p = search(v, n, r);
            if (p != -1) display(v[p]);
            else cout << "Not found";
        }

        else if (ch == 4) {
            cin >> r;
            p = search(v, n, r);
            if (p != -1) add(v[p]);
        }

        else if (ch == 5) {
            cin >> r;
            p = search(v, n, r);
            if (p != -1) {
                for (int i = p; i < n - 1; i++)
                    v[i] = v[i + 1];
                n--;
            }
        }

    } while (ch != 6);

    return 0;
}