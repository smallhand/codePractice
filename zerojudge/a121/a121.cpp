/*Prime number
notice!! may be TTE
*/
#include <iostream>
#include <cmath>
using namespace std;

int judgePrime(long unsigned num){
    if (num==1) return 0;
    if (num==2) return 1;
    else if (num%2==0) return 0;  //even
    else {
        for (unsigned i=3; i<=sqrt(num); i++){
            if (num%i==0) return 0;
        }
        return 1;
    }
}

int main()
{
    unsigned long num1, num2;
    while(cin >> num1 >> num2){
        int total=0;
        for (unsigned long i=num1; i<=num2; i++){
            if (judgePrime(i))  total++;
        }
       cout << total << endl;

    }
    return 0;
}
