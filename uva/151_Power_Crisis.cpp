/*
f(n) = (f(n-1)+m)%n
f(1) = 0, 從0開始熄
*/
#include <iostream>
using namespace std;

int main(){
    int n, m, turnoff;
    while (cin >> n && n) {
        n = n -1; // 0~n-1
        for (m=1; m<n; m++) { //找出m
            turnoff = 0;
            for (int i=1; i<=n; i++) {
                turnoff = (turnoff+m)%i;
            }
            if (turnoff==11)
                break;
        }
        cout << m << endl;
    }
    return 0;
}