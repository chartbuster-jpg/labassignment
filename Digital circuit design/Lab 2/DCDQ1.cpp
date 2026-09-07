#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "Enter the binary number " << endl;
    cin >> str;

    int num1 = str.length();
    float integer = 0;
    float decimal = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            num1 = i;
            break;
        }
    }

    int pow1 = 1;
    for (int i = num1 - 1; i >= 0; i--)
    {

        integer += (str[i] - '0') * pow1;
        pow1 *= 2;
    }

    float pow2 = 0.5;
    for (int i = num1 + 1; i < str.length(); i++)
    {
        decimal += (str[i] - '0') * pow2;
        pow2 *= 0.5;
    }

    float result = integer + decimal;
    cout << result << endl;

    return 0;
}
