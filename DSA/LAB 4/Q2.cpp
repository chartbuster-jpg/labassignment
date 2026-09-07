#include<iostream>
using namespace std ; 
int main()
{
    int m,n , sparse ;
    int count = 0; 
    float saved,percentsaved ;

     
    cin>>m>>n ;
    int elements = m*n ;
    int matrix[m][n] ;
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++)
        {
            cin>> matrix[i][j] ;
        }
    }

         for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++)
        {
           if(matrix[i][j]==0)
           {count++ ;}
        }
        }
     
    sparse = (elements - count+1) * 3 ;
        saved = (float)(elements - sparse) / elements ; 
     percentsaved = saved * 100 ;
    cout<< percentsaved << "%" ;

     return 0 ;

}