/*
若總和不是2的倍數就一定不能分
總和/2後，即是0 1 背包問題: sum /= 2
一開始一定能放物品進去(dp[0]=true)
接著2個迴圈分別代表
1. i: 掃1~n個物品 (i)
2. j:由sum開始往回推到item[i]，如果dp[j-item[i]] = true
    dp[j] ＝ true （代表由i衍伸出的j可以被放入)

Ref:https://www.youtube.com/watch?v=6VtWsq8cESQ&t=2507s
*/

#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int cases;
    while(cin >> cases) {
        getchar();
        while(cases--) {
            string in_str;
            int number[21]={0};
            int dp[201]={0};
            int index=0, sum=0;

            stringstream ss;
            getline(cin, in_str);
            ss << in_str;
            while(ss >> number[index]) {
                sum += number[index++];
            }
            if (sum%2) { // 不能平分的話, 就直接輸出不行！
                cout << "NO\n" ;
                continue;
            }
            sum /= 2;
            dp[0] = 1;
            for (int i=0; i<index; i++) {
                for (int j=sum; j>=number[i]; j--) {
                    if (dp[j-number[i]]) {
                        dp[j] = 1;
                        //cout << "J: " << j<< endl;
                    }
                }
            }
            if (dp[sum]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}