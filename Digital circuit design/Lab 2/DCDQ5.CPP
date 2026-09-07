#include <iostream> 
using namespace std; 

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

string convertInt(int num) { 
    if (num == 0) { 
        return ""; 
    } 
    
    int rem = num % 16; 
   
    return convertInt(num / 16) + digits[rem]; 
} 

string decimal(float fraction) { 
    string deciPart = ""; 
    
    for (int i = 0; i < 10; i++) { 
        if (fraction == 0.0) break; 
        
        fraction = fraction * 16; 
        int integerPart2 = fraction; 
        float deciPart2 = fraction - integerPart2; 
        
        deciPart = deciPart + digits[integerPart2]; 
        fraction = deciPart2; 
        
        if (fraction == 0.0) { 
            break; 
        } 
    } 
    return deciPart; 
} 

int main() { 
    float num; 
    cout << "Enter any decimal number " << endl; 
    cin >> num; 

   
    int integerPart = (int)num; 
    float fractionPart = num - integerPart; 

  
    if (integerPart == 0) {
        cout << "0";
    } else {
        cout << convertInt(integerPart); 
    }

   
    if (fractionPart > 0) {
        cout << "." << decimal(fractionPart); 
    }

    cout << endl;
    return 0; 
}
