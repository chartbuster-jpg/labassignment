#include<iostream>
using namespace std ; 

class Sunny{
private: 
       int num ; 
         

public: 
      Sunny(int n)
      {
        num = n ; 
        int num1 = num + 1 ; 
        for(int i=0; i<num1/2 ; i++){
            if(i*i==num1){cout<<"Sunny Number"<<endl ; 
            return ; }
            
        }
        cout<<"Not a Sunny Number"<<endl ; 
        return ;
       
      }

      ~Sunny(){
        cout<<"Destructor called" ; 
      }


};

int main(){

   int x ; 
    cin>>x ;
    Sunny obj(x); 
}