/*
1. Digit Mapping: 0~9
2. No matter how many digits, %10, /10 until num/10==0
3. Get digit from num%10, and then count the map
Date: 2019/02/28
*/
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int num;
    while (cin >> num) {
        int map[10];
        int data;
        while(num--){
            memset(map, 0, sizeof(map));

            int n;
            cin >> data;
            for (int i=1; i<=data; i++) {
                int tmp = i;
                while(tmp/10) {
                    n = tmp%10;
                    map[n]++;
                    tmp /= 10;
                }
                map[tmp%10]++;
            }

            for (int i=0; i<10; i++) {
                if (i==9)
                    cout << map[i];
                else {
                    cout << map[i] << " ";
                }
            }
            cout << endl;
            
        }
    }
    return 0;
}