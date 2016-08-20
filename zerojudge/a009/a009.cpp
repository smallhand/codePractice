#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char num[200];
    while (cin.getline(num, 200)){
        for (int i=0; i<strlen(num); i++){   //strlen：字串長度
            num[i] -= 7;
        }
        cout << num << endl;
    }
    return 0;
}
