/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
double zero=(double)0;
double getArea(double x1,double y1,double x2,double y2,double x3,double y3){
    return 0.5*abs((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1));
}
bool checkBoundryCondition(double x1,double y1,double x2,double y2,double x3,double y3){
    return (getArea(x1,y1,x2,y2,zero,zero)==zero)||(getArea(zero,zero,x2,y2,x3,y3)==zero)||(getArea(x1,y1,zero,zero,x3,y3)==zero);
}
bool inSide(double x1,double y1,double x2,double y2,double x3,double y3){
    return !checkBoundryCondition(x1,y1,x2,y2,x3,y3)&&
            (getArea(x1,y1,x2,y2,x3,y3)==getArea(x1,y1,x2,y2,zero,zero)+getArea(zero,zero,x2,y2,x3,y3)+getArea(x1,y1,zero,zero,x3,y3));
}
int main(){
    vector<pair<double,double> > points(1000000);
    int t,ans=0,n=0; scanf("%d",&t); while(t--){ n++;
        int x,y; scanf("%d%d",&x,&y);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans+=(inSide(points[i].first,points[i].second,points[j].first,points[j].second,double(x),double(y)));
            }
        }points[n-1]=(make_pair((double)x,double(y)));
        printf("%d\n",ans);
    }
}
