#include <iostream>
using namespace std;
void p(int num,int a[])
{
    int ten=1;
    int temp=num;
    while(num)
    {
        for(int i=0;i<num%10;i++)
        {
            a[i]+=ten;
        }
        for(int i=0;i<10;i++)
        {
            a[i]+=ten*(num/10);
        }
        a[0]-=ten;
        a[num%10]+=(temp%ten)+1;
        ten*=10;
        num/=10;
    }
}
int main()
{
    int a,b;
    while(cin>>a>>b && a+b)
    {
        int Num[10]={0};
        p(a-1,Num); /*計算0到a的0~9個有幾個*/
        for(int i=0;i<10;i++) Num[i]*=-1;   /* 所求= 0~b - 0~(a-1) */
        p(b,Num);   /*計算0到b的0~9個有幾個*/
        for(int i=0;i<10;i++)
        {
            cout<<Num[i]<<(i==9 ? '\n': ' ');
        }
    }
    return 0;
}