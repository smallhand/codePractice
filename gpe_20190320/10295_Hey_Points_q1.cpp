/*
uva 10295: Hay Points
用Map紀錄每個單字得數值，然後再切字串
*/
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main(){
    int number, article;
    while(cin >> number >> article) {
        map<string, int> dict;
        string word;
        int value;
        while(number--) {
            cin >> word >> value;
            dict[word] = value;
        }
        string lines, tmp;
        stringstream ss;
        int total;
        while(article--) {
            total = 0;
            while(getline(cin, lines)){
                if (lines==".")
                    break;
                ss << lines;
                while(ss >> tmp){
                    if (dict.count(tmp)>0) { // 有在map裡面
                        total += dict[tmp];
                    }
                }
                ss.str("");
                ss.clear();
            }
            cout << total << endl;
        }

    }
    return 0;
}