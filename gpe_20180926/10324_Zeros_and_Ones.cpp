#include <iostream>

using namespace std;

int main(){
    string s;
    int cnt = 1;
    while( cin >> s ){
        printf("Case %d:\n", cnt++);
        int n;
        cin >> n; 
        int i, j, min_, max_;
        while(n--) {
            cin >> i >> j;
            min_ = min(i, j);
            max_ = max(i, j);
            
            int tmp = s[min_], flag=0;
            for (int k=min_+1; k<=max_; k++) {
                if(tmp!=s[k])
                    flag = 1; 
            }
            if (flag) {
                cout << "No\n";
            }
            else 
                cout << "Yes\n";
        }
    }

    return 0;
}