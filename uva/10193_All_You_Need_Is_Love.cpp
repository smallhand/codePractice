/*
給S1, S2, 找出L，讓S1、S2分別一直減L後可以得到L -> L即為gcd(S1, S2)
所以可以直接把二進位轉乘十進位，求gcd
*/
#include <iostream>
#include <sstream>
using namespace std;

int b2i(string s){
    int num = 0;
    for (int i=0; i<s.size(); i++){
        num <<= 1;
        num += s[i]-'0';
    }
    return num;
}

int gcd(int n1, int n2){
    int tmp;
    while(n1%n2) {
        tmp = n1;
        n1 = n2;
        n2 = tmp%n2;
    }
    return n2;
}

int main(){
    int n;
    stringstream ss;
    string s1, s2;
    int n1, n2;
    while(cin>>n) {
        for(int i=1; i<=n; i++) {
            cin >> s1 >> s2;
            n1 = b2i(s1);
            n2 = b2i(s2);
            if (gcd(n1, n2)!=1) {
                printf("Pair #%d: All you need is love!\n", i);
            }
            else {
                printf("Pair #%d: Love is not all you need!\n", i);
            }
        }
    }

    return 0;
}