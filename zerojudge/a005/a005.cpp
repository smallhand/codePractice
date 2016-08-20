#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,e;
    int t,s;
    while(cin>>t)
    {
        for(s=1;s<=t;s++)
        {
            while(cin>>a>>b>>c>>d)
            {
                if(b-a==c-b)
                    e=2*d-c;
                else if(b/a==c/b)
                    e=d*d/c;
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
            }   
        }      
    }
return 0;
}
