#include <iostream>
#include <string>
using namespace std ;

int main(){
string str ;
getline(cin,str) ;
int length = str.length() ;
int first = 0 ;
for(int i=0; i<=length ; i++)
{
     
    if(str[i]==' ' || i==length)
    {
        int last = i-1 ;
        while(last>first)
        {
			char temp = str[last] ;
			str[last] = str[first] ;
			str[first] = temp ; 
			first++ ; 
			last-- ; 
		
		}
		
		first = i + 1 ;
		

    }


}
cout<< str << endl ;

}