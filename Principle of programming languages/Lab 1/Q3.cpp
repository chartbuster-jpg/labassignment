#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    
 
    cin >> n1;
    int a[n1];
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }
    
  
    cin >> n2;
    int b[n2];
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }
    
   
    int n = n1 + n2;
    int c[n];
    for (int i = 0; i < n1; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < n2; i++) {
        c[n1 + i] = b[i];
    }
    
   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] > c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    } 

    for (int i = 0; i < n; i++) {
        cout << c[i] << " "; 
    }
    cout << endl;

    return 0;
}
