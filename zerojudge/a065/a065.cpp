#include <iostream>
using namespace std;

int main()
{
    char num[7];
    int result[7];
    int ans;
    while(cin>>num){
        for(int i=0; i<7; i++){
            result[i]=num[i]-64;
        }
        for(int i=0; i<6; i++){
            ans = result[i]-result[i+1];
            if (ans>=0)
                cout << ans ;
            else
                cout << ans*(-1);
        }
        cout << endl;
    }
    return 0;
}
