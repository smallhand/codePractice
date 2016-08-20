#include <iostream>
using namespace std;
int main()
{
    int M,D;
    while(cin>>M>>D)
    { 
        int s=(M*2+D)%3; 
            if (s==0)
                cout<<"普通"<<endl;
             
            else if (s==1)                
                cout<<"吉"<<endl;
             
            else if (s==2)            
                cout<<"大吉"<<endl; 
                     
     }    
    return 0;
}
