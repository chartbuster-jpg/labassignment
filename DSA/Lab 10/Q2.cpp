#include <iostream>
using namespace std;

int q[10] ; int front = -1 ;int rear = -1 ;

void enqueue(int x){
	int n = 10 ;
    if(rear+1 % n == front){cout<<"overflow" ;}
    if(front == -1){ front =  0;}
    rear = (rear+1)% n ; 
    q[rear] = x ;
}


void dequeue(){
	int n = 10 ;
    if(front == -1){cout<<"underflow" ;}
    if(front==rear){front = rear = -1 ;}
    else{front = (front+1)%n ;}
}

void peek(){
    if(front == -1 ){return ;}
    else{cout<<q[front] ;}
   return ;
}


int main(){
	int choice ;
  do {
       
        
        cin >> choice;

        switch (choice) {
            case 1:
                int x ; 
               cin>>x ;
               enqueue(x) ;
                break;

            case 2:
                
                dequeue() ;
                break;

            case 3:
               
                peek() ;
                break;

            case 4:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Invalid " << endl;
        }

    } while (choice != 4);
    
}