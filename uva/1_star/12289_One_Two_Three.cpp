/*
Date: 2019/03/31
依鍵盤順位建立array arr, arr[c]存shift2位的字元
*/
#include <iostream>
using namespace std;

int main(){
    int num;
    string in_str;
    int one;
    while (cin >> num) {
        while(num--) {
            cin >> in_str;
            one =0;
            if (in_str.size()==5){
                cout << "3" << endl;
                continue;
            }
            if (in_str[0] == 'o') one++;
            if (in_str[1] == 'n') one++;
            if (in_str[2] == 'e') one++;
            if (one>=2)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }

    return 0;
}