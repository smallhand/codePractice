#include <iostream>
using namespace std;

int main()
{
    char ID[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int number[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    int num;
    char c;
    while (cin >> c >> num){
        int sum=0;
        int index =0;
        sum += num%10;
        num /=10;
        for (int i=1; i<=8; i++){
            sum += num%10*i;
            num /= 10;
        }
        for (int i=0; i<26; i++){
            if(c==ID[i]){
                index=i;
                break;
            }
        }
        sum +=  number[index]%10*9 + number[index]/10;
        if (sum%10) cout << "fake" << endl;
        else cout << "real" << endl;
    }
    return 0;
}
