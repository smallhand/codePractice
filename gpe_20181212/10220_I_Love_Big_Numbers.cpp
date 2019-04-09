#include <iostream>
using namespace std;

int main(){

    int mem[1001] = {1, 1};
    int num[3000] = {1}, digits=1;
    for (int i=2; i<=1000; i++) {
        for (int j=0; j<digits; j++) {
            num[j] *= i;
        }
        for (int j=0; j<digits; j++) {
            num[j+1] += num[j]/10;
            if (j+1>=digits && num[j+1]>0) digits++;

            num[j] %= 10;
            mem[i] += num[j];
        }
    }

    int n;
    while(cin>>n) {
        cout << mem[n] << endl;
    }
    return 0;
}
