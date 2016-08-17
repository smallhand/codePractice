#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

int check(string );

int main(void)
{
    string s_in, ss;
    int sum,temp_sum;

    while(getline(cin,s_in)){
        istringstream temp(s_in);
        sum=0;
        while(temp){
            temp>>ss;
            temp_sum=check(ss);
            sum+=temp_sum;
        }
        cout << sum-temp_sum << endl;
    }
    return 0;
}

int check(string str){
    int in;
    istringstream s(str);

    for(int i=0; i<str.length(); i++)
        if(str[i]>57 || str[i]<48)   return 0;

    s>>in;
    return in;

}

