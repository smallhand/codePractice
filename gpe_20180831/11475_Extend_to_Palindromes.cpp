/*
網路上查到的都用kmp 演算法
但迴圈暴力解，並有適當的終止條件，其實也還是能避面逾時
目標: 找到string s 的後綴 == reverse(s), r的前綴 
for i: 0~s.size
for j: 0~r.size-i
只要s[i]!=r[j] 立刻i++
相等時，只要比到r.size-i 就結束 (找到相等的前後綴！)
*/
#include <iostream>
#include <cstring>
#include <algorithm> // reverse
using namespace std;

int main(){
    string s, r;
    while(cin >> s) {
        r = s;
        reverse(r.begin(), r.end());

        int cnt = 0, max_=-1, tmp;
        bool find = false;
        for (int i=0; i<s.size(); i++) {
            tmp = i;
            for (int j=0; j<r.size()-i; j++ ) {
                if(s[tmp]!=r[j]) {
                    max_ = max(cnt, max_);
                    cnt = 0;
                    break;
                }
                else {
                    cnt++;
                    tmp++;
                    if (j==r.size()-i-1) {
                        find = true;
                    }
                }
            }
            if (find)
                break;
        }
        cout << s;
        for (int j=cnt; j<r.size(); j++) {
            cout << r[j] ;
        }
        cout << endl;
    }
    return 0;
}