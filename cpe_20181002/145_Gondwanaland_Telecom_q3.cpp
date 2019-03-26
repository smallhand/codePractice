/*
Ref: https://blog.csdn.net/mobius_strip/article/details/43541171
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct charge{
    char distance[2];
    float day, evening, night;
};

double cost[5][4] ={
    0.02, 0.10, 0.06, 0.02,
    0.05, 0.25, 0.15, 0.05,
    0.13, 0.53, 0.33, 0.13,
    0.17, 0.87, 0.47, 0.17,
    0.30, 1.44, 0.80, 0.30
};

int main(){
    //string dis;
    char dis[2];
    //string phone;
    char phone[9];
    int h1, m1, h2, m2;

    int interval[5] = {0, 480, 1080, 1320, 1440};
    int used[1440];
    int sum[4];
    double total;

    while(cin >> dis && dis[0]!='#' ){
        scanf("%s %d %d %d %d", phone, &h1, &m1, &h2, &m2);
        //getchar();
        int start = 60*h1+m1;
        int end = 60*h2+m2;
        memset(used, 0, sizeof(used));
        total = 0.0;

        if (end <= start) {
            for (int i=0; i<end; i++) {
                used[i] = 1;
            }
            for (int i=start; i<1440; i++) {
                used[i] = 1;
            }
        }
        else {
            for (int i=start; i<end; i++) {
                used[i] = 1;
            }
        }
        for (int i=0; i<4; i++) {
            sum[i] = 0;
            for (int j=interval[i]; j<interval[i+1]; j++) {
                sum[i] += used[j];
            }
        }
        sum[3] += sum[0];

        for (int i=1; i<=3; i++) {
            total += sum[i]*cost[dis[0]-'A'][i] ;
        }
        printf("%10s%6d%6d%6d%3s%8.2lf\n", phone, sum[1], sum[2], sum[3], dis, total);
    }
    return 0;
}