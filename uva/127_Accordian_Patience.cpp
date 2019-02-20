/*
Simulate the Robtics move
Date: 2019/02/20
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int max_row , max_column;
    cin >> max_row >> max_column;

    int row, column;
    int tmp_row, tmp_column;
    char direct;
    bool is_outbound = false;
    int maps[51][51];
    memset(maps, 0, sizeof(maps));
    string in_str;
    while (cin >> row >> column >> direct) {
        getchar();
        getline(cin, in_str);
        tmp_row = row, tmp_column = column;
        is_outbound = false;
        for (int i=0; i<in_str.size(); i++){
            cout << "s: " << in_str[i] << endl;
            if (in_str[i]=='F') { // Forward
                if (direct=='N') {
                    tmp_column =  (column+1);
                }
                else if(direct=='E'){
                    tmp_row = (row+1);
                }
                else if (direct=='S'){
                    tmp_column =  (column-1);
                }
                else {
                    tmp_row = (row-1);
                }
                //printf("%d %d %d %d\n", tmp_row, tmp_column, max_row, max_column);

                if (tmp_row<0 || tmp_row>max_row || tmp_column<0 || tmp_column>max_column) {
                    if (maps[row][column]){ // if some robots have fallen at this point, then the robot do not execute the same order
                        tmp_row = row;
                        tmp_column = column;
                        continue;
                    }
                    maps[row][column] = 1;
                    is_outbound = true;
                    break;
                }
                row = tmp_row;
                column = tmp_column;
            }
            else if(in_str[i]=='R') {
                if (direct=='N') {
                    direct = 'E';
                }
                else if (direct=='E') {
                    direct = 'S';
                }
                else if (direct=='S'){
                    direct = 'W';
                }
                else {
                    direct = 'N';
                }
            }
            else { // 'L'
                if (direct=='N'){
                    direct = 'W';
                }
                else if (direct=='W'){
                    direct = 'S';
                }
                else if (direct=='S'){
                    direct = 'E';
                }
                else {
                    direct = 'N';
                }
            }
            //printf("test: %d %d %c\n", row, column, direct);
        }

        printf("%d %d %c", row, column, direct);
        if (is_outbound) {
            cout << " LOST";
        }
        cout << endl;
    }
    return 0;
}
