#include <iostream>
using namespace std;
int main()
{
    int i;
    while (cin>>i)
    {
       while (i--)
       {
        long long  int a,b,c;
          cin>>a>>b>>c;
          if(a==1)
          	cout<<b+c<<endl;
          else if(a==2)
          	cout<<b-c<<endl;
          else if(a==3)
          	cout<<b*c<<endl;
          else if(a==4)
          	cout<<b/c<<endl;
       }
    }
    return 0;
}
