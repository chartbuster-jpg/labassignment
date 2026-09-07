#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cout << "Enter a String: " ;
    cin >> word;

    int vowel = 0;
    int length = word.length();
    for (int i = 0; i < length; i++)
    {
        switch (word[i])
        {
        case 65:
        case 69:
        case 73:
        case 79:
        case 85:
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
            vowel++;
            break;

         default: break;
        }
    }
    int consonant = length - vowel;
    cout << "Vowels: " << vowel << endl;
    cout << "Consonants: " << consonant;
}