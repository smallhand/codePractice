#include <iostream>
#include <cmath>
using namespace std;

int main()
{   int line;
    char ID[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int number[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    while (cin >> line){
        int sum = 0, i=0;
        int check[26];
        while (i<8){
            sum +=((int)(line/pow(10.0,8-i)))*(8-i);
            i++;
        }
        for (int i=0; i<26; i++){
            check[i] = 10 -((sum+(number[i]/10+number[i]%10*9))%10);
            if (check[i]== 10)  //check =10, check sum視為0
                check[i] =0;
            if(check[i]== line %10)
                cout << ID[i];

        }
        cout << endl;

    }

    return 0;
}
