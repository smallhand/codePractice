#include <iostream>

using namespace std;

int main()
{  int n,m;
    while (cin >> n >> m)
    {

      int sum=0;
      int countNum=0;
      for ( int i=n; ; i++ )
             { sum+=i;
                countNum ++;
                if (sum>m)
                     break;
             }
             cout << countNum << endl;
    }

    return 0;
}
