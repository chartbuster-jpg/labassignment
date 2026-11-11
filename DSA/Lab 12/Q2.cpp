#include <iostream>
using namespace std;

int L=0,R=0;

struct Node {
    int d,h;
    Node *l,*r;

    Node(int x) {
        d=x;
        h=1;
        l=r=NULL;
    }
};

int height(Node *t) {
    if(t==NULL) return 0;
    return t->h;
}

int balance(Node *t) {
    return height(t->l)-height(t->r);
}

void update(Node *t) {
    int a=height(t->l),b=height(t->r);

    if(a>b) t->h=a+1;
    else t->h=b+1;
}

Node* rightRotate(Node *y) {
    R++;
    Node *x=y->l,*t=x->r;

    x->r=y;
    y->l=t;

    update(y);
    update(x);

    return x;
}

Node* leftRotate(Node *x) {
    L++;
    Node *y=x->r,*t=y->l;

    y->l=x;
    x->r=t;

    update(x);
    update(y);

    return y;
}

Node* insert(Node *t,int x) {
    if(t==NULL) return new Node(x);

    if(x<t->d) t->l=insert(t->l,x);
    else if(x>t->d) t->r=insert(t->r,x);
    else return t;

    update(t);

    int b=balance(t);

    if(b>1 && x<t->l->d)
        return rightRotate(t);

    if(b<-1 && x>t->r->d)
        return leftRotate(t);

    if(b>1 && x>t->l->d) {
        t->l=leftRotate(t->l);
        return rightRotate(t);
    }

    if(b<-1 && x<t->r->d) {
        t->r=rightRotate(t->r);
        return leftRotate(t);
    }

    return t;
}

void pre(Node *t) {
    if(t) {
        cout<<t->d<<" ";
        pre(t->l);
        pre(t->r);
    }
}

void in(Node *t) {
    if(t) {
        in(t->l);
        cout<<t->d<<" ";
        in(t->r);
    }
}

void post(Node *t) {
    if(t) {
        post(t->l);
        post(t->r);
        cout<<t->d<<" ";
    }
}

int main() {
    cout<<"Aditya Gour "<<endl; 
    cout<<"25112011330 "<<endl ; 
    Node *root=NULL;
    int n,x;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) {
        cin>>x;
        root=insert(root,x);
    }

    cout<<"Left Rotations: "<<L<<"\n";
    cout<<"Right Rotations: "<<R<<"\n";

    cout<<"Preorder: ";
    pre(root);

    cout<<"\nInorder: ";
    in(root);

    cout<<"\nPostorder: ";
    post(root);

    return 0;
}