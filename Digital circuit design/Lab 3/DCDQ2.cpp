#include <iostream>
#include <string>
using namespace std;

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int value(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    return ch - 'A' + 10;
}

char digit(int n)
{
    if (n < 10)
        return n + '0';
    return n - 10 + 'A';
}

int exponent(int base, int z)
{
    int exp = 0, p = 1;

    while (p < base)
    {
        p *= z;
        exp++;
    }

    if (p == base)
        return exp;
}

int main()
{
    string num, group = "", ans = "";
    int Z, X, Y;

    cout << "Enter Number  ";
    cin >> num;

    cout << "Enter Z  ";
    cin >> Z;

    cout << " Enter X  ";
    cin >> X;

    cout << "Enter Y  ";
    cin >> Y;

    int i = exponent(X, Z);
    int j = exponent(Y, Z);

    for (int k = 0; k < num.length(); k++)
    {
        int val = value(num[k]);
        string temp = "";

        while (val > 0)
        {
            temp = digit(val % Z) + temp;
            val /= Z;
        }

        while (temp.length() < i)
            temp = "0" + temp;

        group += temp;
    }

    for (int k = 0; k < group.length(); k += j)
    {
        int val = 0;

        for (int p = 0; p < j; p++)
            val = val * Z + value(group[k + p]);

        ans += digit(val);
    }

    cout << "Answer  " << ans;

    return 0;
}