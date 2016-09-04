#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    int del;
    int del_x, del_y;
    double x, y;
    while (cin >> a >> b >> c >> d >> e >> f ){
        del = a*e - b*d;
        del_x = c*e - b*f;
        del_y = a*f - c*d;
        if (del!=0){
            x = (double)(del_x) / del;
            y = (double)(del_y) / del;
            cout << "x=" << fixed << setprecision(2) << x << endl;
            cout << "y=" << fixed << setprecision(2) << y << endl;
        }
        else if ((del==0)&&(del_x||del_y)!=0){
            cout << "No answer" << endl;
        }
        else if ((del&&del_x&&del_y)==0)
            cout << "Too many" << endl;
    }

    return 0;
}
