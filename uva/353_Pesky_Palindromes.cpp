/* 
Pesky Palindromes (count # of palindomes in a word)
Date: 2019/02/19
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isPal(string str){
    for (int i=0; i<str.length()/2; i++) {
        if (toupper(str[i]) != toupper(str[str.length()-1-i])) {
            return false;
        }
    }
    return true;
}

int countN2(string str_in){
    vector<string> palList;
    for (int len=1; len<str_in.length()+1; len++) {
        for (int i=0; i < str_in.length()+1-len; i++ ){
            // if the substring isn't in the palList, and it is palindromes, then push into the palList
            if (find(palList.begin(), palList.end(), str_in.substr(i, len)) == palList.end() && isPal(str_in.substr(i, len))) { // substr: the ith postion, and str length=len
                palList.push_back(str_in.substr(i, len));
            }
        }
    }
    return palList.size();
}

int countN(string str_in ) {
    vector<string> palList;
    for (int i=0; i<str_in.size(); i++) {
        for (int len=1; len<=str_in.size()-i; len++) {
            if (isPal(str_in.substr(i,len)) && find(palList.begin(), palList.end(), str_in.substr(i, len))==palList.end() ) {
                palList.push_back(str_in.substr(i, len));
            }
        }
    }
    return palList.size();
}

int main(){
    string str_in="";
    while (cin >> str_in){
        int numbers = countN(str_in);
        printf("The string '%s' contains %d palindromes.\n", str_in.c_str(), numbers);
    }
}

