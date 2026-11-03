#include <iostream>
using namespace std;

struct N { int d; N *l, *r; N(int x) { d = x; l = r = 0; } };
N *T, *B;                                // T = binary tree (Q1, Q3), B = BST (Q2)

// ---------- Q1: Binary tree ----------
void create() {
    int n, x, f = 0, b = 0;
    N *q[16];
    cin >> n;
    if (n > 16) n = 16;
    for (int i = 0; i < n; i++) {
        cin >> x;
        N *t = new N(x);
        if (i == 0) T = t;
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
    if (T) q[b++] = T;
    while (f < b) {
        N *t = q[f++];
        cout << t->d << " ";
        if (t->l) q[b++] = t->l;
        if (t->r) q[b++] = t->r;
    }
}

int cnt(N *t)  { return t ? 1 + cnt(t->l) + cnt(t->r) : 0; }
int leaf(N *t) { return !t ? 0 : (!t->l && !t->r) ? 1 : leaf(t->l) + leaf(t->r); }
int ht(N *t) {                           // counts levels; return -1 for empty if edge-based
    if (!t) return 0;
    int a = ht(t->l), b = ht(t->r);
    return 1 + (a > b ? a : b);
}

// ---------- Q3: Non-recursive version of function 2 ----------
void traversals(N *t) {
    N *s[20], *o[20], *p = t;
    int a = 0, b = 0;

    cout << "Pre: ";
    if (p) s[a++] = p;
    while (a) {
        p = s[--a];
        cout << p->d << " ";
        if (p->r) s[a++] = p->r;
        if (p->l) s[a++] = p->l;
    }

    cout << "\nIn: ";
    p = t;
    while (p || a) {
        while (p) { s[a++] = p; p = p->l; }
        p = s[--a];
        cout << p->d << " ";
        p = p->r;
    }

    cout << "\nPost: ";
    if (t) s[a++] = t;
    while (a) {
        p = s[--a];
        o[b++] = p;
        if (p->l) s[a++] = p->l;
        if (p->r) s[a++] = p->r;
    }
    while (b) cout << o[--b]->d << " ";
}

// ---------- Q2: BST ----------
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
        N *s = t->r;                     // two children: inorder successor
        while (s->l) s = s->l;
        t->d = s->d;
        t->r = del(t->r, s->d);
    }
    return t;
}

// ---------- Main menu ----------
int main() {
    cout<<"Aditya Gour "<<endl ; 
    cout<<"25112011330 "<<endl ; 
    int c, x, y;
    do {
      
        cin >> c;
        if (c >= 7 && c <= 9) {  cin >> x; }
        switch (c) {
        case 1: create(); break;
        case 2: cout << "Pre: "; pre(T); cout << "\nIn: "; in(T); cout << "\nPost: "; post(T); break;
        case 3: level(); break;
        case 4: x = cnt(T); y = leaf(T); cout << "Total=" << x << " Leaf=" << y << " Internal=" << x - y; break;
        case 5: cout << "Height=" << ht(T); break;
        case 6: traversals(T); break;
        case 7: B = ins(B, x); break;
        case 8: cout << (srch(B, x) ? "Found" : "Not found"); break;
        case 9: B = del(B, x); break;
        case 10:
            if (B) {
                N *a = B, *b = B;
                while (a->l) a = a->l;
                while (b->r) b = b->r;
                cout << "Min=" << a->d << " Max=" << b->d;
            }
            break;
        case 11: in(B); break;
        }
    } while (c);
}