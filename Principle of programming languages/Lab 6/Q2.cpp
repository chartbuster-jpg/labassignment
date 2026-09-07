#include <iostream>
using namespace std ; 

char* encode( char str[] , int n){
	
	for(int i=0; i<n ; i++){
		str[i] = str[i] + 1 ; 
	}
	return str ; 
}


int main(){
	
	string str ; 
getline(cin,str) ;  
	int n = str.size() ; 
	cout<<str<<" " ; 
	cout<<encode(&str[0] , n) ;  
}