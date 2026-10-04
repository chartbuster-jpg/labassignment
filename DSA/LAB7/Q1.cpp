
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* create(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

Node* insertBeg(Node *h) {
    int x; cin >> x;
    Node *p = create(x);
    p->next = h;
    return p;
}

Node* insertEnd(Node *h) {
    int x; cin >> x;
    Node *p = create(x);

    if (h == NULL) return p;

    Node *t = h;
    while (t->next != NULL) t = t->next;
    t->next = p;
    return h;
}

Node* insertPos(Node *h) {
    int x, pos; cin >> x >> pos;
    if (pos == 1) return insertBeg(h);

    Node *t = h;
    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL) return h;

    Node *p = create(x);
    p->next = t->next;
    t->next = p;
    return h;
}

Node* deleteBeg(Node *h) {
    if (h == NULL) return h;

    Node *t = h;
    h = h->next;
    delete t;
    return h;
}

Node* deleteEnd(Node *h) {
    if (h == NULL) return h;
    if (h->next == NULL) {
        delete h;
        return NULL;
    }

    Node *t = h;
    while (t->next->next != NULL) t = t->next;

    delete t->next;
    t->next = NULL;
    return h;
}

Node* deletePos(Node *h) {
    int pos; cin >> pos;
    if (pos == 1) return deleteBeg(h);

    Node *t = h;
    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL || t->next == NULL) return h;

    Node *p = t->next;
    t->next = p->next;
    delete p;
    return h;
}

void search(Node *h) {
    int x, pos = 1; cin >> x;

    while (h != NULL) {
        if (h->data == x) {
            cout << "Found at " << pos;
            return;
        }
        h = h->next;
        pos++;
    }
    cout << "Not Found";
}

void display(Node *h) {
    while (h != NULL) {
        cout << h->data << " ";
        h = h->next;
    }
}

void count(Node *h) {
    int c = 0;
    while (h != NULL) {
        c++;
        h = h->next;
    }
    cout << "Nodes = " << c;
}

int main() {
    Node *head = NULL;
    int ch, n;
    cout<<"Aditya Gour"<<endl ;
    cout<<"25112011330" <<endl;

    do {
        cin >> ch;

        switch (ch) {
            case 1:
                cin >> n;
                for (int i = 0; i < n; i++)
                    head = insertEnd(head);
                break;

            case 2: head = insertBeg(head); break;
            case 3: head = insertEnd(head); break;
            case 4: head = insertPos(head); break;
            case 5: head = deleteBeg(head); break;
            case 6: head = deleteEnd(head); break;
            case 7: head = deletePos(head); break;
            case 8: search(head); break;
            case 9: display(head); break;
            case 10: count(head); break;
        }
    } while (ch != 11);

    return 0;
}
