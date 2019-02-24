/*
先兩兩相比找出最大的出來: 需n-1次
再去找比最大數小的那些數，繼續兩兩相比: log2(n)-1，取上界
Date: 2019/02/22
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int num;
    while(cin >> num) {
        int times = (num-1) + (ceil(log2(num))-1);
        cout << times << endl;
    }
}