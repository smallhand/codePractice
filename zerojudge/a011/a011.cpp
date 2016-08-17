#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;



int main(){
	string str;
    while (getline(cin,str)){
        int sum=0;
        bool word=false;
        str[str.size()]='!';
        for (int i=0; i<str.size()+1; i++){
            if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122)){
                word=true;
            }
            else if(word==true){
                sum++;
                word=false;
            }
        }
        cout << sum << endl;
    }

	return 0;
}


