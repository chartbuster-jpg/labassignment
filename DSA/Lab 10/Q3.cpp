#include <iostream>
using namespace std;

int q[5], f = -1, r = -1, n = 5;

bool full() { return (r + 1) % n == f; }

void insertFront(int x) {
    if (full()) cout << "Overflow\n";
    else {
        if (f == -1) f = r = 0;
        else f = (f - 1 + n) % n;
        q[f] = x;
    }
}

void insertRear(int x) {
    if (full()) cout << "Overflow\n";
    else {
        if (f == -1) f = r = 0;
        else r = (r + 1) % n;
        q[r] = x;
    }
}

void deleteFront() {
    if (f == -1) cout << "Underflow\n";
    else {
        cout << q[f] << " deleted\n";
        if (f == r) f = r = -1;
        else f = (f + 1) % n;
    }
}

void deleteRear() {
    if (f == -1) cout << "Underflow\n";
    else {
        cout << q[r] << " deleted\n";
        if (f == r) f = r = -1;
        else r = (r - 1 + n) % n;
    }
}

void display() {
    if (f == -1) { cout << "Empty\n"; return; }
    int i = f;
    while (true) {
        cout << q[i] << " ";
        if (i == r) break;
        i = (i + 1) % n;
    }
    cout << endl;
}

int main() {
     cout<<"Aditya Patidar"<<endl ;
    cout<<"25112011324"<<endl ;
    int ch, x;
    do {
   
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertFront(x); break;
            case 2: cin >> x; insertRear(x); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
        }
    } while (ch != 0);
}