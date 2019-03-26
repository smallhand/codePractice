#include <iostream>

using namespace std;

int main(){
    int start, f, s, t;
    int total;
    while(cin>>start >> f >> s >> t && (f||s||t)) {
        total = 0;
        if(f>start) {
            total += start+40-f;
        }
        else {
            total += start-f;
        }
        //cout << "1: " << total << endl;

        if (f > s) {
            total += s+40-f;
        }
        else {
            total += s-f;
        }
        //cout << "2: " << total << endl;

        if (t>s) {
            total += s+40-t;
        }
        else {
            total+= s-t;
        }
        //cout << "3: " << total << endl;
        total = total*9+1080;
        cout << total << endl;
    }
    return 0;
}