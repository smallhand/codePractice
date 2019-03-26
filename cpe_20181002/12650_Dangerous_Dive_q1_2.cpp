/*
uva 12650: Dangerous Dive
2nd method: 
測資範圍小，所以可以一開始初始化arr為0
然後把讀入的id當作array的指標，存成1, eg. arr[id] =1
arr為0的，表示要被輸出，如果所有arr都為1則輸出"*"
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int n, r;
    int arr[10001];
    int tmp;
    while(cin >> n >> r) {
        memset(arr, 0, sizeof(arr));
        for (int i=0; i<r; i++) {
            cin >> tmp;
            arr[tmp] = 1;
            //cin >>  arr[i];
        }
        bool flag = true;
        for (int i=1; i<=n; i++) {
            if (arr[i]!=1)  {
                cout << i << " ";
                flag = false;
            }
        }
        if (flag)
            cout << "*";
        cout << endl;
    }
    return 0 ;
}