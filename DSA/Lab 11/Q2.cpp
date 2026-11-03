#include <iostream>
using namespace std;

struct N { int d; N *l, *r; N(int x) { d = x; l = r = 0; } };
N *root;

N *ins(N *t, int x) {
    if (!t) return new N(x);
    if (x < t->d) t->l = ins(t->l, x);
    else if (x > t->d) t->r = ins(t->r, x);
    return t;
}

N *srch(N *t, int x) {
    while (t && t->d != x) t = x < t->d ? t->l : t->r;
    return t;
}

N *del(N *t, int x) {
    if (!t) return t;
    if (x < t->d) t->l = del(t->l, x);
    else if (x > t->d) t->r = del(t->r, x);
    else {
        if (!t->l || !t->r) {            // leaf or one child
            N *c = t->l ? t->l : t->r;
            delete t;
            return c;
        }
        N *s = t->r;                     // two children: use inorder successor
        while (s->l) s = s->l;
        t->d = s->d;
        t->r = del(t->r, s->d);
    }
    return t;
}

void show(N *t) { if (t) { show(t->l); cout << t->d << " "; show(t->r); } }

int main() {
    int c, x;
    do {
        cout << "\n1.Insert 2.Search 3.Delete 4.Min/Max 5.Show 0.Exit: ";
        cin >> c;
        if (c >= 1 && c <= 3) { cout << "Key: "; cin >> x; }
        if (c == 1) root = ins(root, x);
        else if (c == 2) cout << (srch(root, x) ? "Found" : "Not found");
        else if (c == 3) root = del(root, x);
        else if (c == 4 && root) {
            N *a = root, *b = root;
            while (a->l) a = a->l;
            while (b->r) b = b->r;
            cout << "Min=" << a->d << " Max=" << b->d;
        }
        else if (c == 5) show(root);
    } while (c);
}