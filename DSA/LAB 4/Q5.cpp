#include <iostream>
using namespace std;

int main()
{
    int n1, n2;

    cin >> n1;

    int s1[n1 + 1][3];

    for (int i = 0; i < n1 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> s1[i][j];
    }

    cin >> n2;

    int s2[n2 + 1][3];

    for (int i = 0; i < n2 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> s2[i][j];
    }

    int sadd[n1 + n2 + 1][3];

    sadd[0][0] = s1[0][0];
    sadd[0][1] = s1[0][1];
    sadd[0][2] = 0;

    int i = 1, j = 1, k = 1;

    while (i <= n1 && j <= n2)
    {
        if (s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1])
        {
            sadd[k][0] = s1[i][0];
            sadd[k][1] = s1[i][1];
            sadd[k][2] = s1[i][2] + s2[j][2];
            i++;
            j++;
        }
        else if (s1[i][0] < s2[j][0] ||
                (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1]))
        {
            sadd[k][0] = s1[i][0];
            sadd[k][1] = s1[i][1];
            sadd[k][2] = s1[i][2];
            i++;
        }
        else
        {
            sadd[k][0] = s2[j][0];
            sadd[k][1] = s2[j][1];
            sadd[k][2] = s2[j][2];
            j++;
        }
        k++;
    }

    while (i <= n1)
    {
        sadd[k][0] = s1[i][0];
        sadd[k][1] = s1[i][1];
        sadd[k][2] = s1[i][2];
        i++;
        k++;
    }

    while (j <= n2)
    {
        sadd[k][0] = s2[j][0];
        sadd[k][1] = s2[j][1];
        sadd[k][2] = s2[j][2];
        j++;
        k++;
    }

    sadd[0][2] = k - 1;

    cout << "Addition:\n";
    for (int i = 0; i < k; i++)
        cout << sadd[i][0] << " " << sadd[i][1] << " " << sadd[i][2] << endl;


    // Subtraction
    int ssub[n1 + n2 + 1][3];

    ssub[0][0] = s1[0][0];
    ssub[0][1] = s1[0][1];
    ssub[0][2] = 0;

    i = 1;
    j = 1;
    k = 1;

    while (i <= n1 && j <= n2)
    {
        if (s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1])
        {
            ssub[k][0] = s1[i][0];
            ssub[k][1] = s1[i][1];
            ssub[k][2] = s1[i][2] - s2[j][2];
            i++;
            j++;
        }
        else if (s1[i][0] < s2[j][0] ||
                (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1]))
        {
            ssub[k][0] = s1[i][0];
            ssub[k][1] = s1[i][1];
            ssub[k][2] = s1[i][2];
            i++;
        }
        else
        {
            ssub[k][0] = s2[j][0];
            ssub[k][1] = s2[j][1];
            ssub[k][2] = -s2[j][2];   
            j++;
        }
        k++;
    }

    while (i <= n1)
    {
        ssub[k][0] = s1[i][0];
        ssub[k][1] = s1[i][1];
        ssub[k][2] = s1[i][2];
        i++;
        k++;
    }

    while (j <= n2)
    {
        ssub[k][0] = s2[j][0];
        ssub[k][1] = s2[j][1];
        ssub[k][2] = -s2[j][2];   
        j++;
        k++;
    }

    ssub[0][2] = k - 1;

    cout << "Subtraction:\n";
    for (int i = 0; i < k; i++)
        cout << ssub[i][0] << " " << ssub[i][1] << " " << ssub[i][2] << endl;

    return 0;
}