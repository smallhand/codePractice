#include <iostream>

using namespace std;

int main()
{
    int n;
    while ( cin>> n )
      { int N[n];
        for ( int i=0; i<n; i++ )
          { cin >> N[i];
          }
        //int mim=N[0];
        int min;
        for ( int i=0; i<n-1; i++ ) //selection sort
          { int k; 
            min=N[i];
            for ( int j=i+1; j<n; j++ )
              { if (N[j]< min)
                { k=j;
                  min=N[j];
                }
              }
            if (min<N[i])
              { N[k]=N[i];
                N[i]=min;                  
              }
          }
        for ( int i=0; i<n; i++ )
          { cout <<N[i] << " ";
          }
          cout <<endl;
      }
    return 0;
}
