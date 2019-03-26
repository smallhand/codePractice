/*
Ref: https://blog.csdn.net/mobius_strip/article/details/40455085
*/
#include <iostream>

using namespace std;

void calc(long long number) {
    if (number>=10000000) {
        calc(number/10000000);
        cout << " kuti";
        calc(number%10000000);
    }
    else {
        if (number>=100000) {
            cout << " " << number/100000 << " lakh";
        }
        number %= 100000;
        if (number >= 1000) {
            cout << " " << number/1000 << " hajar";
        }
        number %= 1000;
        if (number>=100) {
            cout << " " << number/100 << " shata";
        }
        number %= 100;
        if (number>0)
            cout << " " << number;
    }
}

int main(){
    long long number;
    int round = 1;
    while(cin >> number) {
        printf("%4d.", round++);
        calc(number);
        if (number==0)
            cout << " 0" ;
        cout << endl;
    }
    return 0;
}