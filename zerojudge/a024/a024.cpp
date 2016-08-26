// GCD

#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
      while(a%b!=0)
      {
      int c=a%b;          
      a=b;
      b=c;
      }       
    cout<<b<<endl;
    }
 return 0;
}
