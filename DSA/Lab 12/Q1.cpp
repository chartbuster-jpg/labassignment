#include <iostream>
using namespace std;

void show(int a[],int n) {
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

void insert(int h[],int &n,int x) {
    int i=n++;
    h[i]=x;

    while(i>0 && h[(i-1)/2]<h[i]) {
        swap(h[i],h[(i-1)/2]);
        i=(i-1)/2;
    }
    show(h,n);
}

void heapify(int a[],int n,int i) {
    int l=2*i+1,r=2*i+2,m=i;

    if(l<n && a[l]>a[m]) m=l;
    if(r<n && a[r]>a[m]) m=r;

    if(m!=i) {
        swap(a[i],a[m]);
        heapify(a,n,m);
    }
}

void deleteMax(int h[],int &n) {
    if(n==0) return;
    cout<<"Deleted: "<<h[0]<<"\n";
    h[0]=h[--n];
    heapify(h,n,0);
}

void heapSort(int a[],int n) {
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(int i=n-1;i>0;i--) {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main() {
    cout<<"Aditya Gour "<<endl; 
    cout<<"25112011330 "<<endl ; 
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int *h=new int[n],*a=new int[n];
    int m=0;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++) {
        cin>>a[i];
        insert(h,m,a[i]);
    }

  
    show(h,m);

    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);

  

    deleteMax(h,m);
    cout<<"After deletion: ";
    show(h,m);

    heapSort(a,n);
    cout<<"Heap Sort: ";
    show(a,n);

    delete[] h;
    delete[] a;
}