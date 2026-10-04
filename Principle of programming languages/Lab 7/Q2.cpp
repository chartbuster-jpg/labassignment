#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void insert(Node* &head, int x) {
    Node* a = new Node(x);
    if (head == NULL) {
        head = a;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = a;
}

void insertatk(Node* &head, int pos, int x) {
    Node* a = new Node(x);
    if (pos == 0) {
        a->next = head;
        head = a;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            cout << "Position is outside the range" << endl;
            delete a;
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position is outside the range" << endl;
        delete a;
        return;
    }
    a->next = temp->next;
    temp->next = a;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int value, newvalue, pos;
    for (int i = 0; i < 10; i++) {
        cin >> value;
        insert(head, value);
    }
    display(head);
    cin >> pos >> newvalue;
    int x = (pos / 2) + 2;
    insertatk(head, x, newvalue);
    display(head);

}