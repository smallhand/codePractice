/*
Date: 2019/03/16
Ref: http://bruce30262.pixnet.net/blog/post/93060114-%5Bc-c%2B%2B%5D-uva-10004----bicoloring-
*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define N 200
vector<int> graph[N]; // 1<n<200
int color[N];
int visited[N];
void init(){
    for (int i=0; i<N; i++) {
        if (!graph[i].empty()){
            graph[i].clear();
        }
    }
    memset(color, 0, sizeof(color));
    memset(visited, 0, sizeof(visited));
}
int check = 0;
void dfs(int now){
    visited[now] = 1;
    int next;
    for (int i=0; i<graph[now].size(); i++) {
        next = graph[now][i];
        if (color[next]==0) { //還沒上色
            color[next] = color[now]*-1;  //下一個顏色和現在相反
        }
        if (color[next]==color[now]){ // 兩相鄰顏色相同：Not BICOLORABLE
            check ++;
            return ;
        }
        if(visited[next]==0)
            dfs(next);
    }
}

int main(){
    int nodes;
    int edges;
    while( cin>> nodes && nodes) {
        init();
        int n1, n2;
        check = 0;
        cin >> edges;
        for (int i=0; i<edges; i++) {
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        color[0] = 1;
        dfs(0);
        if ( check  ){
            cout << "NOT BICOLORABLE." << endl;
        }
        else {
            cout << "BICOLORABLE." << endl;
        }
    }
    return 0;
}