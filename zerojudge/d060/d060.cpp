#include <iostream>
using namespace std;
int main()
{
	int i,j;
	while(cin>>i)
	{ 
		if(i<=25)
			j=25-i;
		if(i>=26)
			j=85-i;
		cout<<j<<endl;
	}
	return 0;
}