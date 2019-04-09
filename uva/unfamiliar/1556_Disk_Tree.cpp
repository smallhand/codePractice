/*
用map建每一層Disk路徑的關聯
p[0]["word"] = 4 ，1表接在他之後字的層級為4 -> p[4]["word2"] =2 // word\word2
印出的時候，map迭代時本身就會依字母順序由小到大迭代了！
*/
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

struct Tier {
    int size;
    map<string, int> path[50005];

    void init();
    void insert(string s);
    void output(int up, int down);
};

void Tier::init() {
    size = 1;
    path[0].clear();
}
void Tier::insert(string s){ // insert the tree from up to down
    int up = 0;
    string word = "";

    for (int i=0; i<s.size(); i++) {
        if (s[i]=='\\') {
            if (!path[up].count(word)) { // the key word appear in the paht[u]
                path[size].clear(); //預先幫下一個清空記憶體
                path[up][word] = size++; //word下一個的層級
            }
            up = path[up][word];  //取得word下一個的層級
            word = "";
        }
        else {
            word += s[i];
        }
    }
}

void Tier::output(int up, int down){
    map<string, int>::iterator iter;
    for (iter=path[up].begin(); iter!=path[up].end(); iter++) {
        for (int j=0; j<down; j++) 
            cout << " ";
        cout << iter->first << endl;
        output(iter->second, down+1);
    }
}

int main(){
    int n;
    string s;
    Tier tree;
    while (cin >> n &&n )  {
        tree.init();
        while(n--) {
            cin >> s;
            s += '\\';
            tree.insert(s);
        }
        tree.output(0, 0);
        cout << endl;
    }
    return 0;
}