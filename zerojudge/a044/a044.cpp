#include <iostream>
using namespace std;

int main() {
	int num;
	while (cin>>num){
		cout << num*(num*num + 5)/6 +1 << endl; //1+(n)(n平方+5)/6  
	}
	return 0;
}