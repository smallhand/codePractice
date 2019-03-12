#include <iostream>
#include <string.h>

using namespace std;


int main(){
    int a, b;
    int map[10];
    while(cin >> a>> b && a && b) {
        memset(map, 0, sizeof(map));
        for (int i=a; i<=b; i++) {
            int tmp = i;
            while(tmp/10){
                map[tmp%10]++;
                tmp /= 10;
            }
            map[tmp%10]++;
        }
        for (int i=0; i<10; i++) {
            cout << map[i] << " ";
        }
        cout << endl;
    }

    return 0;
}