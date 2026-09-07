#include <iostream>
using namespace std;
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
            if (matrix[i][j] == 0)
            {
                count++;
            }
        }
    }

  
if (count > (elements)/2)
{
    cout << "It is a sparse matrix";
}
else
{
    cout << "It is  not a sparse matrix";
}

return 0;
}