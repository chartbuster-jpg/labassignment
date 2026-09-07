#include <iostream>
using namespace std ; 
float S_interest(float p  , float t , float r = 7.5){
	
   float result =  (p * r * t)/100 ;
	return result ; 
}



int main(){
	float principal , rate , time ;
	cin>>principal>>rate>>time ; 
float result1 = S_interest(principal , time) ; 
	float result2 = S_interest(principal, time, rate) ;
	float difference = result2 - result1 ; 
	cout<<result1<<" "<<result2<<" "<<difference ;  	
}