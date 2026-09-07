#include<iostream>
using namespace std ; 
int main()
{
    int m, n;
    int count = 0;

    cin >> m >> n;
    int elements = m * n;
    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
        int k = 1 ;
    int sparse[count+1][3] ;
    sparse[0][0]= m ;
    sparse[0][1] = n ;
    sparse[0][2] = count ; 
    for(int i = 0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(matrix[i][j]!=0)
            {
                sparse[k][0] = i ;
                 sparse[k][1] = j ;
                  sparse[k][2] = matrix[i][j];
                  k++ ;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<sparse[i][j] << " ";
        }
        cout<<endl ;
        
    }
    
    
}