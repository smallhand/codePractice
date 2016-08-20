#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x,x1,x2,a,b,c,D;
    while(cin>>a>>b>>c)
    {
      D=b*b-4*a*c;
      if(D>0)
      {
        x1=(-b+sqrt(D))/(2*a);
        x2=(-b-sqrt(D))/(2*a);
        cout<<"Two different roots x1="<<x1<<" , x2="<<x2<<endl;
      }
      else if(D==0)
      {
        x=-b/(2*a);
        cout<<"Two same roots x="<<x<<endl;
      }
      else
        cout<<"No real root"<<endl;
      
    }
return 0;
}
