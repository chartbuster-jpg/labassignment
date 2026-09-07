#include<iostream>
using namespace std ;
int main(){
int count ;
cin>>count ;
int sparse[count+1][3] ;

for (int i = 0; i < count+1; i++)
{
    for (int j = 0; j < 3; j++)
    {
        cin>>sparse[i][j] ;
    }
    
}

int row = sparse[0][0];
int col = sparse[0][1];
int matrix[row][col] ;
 
int a=1 ;
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
       if(a<count+1 && sparse[a][0]==i && sparse[a][1]==j)
       {
            matrix[i][j] = sparse[a][2] ;
            a++ ;
       } 
       else{
        matrix[i][j] = 0 ;
       }
    }
    
}

for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
       cout<<matrix[i][j] <<" " ;
    }
    cout<<endl ;
    
}


}