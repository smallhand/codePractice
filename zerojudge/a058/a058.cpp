//mod

#include <iostream> 
using namespace std;
int main()
{
    int out[3]={0},m,n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
           cin>>m;
           out[m%3]++;
        }   
        
        for(int a=0;a<3;a++)
            cout<<out[a]<<" ";
        cout<<endl;
     }
     return 0;
}
