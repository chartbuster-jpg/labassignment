#include <iostream>
using namespace std;

int main()
{

    int order;

    cout << "Enter order of matrix ";
    cin >> order;
    cout << "Enter matrix elements ";
    int matrix[order][order];
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            if (i + j > order - 1)
            {
                matrix[i][j] = 0;
            };
        }
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
