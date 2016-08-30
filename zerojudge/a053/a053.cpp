#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a)
    {
      if(a<11)
      b=a*6; 
      
      else if(a<21)
      b=60+(a-10)*2;
      
      else if(a<41)
      b=80+(a-20);
      
      else 
      b=100;
      
      cout<<b<<endl;
    }
    return 0;
}
