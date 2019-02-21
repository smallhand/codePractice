/*
Simulate the Robtics move
Date: 2019/02/20
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

// update row/column according by N,E,S,W; 2nd dimension, [0]:row, [1]:column
int movePos[4][2] = {0, 1,
                  1, 0,
                  0, -1,
                  -1, 0 };

int main() {
    int max_row , max_column;
    cin >> max_row >> max_column;

    int row, column, tmp_row, tmp_column;
    char direct;
    string face = "NESW";
    int faceIndex[128];
    faceIndex['N'] = 0;
    faceIndex['E'] = 1;
    faceIndex['S'] = 2;
    faceIndex['W'] = 3;

    bool is_outbound;
    int maps[51][51]; // record which position the robots will fall (1:fall, 0:not fall)
    memset(maps, 0, sizeof(maps));

    string in_str;
    while (cin >> row >> column >> direct) {
        getchar();
        getline(cin, in_str);

        int updateIndex = faceIndex[direct];
        tmp_row = row, tmp_column = column;
        is_outbound = false;
        for (int i=0; i<in_str.size(); i++){
            //cout << "s: " << in_str[i] << endl;
            if (in_str[i]=='F') { // Forward
                /*
                if (face[updateIndex]=='N') {
                    tmp_column =  (column+1);
                }
                */
                tmp_row = row + movePos[updateIndex][0];
                tmp_column = column + movePos[updateIndex][1];
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
                updateIndex = (updateIndex+1) % 4;
            }
            else if(in_str[i]=='L'){ // 'L'
                updateIndex = (updateIndex+3) % 4;
            }
            //printf("test: %d %d %c\n", row, column, face[updateIndex]);
        }

        printf("%d %d %c", row, column, face[updateIndex]);
        if (is_outbound) {
            cout << " LOST";
        }
        cout << endl;
    }
    return 0;
}
