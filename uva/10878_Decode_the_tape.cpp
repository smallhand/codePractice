#include <iostream>
using namespace std;

int main(){
    string s;
    int ascii;
    while(getline(cin, s)) {
        ascii = 0;
        if (s[0]=='_')
            continue;
        for (int i=0; i<s.size(); i++) {
            if (s[i]==' ')
                ascii *= 2;
            else if (s[i]=='o')
                ascii = ascii*2 +1 ;
        }
        printf("%c", ascii);
    }
    return 0;
}