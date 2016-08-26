#include <iostream>    //a034 二進位 
using namespace std;
int main()
{
    int i,k,r,sum,n[12];
    while(cin>>sum)
    {
        for(i=0;sum>=1;i++)
        {
            n[i]=sum%2;
            sum=sum/2; 
            r=i;              
        }  
     
       for(k=r;k>=0;k--)
       { 
       cout<<n[k];
        }         
        cout<<endl; 
    }
    return 0;
  }
