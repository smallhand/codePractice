#include <iostream>
#include <string.h>
using namespace std;
#define MAXL 1000002
int x[MAXL];
int y[MAXL];
int ans[MAXL];
int carry[MAXL];

int main(){
    int cases; 
    while (cin >> cases) {
        int num;
        while(cases){
            cin >> num;

            //memset(x, 0, sizeof(x));
            //memset(y, 0, sizeof(y));
            memset(ans, 0, sizeof(ans));
            memset(carry, 0, sizeof(carry));
            int x, y;
            int i;

            for (i=1; i<=num; i++) {
                //cin >> x[i] >> y[i];
                cin >> x >> y;
                if(x+y > 9) {
                    //carry[i+1] += (x+y)/10;
                    int tmp = i;
                    do {
                        (ans[tmp--] += (x+y)/10);
                    } while (ans[tmp--]>9);

                    ans[i-1] = ans[i-1] + (x+y)/10;
                }
                ans[i] = (x+y) % 10;
            } 
            for (int j=0; j<i; j++) {
                if (ans[j]==0 & j==0)
                    continue;
                    //cout << carry[j];
                cout << ans[j];
            }
            cout << endl ;

            if (cases)
                cout << endl;

        }
    }

    return 0;
}
/*
2

4
0 4
4 2
6 8
3 7

4
8 0
6 3
6 3
2 8
=== > 9000
*/