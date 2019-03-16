/*
Ref: http://hanting1225.blogspot.com/2014/05/uva-12241-digits-count.html
*/
#include <iostream>
#include <string.h>
using namespace std;
void counts(int *map, int num) {
    int digit = 1; //個位數 (10位數, 100位數..)
    int save_num = num;

    // assume that the num = 325;
    while(num){ // 1: 325, 2: 32, 3: 3
        // 計算表面出現的數字內代表的意義
        for (int i=0; i<num%10; i++) { // 1. 325個位數: 320~324[1次]. 2. 325: 30x, 31x (x:0~9)[10次] 3. 325百位數 0xx, 1xx, 2xx [100次]]
            map[i] += digit;    
        }
        //1. 看個位數，5前面是32 00~09, 10~19, 20~29... 90~99, 100~109, ... 290~299, 300~309, 310~319: 0~31每個個位數都出現一次
        // 2. 看十位數，2前面是3 00x, 01x, 02x...09x, 10x, 11x,...29x (x:0~9)： 0~29: 每個後面都接x(0~9)，所以[0]~[9] += 30
        // 3. 看百位數，3前面是0 所以就沒有了（3在此回合迴圈+0個
        for (int i=0; i<10; i++){  
            map[i] += (num/10)*digit;
        }
        map[0] -= digit; // 1. 00~09 不能以鈴當開頭，所以要再把0扣回 2. 與1.同理
        map[num%10] += (save_num%digit)+1; // 1. 325，5出現一次, 2.320~325，2出現6次, 3. 300~325，3出現26次(00~25)
        digit *= 10;
        num /= 10;
    }

}

int main(){
    int a, b;
    int map[10];
    while(cin >> a>> b && a && b) {
        memset(map, 0, sizeof(map));
        counts(map, a-1);
        for (int i=0; i<10; i++)
            map[i] *= -1;
        counts(map, b);
        for (int i=0; i<10; i++) {
            if (i==9)
                cout << map[i] << endl;
            else
                cout << map[i] << " ";
        }
    }
    return 0;
}