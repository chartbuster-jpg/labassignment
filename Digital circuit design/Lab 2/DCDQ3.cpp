#include <iostream>
#include <string>

using namespace std;

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    string str;
    cout << "Enter the binary number " << endl;
    cin >> str;

    int num1 = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            num1 = i;
            break;
        }
    }

    string hexInteger = "";
    string hexDecimal = "";

    for (int i = num1 - 1; i >= 0; i -= 4)
    {
        int val = 0, pow = 1;
        for (int j = 0; j < 4 && (i - j) >= 0; j++)
        {
            val += (str[i - j] - '0') * pow;
            pow *= 2;
        }
        hexInteger = digits[val] + hexInteger;
        
    }
    if (hexInteger == "")
        hexInteger = "0";

    if (num1 < str.length())
    {
        for (int i = num1 + 1; i < str.length(); i += 4)
        {
            int val = 0, pow = 8;
            for (int j = 0; j < 4; j++)
            {
                if ((i + j) < str.length())
                {
                    val += (str[i + j] - '0') * pow;
                }
                pow /= 2;
            }
            hexDecimal = hexDecimal + digits[val];
        }
    }

    cout << hexInteger;
    if (hexDecimal != "")
        cout << "." << hexDecimal;
    cout << endl;

    return 0;
}
