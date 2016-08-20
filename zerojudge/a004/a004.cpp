#include <iostream>
using namespace std;
int main()
{
     int i,y;
     while(cin>>y){
        i=0;
        if(!(y%4))
            i=1;
        if(!(y%100))
            i=0;
        if(!(y%400))
            i=1;

        if(i)
            cout<<"閏年"<<endl;
        else
            cout<<"平年"<<endl;
     }
     return 0;
}
