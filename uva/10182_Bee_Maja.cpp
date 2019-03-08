/*
找規律，暴力解
*/

#include <iostream>

using namespace std;
#define SIZE 100000

struct point{
    int x,y;
};

point p[SIZE];

void build(){
    p[1].x = 0, p[1].y=0;
    int index=2;
    int update_x=0, update_y=0, count, num;

    for (num=1; index<=SIZE; num++) {
        for (count=0; count<num && index<=SIZE; count++, index++) {// down
            p[index].x = update_x;
            p[index].y = ++update_y;
        }
        for (count=0; count<num-1 && index<=SIZE; count++, index++) { // 左下，一開始沒有
            p[index].x = --update_x;
            p[index].y = ++update_y;
        }
        for (count=0; count<num && index<=SIZE; count++, index++) { // 左上
            p[index].x = --update_x;
            p[index].y = update_y;
        }
        for (count=0; count<num && index<=SIZE; count++, index++) { //上
            p[index].x = update_x;
            p[index].y = --update_y;
        }
        for (count=0; count<num && index<=SIZE; count++, index++) { //右上
            p[index].x = ++update_x;
            p[index].y = --update_y;
        }
        for (count=0; count<num && index<=SIZE; count++, index++) { //右下
            p[index].x = ++update_x;
            p[index].y = update_y;
        }
    }
}

int main(){
    build();
    int n;
    while(cin>>n) {
        cout << p[n].x << " " << p[n].y << endl;
    }
}