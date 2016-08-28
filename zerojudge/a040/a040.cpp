#include <iostream>

using namespace std;

int pow(int n, int k){  // k次方
    int num=1;
    for (int i=1; i<=k; i++){
       num = num*n;
    }
    return num;
}
int main()
{
    int num1, num2;
    while (cin >> num1 >> num2){
        int count = 0;
        for (int i=num1; i<=num2; i++){
            int k =0;  //k 位數
            int tempNum = i;
            long long int sum = 0;

            while(tempNum){
                tempNum=tempNum/10;
                k++;
            }
            tempNum = i;
            while (tempNum){
                sum += pow(tempNum%10,k);
                tempNum= tempNum/10;
            }
            if (sum == i){
                cout << i << " ";
                count ++;
            }
        }
        if (count==0) cout << "none" <<endl;
        else cout << endl;
    }
    return 0;
}
