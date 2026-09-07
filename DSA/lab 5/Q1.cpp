#include <iostream>
using namespace std;

struct Consumer {
    int no;
    string name;
    float units, bill;
};

void calculate(Consumer &c) {
    if (c.units <= 100)
        c.bill = c.units * 2;
    else if (c.units <= 200)
        c.bill = 200 + (c.units - 100) * 3;
    else
        c.bill = 500 + (c.units - 200) * 5;
}

void display(Consumer c) {
    cout << c.no << " " << c.name << " "
         << c.units << " " << c.bill << endl;
}

int main() {
    Consumer c[10];
    int n, max = 0;
    cout<<25112011324<<endl;
    cout<<"Aditya Patidar"<<endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i].no >> c[i].name >> c[i].units;
        calculate(c[i]);
        if (c[i].bill > c[max].bill)
            max = i;
    }

    for (int i = 0; i < n; i++)
        display(c[i]);

    cout << "Highest Bill: " << c[max].name
         << " " << c[max].bill;

    return 0;
}