#include <iostream>

using namespace std;

int main()
{
    string s;
    while (cin >> s){
        int i=0,j=s.length()-1; //begin,end
        int count=0;
        for (int a=0; a<s.length(); a++){
            if (s[a]=='0') count++;
        }
        if (count==s.length())
            cout << 0 << endl;
        else {
            while(s[i]=='0'){
              i++;
            }
            while(s[j]=='0')
              j--;
            for (int b=j; b>=i; b--)
              cout << s[b];
            cout << endl;
        }


    }
    return 0;
}