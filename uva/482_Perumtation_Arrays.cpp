/*
Permutation Arrays (Output the array with the specific order)
Date: 2019/02/19, 18:06
*/
#include <iostream>
#include <string.h>
#include <sstream>

#define N 1000
using namespace std;

int main(){
    int num;
    int tmp;
    int cnt;
    int pos[N];
    string arr[N];
    while(cin>>num) {
        getchar(); // get the \n out of stdin buff
        for (int run=0; run<num; run++) {
            cnt = 0;
    
            while(1) {
                cin >> tmp;
                pos[tmp-1] = cnt++;

                if (getchar()=='\n')
                    break;
            }
            for (int i=0; i<cnt; i++)
                cin >> arr[i];
            for (int i=0; i<cnt; i++){
                cout << arr[pos[i]] << endl;
            }
            if (run!=num-1){
                cout << endl;
            }
        }
    }
}