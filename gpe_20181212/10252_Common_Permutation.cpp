#include <iostream>
#include <map>
using namespace std;

int main(){

    string str1, str2;
    while(getline(cin, str1)){
        getline(cin, str2);

        map<char, int> m1, m2;
        for (int i=0; i<str1.size(); i++) {
            m1[str1[i]] += 1;
        }
        for (int j=0; j<str2.size(); j++) {
            if (m1.count(str2[j])>0) {
                m2[str2[j]] +=1;
                m1[str2[j]] -=1;
                if(m1[str2[j]]==0)
                    m1.erase(str2[j]);
            }
        }
        map<char, int>::iterator it;
        for (it=m2.begin(); it!=m2.end(); it++) {
            for (int i=0; i<it->second; i++) {
                cout << it->first;
            }
        }
        cout << endl;
    }

    return 0;
}