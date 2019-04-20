/*
Ref: http://naivered.github.io/2016/04/23/Problem_Solving/UVa/UVa-477-Points-in-Figures-Rectangles-and-Circles/
*/
#include <iostream>
using namespace std;

#define N 10

struct Shape{
    char type;
    double x1, y1, x2, y2, r;
}shape[N];

int main(){
    char c;
    int cnt = 0;
    while((c=getchar())!='*'){
        
        shape[cnt].type = c;
        if (c=='r') {
            scanf("%lf %lf %lf %lf",
                &shape[cnt].x1, &shape[cnt].y1, &shape[cnt].x2, &shape[cnt].y2);
        }
        else {
            scanf("%lf %lf %lf", 
                &shape[cnt].x1, &shape[cnt].y1, &shape[cnt].r);
        }
        cnt++;
        getchar();
    }

    double x, y;
    int round=1;
    bool flag;
    double dis;
    while(scanf("%lf %lf", &x, &y) && x!=9999.9 && y!=9999.9) {
        flag = false;
        for (int i=0; i<cnt;i++) {
            //printf("shape: %lf %lf %lf %lf\n", shape[i].x1, shape[i].y1, shape[i].x2,shape[i].y2);
            if(shape[i].type=='r'){
                if ( (x>shape[i].x1) && (x<shape[i].x2) && (y<shape[i].y1) && (y>shape[i].y2)){
                    printf("Point %d is contained in figure %d\n", round, i+1);
                    flag = true;
                }
            }
            else{
                dis = (x-shape[i].x1)*(x-shape[i].x1) + (y-shape[i].y1)*(y-shape[i].y1);
                if (dis < shape[i].r*shape[i].r){
                    printf("Point %d is contained in figure %d\n", round, i+1);
                    flag = true;
                }
            }
        }
        if (!flag)
            printf("Point %d is not contained in any figure\n", round);
        round++;

    }

    return 0;
}