#include <iostream>
using namespace std;
int main()
{
    int m,n,i,j;
    while(cin>>i>>j)
    {
       int T[i][j];
       for(m=0;m<i;m++){
        for(n=0;n<j;n++)      
          cin>>T[m][n];
       }
       for(m=0;m<j;m++){
        for(n=0;n<i;n++)
          cout<<T[n][m]<<" ";
        cout<<endl;
       } 
     
    }
    return 0;
}
