/*
Date: 2019/03/03
Greedy
1. 左界由小到大排序
2. 選左界小於目前目標的左界範圍，然後右界最大的
3. 直到右界最大也比目標的左界小(沒線段符合，輸出0)，或是右界已經可以完全涵蓋(有線段符合)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment{
    int left;
    int right;
};

bool cmp(Segment begin, Segment end){
    if (begin.left < end.left) return true;
    return false;
}

int main(){
    int cases;
    while (cin >> cases) {
        int M;
        Segment line[100001];
        int pairs;
        while(cases--) {
            pairs = 0;
            cin >> M;
            while(cin >> line[pairs].left >> line[pairs].right) {
                if (!line[pairs].left  && !line[pairs].right) {
                    break;
                }
                pairs++;
            }
            sort(line, line+pairs, cmp);

            int left = 0;
            int index = 0, Max=0;
            int i, flag;
            vector<Segment> ans;

            while(Max < M) {
                flag = -1;
                left = Max; // (0,M) -> (left,M)
                //for (i=index; line[i].left<=left && i<pairs; i++) {
                for (i=index; i<pairs; i++) {
                    if (line[i].left>left)
                        break;
                    if (line[i].right > Max) {
                        Max = line[i].right;
                        flag = i;
                    }
                }
                if (flag==-1) // 所有線段右邊都沒辦法覆蓋住M, or 所有線段的左邊無法覆蓋住0
                    break; 
                ans.push_back(line[flag]);
                index = i;
            }

            if (Max < M)
                cout << "0" << endl;
            else {
                cout << ans.size() << endl;
                for (int i=0; i<ans.size(); i++) {
                    printf("%d %d\n", ans[i].left, ans[i].right);
                }
            }

            if(cases) // 連續兩outputs要多空一行
                cout <<  endl;
        }
    }

    return 0;
}