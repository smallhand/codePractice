#include <iostream>
using namespace std;
int main()
{
     int i,j;
     while(cin>>i>>j)
     {
        
        if(i==7&&j>=30)
            cout<<"At School"<<endl;
        else if(8<=i&&i<=16)
            cout<<"At School"<<endl;
        else
            cout<<"Off School"<<endl;        
     }
return 0;
}
