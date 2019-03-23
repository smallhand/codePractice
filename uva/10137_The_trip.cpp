/*
Date: 2019/03/23
分錢：可以*100(因題目只會到小數點第二位) 變成整數後處理
全部加總取平均就是最後大家錢的金額，但有可能有些人會多或少（無法完全平分)
所以透過取餘數得到會多多少金額出來(也等於有多少人的金額比較多)
因為題目要球的是"最少"的金額交換，所以把錢由大到小排，
餘數個人只要給 $-avg-1 （少出1因為分布平均的關係)
Ref: http://kaibro.logdown.com/posts/256635-uva-10137-the-trip
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

double stu[1000];

bool cmp(int a, int b) {
    return a>b;
}

int main(){
    int num;
    while(cin >> num && num) {
        int dollar, cents;
        int avg=0, rem;
        int ans=0;
        memset(stu, 0, sizeof(stu));
        for (int i=0; i<num; i++ ){
            scanf("%d.%d", &dollar, &cents);
            stu[i] = dollar*100 + cents;
            avg += stu[i];
        }
        rem = avg%num;
        avg /= num;
        sort(stu, stu+num, cmp);
        for (int i=0; i<rem; i++) {
            ans += abs(stu[i] - (avg+1));
        }
        for (int i=rem; i<num; i++) {
            ans += abs(stu[i] - avg);
        }
        printf("$%.2lf\n", ans/200.0);
    }
    return 0;
}