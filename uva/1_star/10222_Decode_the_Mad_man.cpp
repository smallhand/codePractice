#include <iostream>

using namespace std;

char keyboard[] = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main(){
    char maps[256];
    
    string s;
    for (int i=2; keyboard[i]; i++) {
        maps[keyboard[i]] = keyboard[i-2];
    }
    while(getline(cin, s)){
        for (int i=0; i<s.size(); i++) {
            if (s[i]==' ')
                cout << " ";
            else
                cout << maps[tolower(s[i])];
        }
        cout << endl;
    }
    return 0;
}