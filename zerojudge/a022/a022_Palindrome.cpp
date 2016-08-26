#include<iostream>
#include<cstring>

using namespace std;

int main()

{
    string n;
    while ( cin>>n )
    { int judge=1;
      for ( int i=0; i<n.size()/2; i++ )
          { if (n[i]!=n[n.size()-1-i])
               { judge=0;
                 cout << "no" << endl;
                 break;
               }
            else { judge=1;
                   continue;
                 }
          }
        if (judge==1)
            cout << "yes" << endl;
    }

}
