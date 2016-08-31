#include <iostream>
using namespace std;
int main()
{
  int a;
  while(cin>>a)
  {
      if(a==0)
      break;  
  
      for(int b=1;b<a;b++)
        if(b%7!=0)
          cout<<b<<" ";
      cout<<endl;
   }
   return 0;
}
