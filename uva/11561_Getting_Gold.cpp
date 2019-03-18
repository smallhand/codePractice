/*
Date: 2019/03/17
位置分為現在(牆壁,超界,黃金)、下一步(陷阱、超界)
*/
#include <iostream>
#include <string.h>
 
using namespace std;
#define MAX_NUM 52
char graph[MAX_NUM][MAX_NUM];

int go_xy[4][2] = {
    0, 1, // 右
    1, 0, // 下
    0, -1, // 左
    -1, 0 // 上
};

bool in_bound(int i, int j, int row, int col){
    if (i<0 || i>=row || j<0 || j>=col)
        return false;
    return true;
}
 
int dfs(int x, int y, int row, int col) {
    int sum = 0;
     
    // 現在位置為牆 或 超出邊界-> 停下來
    if (!in_bound(x, y, row, col) || graph[x][y]=='#' ){
        return sum;
    }

    // 現在位置有黃金 -> 撿起來(+1), 現在位置已走過，就不用再拜訪了(設為牆壁即可)
    if (graph[x][y]=='G')
        sum+=1;
    graph[x][y] = '#';

    // '下一步'遇到陷阱 -> 停下來
    bool stop = false;
    for (int i=0; i<4; i++) {
        if (graph[x+go_xy[i][0]][y+go_xy[i][1]]=='T' &&
            in_bound(x+go_xy[i][0], y+go_xy[i][1], row, col)){
                stop = true;
                break;
            }
    }
    if (stop)
        return sum;

    // 下一步不會遇到陷阱 -> 就走下去
    for (int i=0; i<4; i++) {
        sum += dfs(x+go_xy[i][0], y+go_xy[i][1], row, col);
    }
    return sum;
}


int main() {
    int col, row;
    while (cin >> col >> row) {
        memset(graph, 0, sizeof(graph));
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++)
                cin >> graph[i][j];
        }

        // find the start('P') position
        bool stop = false;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (graph[i][j]=='P') {
                    cout << dfs(i, j, row, col) << endl;
                    stop = true;
                    break;
                }
            }
            if (stop)
                break;
        }
    }
    return 0;
}

/*
7 4
#######
#P.GTG#
#..TGG#
#######

8 6
########
#...GTG#
#..PG.G#
#...G#G#
#..TG.G#
########
*/