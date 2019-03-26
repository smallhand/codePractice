/*
uva 12650: Dangerous Dive
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int n, r;
    int arr[10000];
    while(cin >> n >> r) {
        memset(arr, 0, sizeof(arr));
        for (int i=0; i<r; i++) {
            cin >>  arr[i];
        }
        sort(arr, arr+r);
        bool flag=false;
        for (int i=0, cnt=1; cnt<=n; cnt++) {
            if (cnt!=arr[i]){
                cout << cnt << " ";
                flag = true;
            }
            else {
                if (i<r)
                    i++;
            }
        }
        if (!flag){
            cout << "*\n";
        }
        else {
            cout << endl;
        }
    }

    return 0 ;
}