/*
The prime range 2~100000
Date: 2019/02/21
*/
#include <iostream>
using namespace std;

#define N 100000

int primes[N]={0}; // assume 0 is prime

void fillPrime(){
    primes[0] = 1;
    primes[1] = 1;

    for (int i=2; i<N; i++) {
        if (primes[i]==1) continue;

        for (int j=i+i; j<N; j+=i) {
            primes[j] = 1;
        }
    }
}

int main(){
    fillPrime();
    string in_str;
    while(cin>>in_str) {
        if (in_str=="0") break;
        int max_prime = 0;
        for (int i=0; i<in_str.size(); i++){
            int tmp=0;
            for (int j=i; j<in_str.size(); j++) {
                tmp = tmp*10+(in_str[j]-'0');
                if (tmp>N) break;
                if (!primes[tmp]) {
                    if (tmp > max_prime) {
                        max_prime = tmp;
                    }
                }
            }
        }
        printf("%d\n", max_prime);
    }
}