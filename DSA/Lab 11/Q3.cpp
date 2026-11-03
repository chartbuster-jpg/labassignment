// Non-recursive version of Function 2 (uses manual stacks, only iostream)
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