#include <iostream>
using namespace std;
int main()
{
   int i,s;
   while(cin>>i)
   {
       if(i<0)
       cout<<"-1"<<endl;
       if(i==0)
       cout<<"0"<<endl;
       if(i>0)
       cout<<"1"<<endl;
   }
   return 0;
}
