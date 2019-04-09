/*
Dynamic Programming
每個價錢，都是由1,5,10,25, 50組合出來的

Ref: https://knightzone.studio/2014/10/04/2228/uva：357－let-me-count-the-ways/
*/
#include <iostream>
using namespace std;

int main(){

    long long dp[30005] = {1};
    int money[] = {1, 5, 10, 25, 50};

    for (int i=0; i<5; i++) {
        for (int j=money[i]; j<=30000; j++) {
            dp[j] += dp[j-money[i]];
        }
    }

    int n;
    while(cin >> n) {
        if (dp[n]==1) {
            printf("There is only 1 way to produce %d cents change.\n", n);
        }
        else {
            printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
        }
    }
    return 0;
}