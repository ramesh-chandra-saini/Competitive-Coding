#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
double getAngle(double x, double y){
    double val = 180.0 / PI;
    double ret = atan2 (y,x) * val;
    if(ret<0)    ret=(360.00+ret);
    return ret;
}
int main ()
{
    while(1){
   double x, y, ret, val;

    cin >> x >> y;
    cout<<getAngle(x,y)<<endl;

}
   return(0);
}
