#include <iostream>
using namespace std;

int q[10];
int front = -1;
int rear = -1;

void rearenqueue(int x) {
    int n = 10;
    if ((rear + 1) % n == front) {
        cout << "overflow";
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    q[rear] = x;
}


void frontdequeue() {
    int n = 10;
    if (front == -1) {
        cout << "underflow";
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void reardequeue() {
    int n = 10;
    if (front == -1) {
        cout << "underflow";
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        rear = (rear - 1 + n) % n;
    }
}

void display() {
    if (front == -1) {
        return;
    } else {
        cout << q[front] << endl;
    }
}

int main() {
    int choice;
    do {
        cin >> choice;
        switch (choice) {
            
            case 1:
                frontdequeue();
                break;
            case 2:
                int x;
                cin >> x;
                rearenqueue(x);
                break;
          case 3:
                  reardequeue();
                break;
            
             case 4:
                display();
                break;
            
            
                case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid " << endl;
        }
    } while (choice != 5);
    return 0;
}