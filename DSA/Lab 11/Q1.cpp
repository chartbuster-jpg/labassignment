#include <iostream>
using namespace std;

struct N { int d; N *l, *r; N(int x) { d = x; l = r = 0; } };
N *root;

void create() {                          // builds the tree level by level
    int n, x, f = 0, b = 0;
    N *q[16];
    cout << "n (<=16): "; cin >> n;
    if (n > 16) n = 16;
    for (int i = 0; i < n; i++) {
        cout << "Value: "; cin >> x;
        N *t = new N(x);
        if (i == 0) root = t;
        else if (!q[f]->l) q[f]->l = t;
        else q[f++]->r = t;
        q[b++] = t;
    }
}

void pre(N *t)  { if (t) { cout << t->d << " "; pre(t->l); pre(t->r); } }
void in(N *t)   { if (t) { in(t->l); cout << t->d << " "; in(t->r); } }
void post(N *t) { if (t) { post(t->l); post(t->r); cout << t->d << " "; } }

void level() {
    N *q[16];
    int f = 0, b = 0;
    if (root) q[b++] = root;
    while (f < b) {
        N *t = q[f++];
        cout << t->d << " ";
        if (t->l) q[b++] = t->l;
        if (t->r) q[b++] = t->r;
    }
}

int cnt(N *t)  { return t ? 1 + cnt(t->l) + cnt(t->r) : 0; }
int leaf(N *t) { return !t ? 0 : (!t->l && !t->r) ? 1 : leaf(t->l) + leaf(t->r); }
int ht(N *t) {
    if (!t) return 0;                    // counts levels; use -1 here for edge-based height
    int a = ht(t->l), b = ht(t->r);
    return 1 + (a > b ? a : b);
}

int main() {
    int c;
    do {
        cout << "\n1.Create 2.Traversals 3.Level-order 4.Count 5.Height 0.Exit: ";
        cin >> c;
        if (c == 1) create();
        else if (c == 2) {
            cout << "Pre: ";  pre(root);
            cout << "\nIn: "; in(root);
            cout << "\nPost: "; post(root);
        }
        else if (c == 3) level();
        else if (c == 4) {
            int a = cnt(root), l = leaf(root);
            cout << "Total=" << a << " Leaf=" << l << " Internal=" << a - l;
        }
        else if (c == 5) cout << "Height=" << ht(root);
    } while (c);
}