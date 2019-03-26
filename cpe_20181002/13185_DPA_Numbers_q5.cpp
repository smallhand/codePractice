/*
End: 12:08
*/
#include <iostream>
#include <string.h>

using namespace std;
int primes[1001];

void buildPrime(){
    int visited[1001] = {0};
    memset(primes, 0, sizeof(primes));
    int index = 0;

    for (int i=2; i<1001; i++) {
        if(!visited[i]) {
            primes[index++] = i;
            for (int j=i; j<1001; j+=i) {
                visited[j] = 1;
            }
        }
    }

}
int main(){
    //buildPrime();
    int n, test;
    int total;

    while(cin >> n) {
        while(n--) {
            cin >> test;
            total = 0;
            for (int i=2; i*i<=test ;i++) {
                if (test%i==0) {
                    total+=i;
                    if (i!=(test/i))
                        total += test/i;
                }
            }
            total+= 1;
            if (total==test) {
                cout << "perfect\n" ;
            }
            else if(total < test) {
                cout << "deficient\n";
            }
            else {
                cout << "abundant\n";
            }
        }
    }
    return 0;
}