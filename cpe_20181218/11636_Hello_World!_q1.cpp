#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int line;
    int num=1;
    while(cin >> line && line>0) {
        for (int i=0; ;i++) {
            if (pow(2,i) >= line){
                printf("Case %d: %d\n", num++, i);
                break;
            }
        }
    }
    return 0;
}