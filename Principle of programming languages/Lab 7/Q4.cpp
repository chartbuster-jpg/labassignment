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

void deletedup(Node* head , int length){ 
    bool vis[100] = {false}; 
    Node* temp = head ; 
    int array[length] ; 
    
    for(int i=0; i<length; i++){ 
        array[i] = temp->data ; 
        temp = temp->next ; 
    } 
    
    int count = 0 ; 
    int x = 0 ; 
    
    for(int i=0; i<length; i++){ 
      
        if (vis[i]) continue; 
        
        for(int j=i; j<length; j++){ 
            if(array[i]==array[j]){ 
                count++ ; 
                vis[j] = true ; 
            } 
        } 
        
        if(count>1){ 
            cout<<array[i]<<" "<<count<<" "<<i << endl ; 
            x = 1 ; 
        } 
        count = 0 ; 
    } 
    
    if(x==0){ 
        cout<<" unique list exist "; 
    } 
    return ; 
} 

int main(){ 
    Node* head = NULL; 
    int value ; 
    for(int i=0; i<10; i++){ 
        cin>>value ; 
        insert(head,value) ; 
    } 
    deletedup(head,10) ; 
}
