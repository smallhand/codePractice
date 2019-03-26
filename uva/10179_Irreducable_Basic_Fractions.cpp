/*
建質數表，找gcd等容易有超時的問題
最易處理的方法：尤拉公式: 
假設n的值數為m1, m2=> n(1-1/m1)(1-1/m2)...

Ref: 
1. http://ginwha.pixnet.net/blog/post/241244-尤拉公式的由來
2. http://natetang.tw/2017/06/30/95/

*/

#include <iostream>
#include <cmath>
using namespace std;

//#define NUM 1000000000

int prime[3401]={0};
int primeIndex = 1;
void buildPrime(){
    prime[0] = 2;
    //int index = 1;
    bool flag =true;

    for (int i=3; i*i<1000000000; i+=2) {
        for (int j=2; j*j<=i; j++) {
            if (i%j==0){
                flag = false;
                break;
            }
        }
        if (flag)
            prime[primeIndex++] = i;
        flag = true;
    }
}

int main(){
    int n;
    buildPrime();
    while(cin >> n && n ) {
        int tmp = n;
        int index = 0;
        bool flag = false;

        int ans = n;
        for (int i=0; i<primeIndex && prime[i]<=n; i++) {
            if (n%prime[i]==0) {
                while(n%prime[i]==0) {
                    n /= prime[i];
                }
                ans /= prime[i];
                ans *= (prime[i]-1);
            }
        }
        if (n!=1) {
            ans /= n;
            ans *= (n-1);
        }

        /*
        for (int i=0; i<primeIndex && prime[i]<=n; i++) {
            while(tmp%prime[i]==0) {
                tmp /= prime[i];
                flag = true;
            }
            if (flag) {
                //arr[index++] = prime[i];
                ans /= prime[i];
                ans *= (prime[i]-1);

            }
            flag = false;
        }

        if (tmp!=1) {
            ans /= tmp;
            ans *= (tmp-1);
        }
        */
        
        cout << ans << endl;
    }
    return 0;
}