/*
not pass
Ref: https://blog.csdn.net/mobius_strip/article/details/51261297
*/
#include <iostream>
#include <string.h>
using namespace std;
/*
2: 4,6,8,10,12,14,16,18,20,22,24,26,30
3: 9, 12,15, 18, 21, 24, 27, 30
5: 25, 30
7: 
*/
#define MAX 46340 // 題目range U<=2,147,483,647, sqrt(U)=46340
int visit[50001], primes[50001];

int buildPrime(){
    memset(visit, 0, sizeof(visit));
    int prime_count = 0;
    for (int i=2; i<MAX; i++) {
        if (!visit[i]) {
            primes[prime_count++] = i;
            for (int j=i*i; j<MAX; j+=i){
                visit[j] = 1;
            }
        }
    }
    return prime_count;
}

int plist[1000000], ans[1000000]; 
void calc(int prime_count, int low, int up) {
    memset(plist, 0, sizeof(plist));
    for (int i=0; i<prime_count; i++) {
        int s = (low-1)/primes[i] + 1;
        if (s<2) s=2;
        for (unsigned int j=s*primes[i]; j<=up; j+=primes[i]) { // j: must unsigned, up 過大
            plist[j-low] = 1;
        }
    }

    int ans_count = 0;
    for (unsigned int i=low; i<=up; i++) {
        if (i>1 && !plist[i-low]) {
            ans[ans_count++] = i;
        }
    }
    if (ans_count<2)
        cout << "There are no adjacent primes.\n";
    else {
        int max=-1, min=214783647,minlow, minup, maxlow, maxup;
        for (int i=1; i<ans_count; i++) {
            if (max<ans[i]-ans[i-1]) {
                max = ans[i]-ans[i-1];
                maxlow = ans[i-1];
                maxup = ans[i];
            }
            if (min> ans[i]-ans[i-1]) {
                min = ans[i]-ans[i-1];
                minlow = ans[i-1];
                minup = ans[i];
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", minlow, minup, maxlow, maxup);
    }
}

int main(){
    int prime_count = buildPrime();
    int low, up;
    while(cin >> low >> up) {
        calc(prime_count, low, up);
    }
    return 0;
}