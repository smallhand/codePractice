#include <iostream>
#include <map>
#include <sstream>

using namespace std;
int main(){
    int n;
    string s, tmp;
    stringstream ss;
    while(cin>>n) {
        map<string, int> nation;
        getchar();
        while(n--){
            getline(cin, s);
            ss << s;
            ss >> tmp;
            nation[tmp] += 1;
            ss.str("");
            ss.clear();
        }

        map<string, int>::iterator it;
        for (it=nation.begin(); it!=nation.end(); it++){
            cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}