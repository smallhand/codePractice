/*
Ref: http://kos74185foracm.blogspot.com/2011/08/993-product-of-digits.html
若沒辦法被2~9的數整除 -> Q不存在
*/
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int cases;
    while(cin>>cases) {
        int n;
        int map_[10];  //只存2~9就好
        while(cases--) {
            memset(map_, 0, sizeof(map_));
            cin >> n;
            if(n==1){
                cout << 1 << endl;
                continue;
            }
            for (int i=9; i>1; i--) {
                while(n%i==0) {
                    map_[i]++;
                    n/=i;
                }
            } 
            if(n!=1) {
                cout << "-1" << endl;
                continue;
            }

            for (int i=2; i<=9; i++) {
                while(map_[i]--){
                    cout << i;
                }
            }
            cout << endl;
        }
    }
    return 0;
}