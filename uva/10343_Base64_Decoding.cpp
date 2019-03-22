#include <iostream>
#include <stdio.h>
using namespace std;
char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz\
0123456789+/=";
int main(){
    char c, pre_c;
    char input[4];
    int index[4];
    int number=0, index2Binary; // base64 index 要轉成4組6位binary(共24位)，再從24位中每3位1組輸出
    while( (scanf("%c", &c))==1 ) {
        
        int j;
        for (j=0; j<66 && c!=base64[j]; j++);
        if (j<65) { // 只處理有在base64的字元
            input[number]=c;
            index[number] = j;
            pre_c = c;
            number++;
        }
        else if (c=='#') {
            if(pre_c!='#'){ // 如果有好幾個#，只會印出一個
                cout << "#";
                pre_c = '#'; 
            }
        }

        if (number==4) {
            for (int i=0; i<4; i++) {
                if (input[i]=='=') {
                    index2Binary = index2Binary << 6; // =時做padding (移位)
                }
                else {
                    index2Binary = ((index2Binary << 6) + index[i]);
                }
            }
            printf("%c", index2Binary >> 16);
            printf("%c", index2Binary >> 8);
            printf("%c", index2Binary);
            number = 0;
            index2Binary = 0;
        }
    }
        
    return 0;
}