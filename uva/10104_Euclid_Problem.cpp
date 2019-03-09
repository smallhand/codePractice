/*
擴展歐幾里德算法
gcd(a, b) = gcd (b, a%b)
x = y'
y = x' - (a/b)y'
參考：
https://ccjou.wordpress.com/2012/11/16/利用基本列運算實現擴展歐幾里得演算法/
http://iris123321.blogspot.com/2015/07/uva-10104-euclid-problem.html
https://blog.csdn.net/a1061747415/article/details/26744509
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int x, y;

int extend_gcd(int a, int b) {
    if (b==0) {
        x=1; y=0;
        return a;
    }
    int ans = extend_gcd(b, a%b);
    int tmp = y;
    y = x - (a/b)*y;
    x = tmp;
    return ans;
}

int main() {
    int a, b;
    int d;
    while(cin >> a >> b) {
        d = extend_gcd(a, b);
        printf("%d %d %d\n", x, y, d);
    }

    return 0;
}
