/*
Ref: 
1. https://www.itread01.com/content/1547061127.html
2. https://codertw.com/程式語言/411726/
公式解： f(n) = (f(n-1)+m)%n
Notice: 公式解要從0開始，若題目是從1的話，最後答案再加上1即可
*/
#include <iostream>
using namespace std;

int Joseph(int n, int m) { // 遞迴
    if(n<=1 || m<=1) {
        return -1;
    }
    if (n==2) {
        if (m%2==0)
            return 0;
        else
            return 1;
    }
    else {
        return (Joseph(n-1, m)+m)%n;
        //return (Joseph(n-1, m)-1+m)%n+1;
    }
}

int Joseph_2(int n, int m) { //迭代
    int ans;
    if (n<=1 || m<=1)
        return -1;
    if (m%2==0)
        ans = 0;
    else 
        ans = 1;
    
    for (int i=3; i<=n; i++) {
        ans = (ans+m)%i;
    }
    return ans;
}

int main(){
    int n, m, last;
    while(cin >> n >> m) {
        last = Joseph_2(n, m);
        printf("the last one: %d\n", last+1);
    }

    return 0;
}