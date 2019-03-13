/*
Date: 03/13/2019
測資不大，枚舉即可，而且只要樹出任一個答案就好
*/

#include <iostream>
using namespace std;

struct coordinate{
    int x, y;
};

coordinate point[100];

int main(){
    int n;
    int flag;
    while (cin >> n && n) {
        for (int i=0; i<2*n; i++){
            cin >> point[i].x >> point[i].y;
        }
        flag=1;
        for (int a=-500; flag&&a<=500; a++) {
            for (int b=-500; flag&&b<=500; b++) {
                int left=0, right=0;
                for (int i=0; i<=2*n; i++) {
                    if ( (a*point[i].x + b*point[i].y) < 0 )
                        left += 1;
                    else if ( (a*point[i].x + b*point[i].y >0) )
                        right += 1;
                }

                if (left==n && right==n){
                    cout << a << " " << b << endl;
                    flag = 0;
                }
            }
        }
    }
    return 0;
}