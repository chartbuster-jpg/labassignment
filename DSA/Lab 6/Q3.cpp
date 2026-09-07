#include <iostream>
using namespace std;

struct Address {
    string city;
    int pin;
};

struct Employee {
    int id;
    string name;
    Address addr;
};

void input(Employee *e) {
    cin >> e->id >> e->name
        >> e->addr.city >> e->addr.pin;
}

void display(Employee *e) {
    cout << e->id << " " << e->name << " "
         << e->addr.city << " " << e->addr.pin << endl;
}

int main() {
    Employee e[20];
    int n, id;
    cout<<"Aditya Gour"<<endl ; 
    cout<<"25112011330"<< endl ; 


    cin >> n;

    for (int i = 0; i < n; i++)
        input(&e[i]);

    for (int i = 0; i < n; i++)
        display(&e[i]);

    cin >> id;

    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            display(&e[i]);
            cin >> e[i].addr.city >> e[i].addr.pin;
        }
    }

    return 0;
}