#include <iostream>
using namespace std;

class Number{
public:
    Number() {
       
        int num;
        cin >> num;
        
        if (num % 2 == 0) {
            cout << "The Number is Even" << endl;
        } else {
            cout << "The Number is Odd" << endl;
        }
        
        bool isPrime = true;

        if (num <= 1) {
            isPrime = false;
        } else {
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime) {
            cout << "Prime" << endl;
        } else {
            cout << "not Prime" << endl;
        }
    }
    
};

int main() {
    Number obj; 
    
}