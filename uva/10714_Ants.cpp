/*
不管有沒有碰面回頭，總時間還是一樣
Date: 2019/03/02
*/
#include <iostream>

using namespace std;

int main(){
    int cases;
    while (cin >> cases) {
        while(cases--) {
            int len, numbers;
            cin >> len >> numbers;
            int pos;
            int m, M, tmp;
            m = M = -1;
            for (int i=0; i<numbers; i++) {
                cin >> pos;
                m = max(m, min(pos, len-pos));
                M = max(M, max(pos, len-pos));
            }
            cout << m  << " " << M << endl;
            
        }
    }
    return 0;
}