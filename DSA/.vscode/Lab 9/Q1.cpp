#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front = NULL;
    Node* rear = NULL;
};

void enqueue(Queue &q, int value) {
    Node* p = new Node;
    p->data = value;
    p->next = NULL;
    if (q.rear == NULL) {
        q.front = q.rear = p;
    } else {
        q.rear->next = p;
        q.rear = p;
    }
    cout << value << " inserted\n";
}

void dequeue(Queue &q) {
    if (q.front == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = q.front;
    cout << "Deleted: " << temp->data << '\n';
    q.front = q.front->next;
    if (q.front == NULL) {
        q.rear = NULL;
    }
    delete temp;
}

void display(Queue &q){
    if (q.front == NULL) {
        cout << "Queue is empty\n";
        return;
    } else {
        Node* p = q.front;
        while(p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
        
    }
}

int main() {
    int choice;
    Queue q;
    do {
        cin >> choice;
        switch (choice) {
            case 1: {
                int x;
                cin >> x;
                enqueue(q, x);
                break;
            }
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid" << endl;
        }
    } while (choice != 4);
    return 0;
}