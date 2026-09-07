#include <iostream>
using namespace std ; 
int value(int n){
	
	for(int i = 0 ; i<n/2 ; i++)
	{
		if(i*i == n){
			return i ; 
		}
	}
	return -1 ; 
}

int reference(int &n){
	
	for(int i = 0 ; i<n/2 ; i++)
	{
		if(i*i == n){
			return i ; 
		}
	}
	
	return -1  ; 
}

int main(){
	int num ; 
	cin>>num ; 
	 
	 if(value(num) == -1){ cout<<"not a perfect square number "<< endl ; 
	 }
	else{
	cout<<"Square Root "<<value(num) <<" Number after call by value " << num << endl ;   
}

 if(reference(num) == -1){ cout<<"not a perfect square number "<< endl ; 
	 }
	   else{
	   	cout<<"Square Root "<<	reference(num) <<" Number after call by refernce " << num << endl ;   
}
}