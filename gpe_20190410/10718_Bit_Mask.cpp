/*
這題直接用|暴力解會time limited
Ref: https://blog.csdn.net/mobius_strip/article/details/56485383
1. 若不考慮上下界[L,U], N取反即可
總共32bits -> 左移31bits開始比較
2. 當N位置為1的時候，M為0，但也要確保不小於L，所以前綴小於L的話，補上去讓他前綴和Ｌ一樣
3. 當N位置為0的時候，M為1，但也要確保不大於U，所以前綴小於U的話，補上去，大於的話就不管，即可確保會有於Ｕ
*/
#include <iostream>
using namespace std;

int main(){
    //long long low, up;
    //long long n, m;
    unsigned low, up, n, ans;
    while (cin >> n >> low >> up) {
        ans = 0;
        for(int i=31; i>=0; i--) {
            if( (1U<<i)&n  ) { // n的前綴有1的情況
                if( ans +(1U<<i) <=low ) { //加上，讓他前綴不小於L
                    ans =  ans + (1U<<i);
                }
            }
            else { // n的前綴有0的情況
                if ( ans+(1U<<i) <= up) {
                    ans = ans + (1U<<i);
                }

            }
        }
        cout << ans << endl;
    }
    return 0;
}