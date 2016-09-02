#include <iostream>
using namespace std;

int main()
{
    int c1, c2, c3;
    while (cin >> c1 >> c2 >> c3){
        cout << c1/c2 << "." ;
        c1%=c2;
        for (int i=1; i<=c3; i++){
            c1*=10;
            cout << c1/c2;
            c1%=c2;
        }
        cout << endl;
    }
    return 0;
}
