/*
1. 得到一個點p的位置
2. 累積到這個點的distance
3. mark this pos #
4. then push the p into queue -> 即將走訪這個點
5. 開始走訪: pop
*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define N 32

char dungeon[N][N][N];
int Distance[N][N][N];
const int direct[6][3] = { // 下/上樓, 東/西, 南/北
    -1, 0, 0, 
    1, 0, 0,   
    0, -1, 0,
    0, 1, 0,
    0, 0, -1,
    0, 0, 1
};

struct point{
    int x, y, z;
};

int bfs(int i, int j, int k, int bl, int br, int bc){
    Distance[i][j][k] = 0;
    queue<point> q;
    //q.push(point{i,j,k});
    point P;
    P.x = i, P.y =j, P.z =k;
    q.push(P);

    dungeon[i][j][k] = '#';

    point cur, nxt;
    while(!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i=0; i<6; i++) {
            nxt.x = cur.x + direct[i][0];
            nxt.y = cur.y + direct[i][1];
            nxt.z = cur.z + direct[i][2];

            if (nxt.x<0 || nxt.x>=bl || nxt.y <0 || nxt.y>=br || nxt.z<0 || nxt.z>=bc)
                continue;
            
            if (dungeon[nxt.x][nxt.y][nxt.z] != '#') {
                Distance[nxt.x][nxt.y][nxt.z] = Distance[cur.x][cur.y][cur.z] + 1;
                if (dungeon[nxt.x][nxt.y][nxt.z]=='E')
                    return Distance[nxt.x][nxt.y][nxt.z];
                dungeon[nxt.x][nxt.y][nxt.z] = '#';
                q.push(nxt);
            }
        }
    }

    return 0;
}
int main(){
    int level, row, column;
    int minute;

    while(cin>>level >> row >> column) {
        if (level==0 && row==0 && column==0) break;
        memset(dungeon, 0, sizeof(dungeon));
        memset(Distance, 0, sizeof(Distance));

        getchar();
        int si, sj, sk; // start

        for (int i=0; i<level; i++) {
            for (int j=0; j<row; j++) {
                scanf("%s", dungeon[i][j]);
                for (int k=0; k<column; k++) {
                    if (dungeon[i][j][k]=='S') {
                        si = i;
                        sj = j;
                        sk = k;
                    }
                }
            }
        }

        minute = bfs(si, sj, sk, level, row, column);

        if (minute)
            printf("Escaped in %d minute(s).\n", minute);
        else {
            cout << "Trapped!\n";
        }
    }

    return 0;
}

/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E
*/