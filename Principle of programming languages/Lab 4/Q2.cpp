#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b , c;
    getline(cin, a);
    getline(cin, b);
    c = a + ' ' + b;
    string s[100] ;
    string word = "" ;
    int count = 0 ;

    for (int i = 0; i <= c.length(); i++)
    {
        if (c[i]==' ' || i==c.length())
        {
            
            s[count] = word ;
            count++ ;
            word = "" ;
        }
        else{ word= word + c[i] ;}
        
    }

      for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (s[j].length() > s[j + 1].length()) {
                string temp = s[j] ;
                s[j] = s[j+1] ;
                s[j+1] = temp ;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        cout << s[i] << " ";
    }
    

    

    return 0;
}
