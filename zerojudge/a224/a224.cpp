#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s){
        int len=s.length();
        int check = 0, check2=0, count =0;
        int store[26]={0};
        for (int i=0; i<len; i++){  //大寫轉成小寫
            if (s[i]>=65&&s[i]<=90) s[i]-=65;
            if (s[i]>=97&&s[i]<=122) s[i]-=97;
            store[s[i]]++;
        }
        if (len%2){ //奇數長度
            for (int i=0; i<26; i++){
                if (store[i]%2==0)  continue;
                else check2 ++ ;
            }
            if (check2 ==0 || check2==1) cout << "yes !" << endl;
            else cout << "no..." << endl;
        }
        else {
            for (int i=0; i<26; i++){
                if(store[i]%2){
                    check = 0;
                    break;
                }
                else check =1;
            }
            if (check==1) cout << "yes !" << endl;
            else if (check==0)cout << "no..." << endl;
        }
    }
    return 0;
}
