#include <iostream>

using namespace std;

int main(){
    int num;
    string direct;
    int dice, n, w;
    while(cin >> num && num) {
        dice=1, n=2, w=3;
        int tmp;
        while(num--) {
            cin >> direct;
            if (direct=="north") {
                tmp = n;
                n = dice;
                dice = 7-tmp;
            }
            else if (direct=="south") {
                tmp = dice;
                dice = n;
                n = 7-tmp;
            }
            else if (direct=="east") {
                tmp = dice;
                dice = w;
                w = 7-tmp;
            }
            else if (direct=="west") {
                tmp = w;
                w = dice;
                dice = 7-tmp;
            }
        }
        cout <<  dice << endl;
    }
    return 0;
}