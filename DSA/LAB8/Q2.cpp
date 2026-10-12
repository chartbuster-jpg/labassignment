#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void create() {
    int n;
   
    cin >> n;

    for (int i = 0; i < n; i++) {
        int ids;
        string s;
       
        cin >> ids >> s;

        Node* temp = new Node;
        temp->id = ids;
        temp->name = s;

        if (!head)
            head = tail = temp, head->next = head->prev = head;
        else {
            tail->next = temp;
            temp->prev = tail;
            temp->next = head;
            head->prev = temp;
            tail = temp;
        }
    }
}

void search() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    int x;
 
    cin >> x;

    Node* temp = head;
    bool flag = false;

    do {
        if (temp->id == x) {
            flag = true;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    cout << (flag ? "Student found\n" : "Student not found\n");
}

void sort() {
    if (!head) return;

    Node* temp = head;
    int n = 0;

    do {
        n++;
        temp = temp->next;
    } while (temp != head);

    for (int i = 0; i < n; i++) {
        Node* temp1 = head;
        for (int j = 1; j < n - i; j++) {
            Node* temp2 = temp1->next;
            if (temp1->id > temp2->id) {
                swap(temp1->id, temp2->id);
                swap(temp1->name, temp2->name);
            }
            temp1 = temp1->next;
        }
    }
}

void display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->id << " " << temp->name << "\n";
        temp = temp->next;
    } while (temp != head);
}

int main() {
     
     cout<<"Aditya Gour"<<endl ;
     cout<<"25112011330"<<endl ;
    int ch;

    do {
       
        cin >> ch;

        switch (ch) {
            case 1: create(); break;
            case 2: search(); break;
            case 3: sort(); cout << "Sorted\n"; break;
            case 4: display(); break;
            case 5: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}