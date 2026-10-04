#include <iostream>
using namespace std ;  
struct Node{
  
    int data ; 
    Node* next ; 
   Node(int x){
        data = x ; 
        next = NULL ;  
   }
    
} ; 

void insert(Node* &head , int x){

      Node* a = new Node(x) ; 
      a->next = NULL ;
       Node* temp = head ;
      if(head==NULL){
        head = a ; 
        return ;
      }
      else{
        
      while(temp->next!=NULL)
        temp = temp->next ;
      } 
      temp->next = a ;
     

}

int main(){
     Node* head = NULL; 
     int value ; 

     for(int i=0; i<10; i++){

         cin>>value ; 
         insert(head,value) ;
     }

    Node* temp = head ; 
    while(temp!=NULL){
        cout<< temp->data <<" " ; 
        temp= temp->next ;
    }


}