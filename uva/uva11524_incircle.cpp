/*
Date: 03/13/2019
海龍公式: s = 三邊和/2 = (a+b+c)/2
三角形面積 = sqrt( s(s-a)(s-b)(s-c) ) = sr
想法: 先假設其中一邊是正確的(固定那一邊, n1, m1)
所以n1=km2, 實際的n2就也要乘以k倍, k = n1/m2 ->  實際n2 = (n1/m2) * n2
邊的關係求出後，但其實n1, m1 可能也是要乘上某個倍數rate才是答案
而真正的倍數可以透過面積的公式求出，用海龍公式會差rate^2倍，而底乘高會差rate倍，所以兩個相除就會得出rate
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int cases;
    double r, m1, n1, m2, n2, m3, n3;
    double a, b, c, s;
    double tmp_area, rate;
    while ( cin >> cases ) {
        while(cases--) {
            cin >>r >> m1 >> n1 >> m2 >> n2 >> m3 >> n3;
            //固定m1, n1
            n2 = (n1/m2) * n2;
            m2 = n1;

            n3 = (n2/m3) * n3;
            m3 = n2;

            a = m1+n1;
            b = m2+n2;
            c = m3+n3;

            s = (a+b+c)/2;
            tmp_area = sqrt( s*(s-a)*(s-b)*(s-c) );
            rate = s*r/tmp_area;
            printf("%.4f\n", rate*rate*tmp_area);
        }
    }
}