/*
題意：給一字串，求該字串是由幾個最小循環節組成的
*/
#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
 
const int N = 1000005;
 
 
int main () {
    string s;
    while(cin>>s && s!=".") {
        int ans = 1;
        int len_ = s.size();
        bool flag;

        for (int i=1; i<len_; i++) { // 多少個字一組
            if (len_%i==0) {
                flag =true;
                for (int j=i; j<len_; j++) { // 組和前一組相對應的位置比較
                    if (s[j]!=s[j%i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = len_/i;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
	return 0;
}