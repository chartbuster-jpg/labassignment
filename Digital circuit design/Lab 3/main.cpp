#include <iostream>
#include <cmath>
using namespace std;
string conversion(string s , int idx ,int  ln){
    int n = 0;
    for(int i = 0 ; i < ln ; i++ ){
        n += (pow(idx, i)*(s[ln-i-1]-'0'));
        
    }
    
    return to_string(n);
}
string con(int num ,int radix1 ,int power ){
    string str  = "";
    while(num >= radix1){
        str = to_string(num%radix1) + str;
        num = num/radix1;
    }
    if(num != 0){
        str = to_string(num) + str;
    }
    int ln = str.length() ;
    for(int i = 0 ; i < power - ln ; i++){
        str = '0' + str;
    }
    return str;
    
}

int main() {
    
    int num , radix1 , radix2 ;
    cout << "Enter the number :";
    cin>> num;
    cout << "Enter the radix of the number :";
    cin >> radix1;
    cout << "Enter the radix for conversion";
    cin >> radix2;
    string res = "";
    int power = 1 ;
    if(radix1 < radix2){
        
        while(pow(radix1 , power) < radix2){
            power++;
        }
        
        string str = to_string(num);
        int ln = str.length();
        
        for(int i =  0 ; i < ln%power ; i++){
            str = '0' + str;
            ln++;
        }
       
        for(int i = 0 ; i < ln ; i = i + power ){
            
            res =  res  + conversion(str.substr(i ,  i + power) , radix1  , power );
        }
        
        
        
    }else{
        while(pow(radix2 , power) < radix1){
            power++;
        }
        string str = to_string(num);
        int ln = str.length();
        for(int i = 0 ; i < ln ; i = i +1 ){
            int m ;
            if((str.substr(i , i+1)[0] - '0') > 9){
                res =  res  + con(str.substr(i ,  i+1)[0] - 'A' + 10 , radix2 , power );
            }else{
                res =  res  + con(str.substr(i ,  i+1)[0] - '0' , radix2, power );
            }
            
            
        }
       
        
        
        
    }
    cout<< res;
    
    return 0;
}
    
   
    
