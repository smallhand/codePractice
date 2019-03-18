/*
Date: 2019/03/18
進制轉換, sstream, %x:16進, %o:8進
https://openhome.cc/Gossip/CGossip/PrintfScanf.html
*/
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string s;
    int num;
    while (cin >> s && s[0]!='-') {
        stringstream ss;
        ss.str(s);

        if(s[1]=='x') {
            ss >> hex >> num;
            printf("%d\n", num);
        }
        else {
            ss >> dec >> num;
            printf("0x%X\n", num); // %X大寫，%x小寫
        }
    }
    return 0;
}