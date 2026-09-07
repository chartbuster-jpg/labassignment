#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    
    int length = a.length();
    char* p = &a[0]; 
    int s = 0;      
    int count = 0;

    for (int i = 0; i <= length; i++) {
        
        if (i == length || *(p + i) == ' ') {
            
            
            
                bool palindrome = true;
                int word = i - s;

                for (int j = 0; j < word / 2; j++) {
                   
                    if (*(p + s + j) != *(p + i - 1 - j)) {
                        palindrome = false;
                        break; 
                    }
                }

                if (palindrome) {
                    count++;
                }
            
            
            
            s = i + 1;
        }
    }

    cout << count;
    return 0;
}
