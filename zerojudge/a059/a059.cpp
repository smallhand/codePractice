// sqrt -> cmath

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int j,i,a,b,m;
    while(cin>>i)
    {
         for(j=1;j<=i;j++)
         {              
              cin>>a>>b;              
              int sum=0;
              for(int i=a;i<=b;i++)
              {
                  if (ceil(sqrt(i))==floor(sqrt(i))) 
                  sum=sum+i;
              }
              cout<<"Case "<<j<<": "<<sum<<endl;              
         }
      
      }
     return 0;
}
