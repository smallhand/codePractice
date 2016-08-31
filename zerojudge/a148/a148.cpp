//calcuatle avg.

#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num){
        double score;
        double sum = 0;
        for (int i=0; i<num; i++){
            cin >> score;
            sum += score;
        }
        if (sum/num>59) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
