#include <iostream>

using namespace std;

int main()
{
    int a;
    while (cin >>a)
    { for ( int i=a; i>=1; i--)
          { int num;
            int k=1;
            cin >> num;
            while( num/10>=0)
                 { k=k*(num%10);
                   num=num/10;
                   if (num==0) break;
                 }
             cout <<k<<endl;
          }

    }
    return 0;
}
