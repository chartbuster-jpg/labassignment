#include <iostream>
using namespace std; 

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

void convert(int num , int radix)
{
    if(num == 0){
        return ; 
    }

convert(num/radix , radix) ; 
cout<< digits[num % radix] ; 
}


int main(){

 int num , radix ; 
 cout<< " Enter any integer number   "  <<endl; 
 cin>> num ; 
 cout<<"Enter radix  "<<endl ; 
 cin>>radix ; 

 if(num==0){
    cout<<0 ;
 }

 else{convert(num,radix);}
 cout<<endl ; 
return 0 ; 

}