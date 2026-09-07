#include <iostream>
using namespace std;

void convertInteger(int num)
{
    if (num == 0)
    {
        return;
    }

    int rem = num % 2;
    convertInteger(num / 2);
    cout << rem;
}


void convertFraction(double frac, int x = 10)
{
    if (frac == 0) return;

    cout << ".";
    int count = 0;
    
    while (frac > 0 && count < x)
    {
        frac *= 2;
        int bit = (int)frac; 
        cout << bit;
        frac -= bit;         
        count++;
    }
}

int main()
{
    double num;
    cout << "Enter any decimal number: " << endl;
    cin >> num;

   
    int integerPart = (int)num;
    double fractionalPart = num - integerPart;

    if (integerPart == 0)
    {
        cout << 0;
    }
    else
    {
        convertInteger(integerPart);
    }

    convertFraction(fractionalPart);

    cout << endl;
    return 0;
}
