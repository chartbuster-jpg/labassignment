#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* create(int x) {
    Node *p = new Node;
    p->data = x;
    p->prev = p->next = NULL;
    return p;
}


// ================= INSERTION FUNCTION =================
// Handles:
// 1. Insert at beginning
// 2. Insert at end
// 3. Insert at position

Node* insert(Node *head) {

    int ch, x, pos;

    
    cin >> ch;

    cout << "Enter data: ";
    cin >> x;

    Node *p = create(x);

    // Empty list
    if (head == NULL) {
        p->next = p;
        p->prev = p;
        return p;
    }


    // -------- INSERT AT BEGINNING --------
    if (ch == 1) {

        Node *last = head->prev;

        p->next = head;
        p->prev = last;

        last->next = p;
        head->prev = p;

        head = p;
    }


    // -------- INSERT AT END --------
    else if (ch == 2) {

        Node *last = head->prev;

        p->next = head;
        p->prev = last;

        last->next = p;
        head->prev = p;
    }


    // -------- INSERT AT POSITION --------
    else if (ch == 3) {

        cout << "Enter position: ";
        cin >> pos;

        if (pos == 1) {

            Node *last = head->prev;

            p->next = head;
            p->prev = last;

            last->next = p;
            head->prev = p;

            head = p;
        }
        else {

            Node *t = head;

            for (int i = 1; i < pos - 1; i++) {

                t = t->next;

                // Position does not exist
                if (t == head) {
                    cout << "Invalid position\n";
                    delete p;
                    return head;
                }
            }

            p->next = t->next;
            p->prev = t;

            t->next->prev = p;
            t->next = p;
        }
    }

    else {
        cout << "Invalid choice\n";
        delete p;
    }

    return head;
}


// ================= DELETION FUNCTION =================
// Handles:
// 1. Delete from beginning
// 2. Delete from end
// 3. Delete from position

Node* deleteNode(Node *head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    int ch, pos;

    cin >> ch;


    // -------- ONLY ONE NODE --------
    if (head->next == head) {

        if (ch == 1 || ch == 2 || ch == 3) {

            if (ch == 3) {
                cout << "Enter position: ";
                cin >> pos;

                if (pos != 1) {
                    cout << "Invalid position\n";
                    return head;
                }
            }

            delete head;
            return NULL;
        }
    }


    // -------- DELETE FROM BEGINNING --------
    if (ch == 1) {

        Node *last = head->prev;
        Node *t = head;

        head = head->next;

        last->next = head;
        head->prev = last;

        delete t;
    }


    // -------- DELETE FROM END --------
    else if (ch == 2) {

        Node *last = head->prev;
        Node *newLast = last->prev;

        newLast->next = head;
        head->prev = newLast;

        delete last;
    }


    // -------- DELETE FROM POSITION --------
    else if (ch == 3) {

        cout << "Enter position: ";
        cin >> pos;

        if (pos == 1) {

            Node *last = head->prev;
            Node *t = head;

            head = head->next;

            last->next = head;
            head->prev = last;

            delete t;
        }
        else {

            Node *t = head;

            for (int i = 1; i < pos; i++) {

                t = t->next;

                if (t == head) {
                    cout << "Invalid position\n";
                    return head;
                }
            }

            t->prev->next = t->next;
            t->next->prev = t->prev;

            delete t;
        }
    }

    else {
        cout << "Invalid choice\n";
    }

    return head;
}


// ================= DISPLAY FUNCTION =================

void display(Node *head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node *t = head;

    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);

    cout << endl;
}


// ================= MAIN FUNCTION =================

int main() {

    Node *head = NULL;

    int ch;

    cout << "Aditya Patidar" << endl;
    cout << "25112011324" << endl;

    do {

       
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {

            case 1:
                head = insert(head);
                break;

            case 2:
                head = deleteNode(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (ch != 4);

    return 0;
}