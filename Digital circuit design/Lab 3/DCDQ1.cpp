#include <iostream>
using namespace std;

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

int toDecimal(string num, int base)
{
    int deci = 0;
    for (int i = 0; i < num.length(); i++)
        deci = deci * base + value(num[i]);
    return deci;
}

void byDeci(int num, int base)
{
    if (num == 0)
    {
        cout << 0;
        return;
    }

    string ans = "";

    while (num > 0)
    {
        ans = digit(num % base) + ans;
        num /= base;
    }

    cout << ans;
}

int main()
{
    string num;
    int X, Y;

    cout << "Enter number ";
    cin >> num;

    cout << "Enter source radix ";
    cin >> X;

    cout << "Enter radix in which answer be calculated ";
    cin >> Y;

    int decimal = toDecimal(num, X);

    byDeci(decimal, Y);

    return 0;
}