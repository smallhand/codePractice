#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define N 101

vector<int> tree[N];
int visited[N];

void init(){
    for (int i=0; i<N; i++)
        tree[i].clear();
}
int dfs(int now) {
    visited[now] = 1;
    int next;
    int depth = 0;
    
    for (int i=0; i<tree[now].size(); i++) {
        next = tree[now][i];
        if (!visited[next]){
            depth += dfs(next);
        }
    }
    return depth+1;
}

int main(){
    int cases;
    while (cin >> cases && cases) {
        init();
        int num, task;
        for (int i=1; i<=cases; i++) {
            cin >> num;
            while(num--){
                cin >> task;
                tree[i].push_back(task);
            }
        }

        int d;
        int max_d=-1, ans;
        for (int i=1; i<=cases; i++) {
            memset(visited, 0, sizeof(visited));
            d = dfs(i);
            if ( d > max_d ){
                max_d = d;
                ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}