/*
找中位數
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n) {
        unsigned x[n], mid, mid2;
        unsigned possible = 0;
        for (int i=0; i<n; i++) {
            cin >> x[i];
        }
        sort(x, x+n);

        mid = x[(n-1)/2];
        mid2 = x[n/2];

        int cnt = 0; 
        for (int i=0; i<n; i++) {
            if (x[i]==mid || x[i]==mid2) { // 只要satisfy A的特性就好，也就是讓絕對值得sum最小，而不是找出和A相等的input
                cnt++;
            }
        }
        possible = (mid2-mid)+1;

        printf("%d %d %d\n", mid, cnt, possible);
    }

    return 0;
}