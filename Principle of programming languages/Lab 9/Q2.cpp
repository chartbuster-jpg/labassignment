#include <iostream>
using namespace std;

class Factorial {
private:
    int num;
    int a;
public:
    Factorial() {
        int n;
        cin >> n;
        num = n;
        a = 1;
        for (int i = 1; i <= n; i++) {
            a = a * i;
        }
    }
    Factorial(const Factorial &x) {
        num = x.num;
        a = x.a;
        cout << num << " " << a;
    }
};

int main() {
    Factorial obj1;
    Factorial obj2(obj1);
    
}