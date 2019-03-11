/*
LCS(longest common string)
Notice: 一開始給的序列只是每個歷史發生的順序，但實際要比較的是依順序排列的歷史事件
        作法如同uva_482
*/
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int cases;
    int LCS[25][25] = {0};
    cin >> cases; 
    int ans[cases+1], stud[cases+1];
    int pos;
    memset(ans, 0, sizeof(ans));
    memset(stud, 0, sizeof(stud));
    for (int i=1; i<cases+1; i++) {
        cin >> pos;
        ans[pos] = i;
    }

    while(scanf("%d", &pos)!=EOF) {
    //while(!cin.eof()) {
        int index = 1;
        stud[pos] = index++;
        for (int i=1; i<cases; i++) {
            cin >> pos;
            stud[pos] = index++;
        }

        // LCS
        for (int i=1; i<=cases; i++) {
            for (int j=1; j<=cases; j++){
                if (ans[i]==stud[j]) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                else{
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                }
            }
        }
        cout << LCS[cases][cases] << endl;
    }
    return 0;
}