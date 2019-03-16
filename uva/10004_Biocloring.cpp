/*
Date: 2019/03/16
Ref: http://bruce30262.pixnet.net/blog/post/93060114-%5Bc-c%2B%2B%5D-uva-10004----bicoloring-
*/
#include <iostream>
#include <vector>
using namespace std;

#define N 200
vector<int> graph[N]; // 1<n<200
void init(){
    for (int i=0; i<N; i++)
        if (!graph[i].empty()){
            graph.clear();
        }

}

void dfs(int node){

}

int main(){
    int nodes;
    int edges;
    int color[N];
    init();
    while( cin>> nodes) {
        int n1, n2;
        cin >> edges;
        for (int i=0; i<edges; i++) {
            cin >> n1 >> n2;
            graph[n1].push_back[n2];
            graph[n2].push_back[n1];
        }
        color[0] = 1;
        dfs(o);


    }
    return 0;
}