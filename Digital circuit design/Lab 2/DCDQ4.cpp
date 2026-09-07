#include <iostream>
#include <string>

using namespace std;


int value(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0; 
}

int main() {
    string str;
    cout << "Enter the hexadecimal number " << endl;
    cin >> str; 
    int num1 = str.length(); 
    float integer = 0;      
    float decimal = 0;      

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            num1 = i;
            break;
        }
    }

  
    long long pow1 = 1; 
    for (int i = num1 - 1; i >= 0; i--) {
        integer +=  value(str[i]) * pow1; 
        pow1 *= 16; 
    }

    float pow2 = 1.0 / 16.0; 
    for (int i = num1 + 1; i < str.length(); i++) {
        decimal +=  value(str[i]) * pow2;
        pow2 /= 16.0; 
    }

    float result = integer + decimal;
    cout << result ;

    return 0;
}
