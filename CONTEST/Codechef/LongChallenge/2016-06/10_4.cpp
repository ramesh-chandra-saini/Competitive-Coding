#include<bits/stdc++.h>
using namespace std;
#define Point pair<double, double>
#define x first
#define y second
multiset<Point> eset;
multiset<Point>::iterator it;
Point allPoints[1000000];
Point center;
int N=0;
#define PI 3.14159265
double getAngle(double x, double y){
    double val = 180.0 / PI;
    double ret = atan2 (y,x) * val;
    if(ret<0)    ret=(360.00+ret);
    return ret;
}
void update(char c,double x, double y){
    switch (c){
        case '-' : eset.erase(make_pair(x,y)),N--,center.x-=x,center.y-=y;break;
        case '+' : eset.insert(make_pair(x,y)),N++,center.x+=x,center.y+=y;break;
    }
}
Point getCenter(Point point,int N){
    return make_pair( (point.x)/(double)N, (point.y)/(double)N ) ;
}
void shiftAllPoints(Point CENTER, int N){
    int i=0;
    for(it = eset.begin(); it != eset.end();++it)
        allPoints[i++]=make_pair(it->first-CENTER.x,it->second-CENTER.y);
}
bool __cmp(pair<pair<double,double>,Point> A, pair<pair<double,double>,Point> B){
    if(A.first.first!=B.first.first) return A.first.first<B.first.first;
    return A.first.second<=B.first.second;
}
double getDistance(Point A,Point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
double getArea(Point A,Point B,Point C){
    cout<<"("<<A.x<<","<<A.y<<")  "<<"("<<B.x<<","<<B.y<<")  "<<"("<<C.x<<","<<C.y<<")  :: ";
    double area=abs( A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y) );
    area = (area)/(double)2.0; cout<<area<<endl;
    return area;
}
int main(){
    int T,Q,x,y,freq; cin >> T;
    char c;
    while(T--){
        cin >> Q,N=0,eset.clear(),center.x=center.y=0;
        while(Q--){
            cin >> c >> x >> y,update(c,x,y);//cout<<c<<" "<<x<<" "<<y<<"("<<N<<")"<<endl;
            double ans=0;
            if(N>=3){
                Point CENTER = getCenter(center,N); //cout<<"CENTER : ("<<CENTER.x<<" , "<<CENTER.y<<")"<<endl;
                shiftAllPoints(CENTER,N);
                vector<pair<pair<double,double>,Point> > DS;DS.clear();
                for(int i=0;i<N;i++)
                    DS.push_back(make_pair(make_pair(getAngle(allPoints[i].x,allPoints[i].y),getDistance(make_pair(0,0),allPoints[i])),make_pair(allPoints[i].x+CENTER.x,allPoints[i].y+CENTER.y)));
                sort(DS.begin(),DS.end(),__cmp);
                for(int i=0;i<N;i++) allPoints[i]=DS[i].second;
                Point prev = allPoints[0];
                for(int i=1;i<N;i++) ans+=getArea(prev,allPoints[i],CENTER),prev=allPoints[i];
                ans+=getArea(prev,allPoints[0],CENTER);

                //for(int i=0;i<N;i++) cout<<DS[i].first.first<<" "<<DS[i].first.second<<" "<<DS[i].second.first<<" "<<DS[i].second.second<<endl;
                for(int i=0;i<N;i++) cout<<"("<<allPoints[i].first<<","<<allPoints[i].second<<")  ";cout<<endl;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
