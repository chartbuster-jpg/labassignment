#include <iostream>
using namespace std;

struct Consumer {
    int no;
    string name;
    float units, bill;
};

void calculate(Consumer *c) {
    if (c->units <= 100)
        c->bill = c->units * 2;
    else if (c->units <= 200)
        c->bill = 200 + (c->units - 100) * 3;
    else
        c->bill = 500 + (c->units - 200) * 5;
}

void display(Consumer *c) {
    cout << c->no << " " << c->name << " "
         << c->units << " " << c->bill << endl;
}

int main() {
    Consumer c[10], *p;
    int n, max = 0;
    cout<<"Aditya Gour"<<endl ; 
    cout<<"25112011330"<< endl ; 

    cin >> n;

    for (int i = 0; i < n; i++) {
        p = &c[i];
        cin >> p->no >> p->name >> p->units;
        calculate(p);

        if (p->bill > c[max].bill)
            max = i;
    }

    for (int i = 0; i < n; i++)
        display(&c[i]);

    cout << "Highest Bill: " << c[max].name << " "
         << c[max].bill;

    return 0;
}