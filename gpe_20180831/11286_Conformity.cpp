#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    long long record;
    while(cin >> n && n){
        map<long long, int> cnt_map;
        int course[5];
        int max_=-1;
        while(n--) {
            record = 0;
            for (int i=0; i<5; i++) {
                cin >> course[i];
            }
            sort(course, course+5);
            for (int i=0; i<5; i++) {
                record += course[i];
                record *= 1000;
            }
            record /= 1000;
            cnt_map[record] +=1;
            max_ = max(max_, cnt_map[record]);
        }
        int cnt=0;
        map<long long, int>::iterator it;
        for (it=cnt_map.begin(); it!=cnt_map.end(); it++){
            if (it->second == max_) {
                cnt += it->second;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}