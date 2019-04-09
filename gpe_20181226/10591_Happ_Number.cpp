#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int calc(int n){
    int ans =0, tmp, save=n;
    while(n/10) {
        tmp = n%10;
        ans += tmp*tmp;
        n/=10;
    }
    ans += n*n;
    if (ans<10)
        return ans;
    else 
        return calc(ans);
}

int main(){
    int cases;
    int count;
    int n, ans;
    while (cin >> cases) {
        count = 1;
        while (cases--){
            cin >> n;
            ans = calc(n);
            if (ans==1)
                printf("Case #%d: %d is a Happy number.\n", count, n);
            else 
                printf("Case #%d: %d is an Unhappy number.\n", count, n);
            count++;
        }
    }
    return 0;
}