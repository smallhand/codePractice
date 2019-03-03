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
            int flag;
            int i;
            vector<Segment> ans;

            while(Max < M) {
                flag = -1;
                left = Max; // (0,M) -> (left,M)
                for (i=index; line[i].left<=left && i<pairs; i++) {
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

            /*
            for (int i=0; i<pairs; i++) {
                flag = -1;
                for(; i<pairs && line[i].left<=left; i++) {
                    if(line[i].right > right) {
                        right = line[i].right;
                        flag = i;
                    }
                }
                if (flag==-1) { // 所有線段右邊都沒辦法覆蓋住M
                    break; 
                }
                ans.push_back(line[flag]);
                if (right >= M) { // find the ans, can stop~
                    break;
                }
                left = right; // [0~M] -> [right, M]
                i--;
            }
            if (right<M){
                cout << "0\n";
            }
            else {
                cout << ans.size() << endl;
                for (int i=0; i<ans.size(); i++) {
                    printf("%d %d\n", ans[i].left, ans[i].right);
                }
            }
            */

            if(cases) // 連續兩outputs要多空一行
                cout <<  endl;
        }
    }

    return 0;
}