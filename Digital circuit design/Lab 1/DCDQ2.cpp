#include <iostream>
using namespace std;

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


string convertInt(int num, int radix)
{
    if (num == 0)
        return "";

    return convertInt(num / radix, radix) + digits[num % radix];
}


string decimal(float fraction, int radix)
{
    string deciPart = "";

    for (int i = 0; i < 20; i++) 
    {
        if (fraction == 0.0)
            break;

        fraction *= radix;
        int integerPart = (int)fraction;

        deciPart += digits[integerPart];

        fraction -= integerPart;
    }

    return deciPart;
}

int main()
{
    float num;
    int radix;

    cout << "Enter decimal number: ";
    cin >> num;

    cout << "Enter radix: ";
    cin >> radix;

    

    int integer = (int)num;
    float fraction = num - integer;

    if (integer == 0)
        cout << "0";
    else
        cout << convertInt(integer, radix);

    if (fraction != 0)
        cout << "." << decimal(fraction, radix);

    return 0;
}