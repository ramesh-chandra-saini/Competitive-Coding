#include<bits/stdc++.h>
using namespace std;
double pi=3.14159265 ; //3589793238462643383279502884197169399375105820974944592307816406286 ;
#define Point pair<double,double>
#define x first
#define y second
double X[100005],Y[100005];
Point points[100005];
multiset<Point> eset;
multiset<Point> :: iterator it;
int N=0;
double getArea(Point A,Point B,Point C){
    double area=abs( A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y) );
    area = (area)/(double)2.0;
    return area;
}

double getDistance(Point A,Point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
double getDirectAngle(Point A,Point B,Point C){
     val = 180.0 / pi;
    double a1=atan2 (A.y-C.y,A.x-C.x)*val;
    double a2=atan2 (B.y-C.y,B.x-C.x)*val;
    double angle=a1-a2;
    if (angle < (double)0) angle = angle + (double)360;
    return angle;
}
bool __cmp( pair<pair<double, double>,Point> A,  pair<pair<double, double>,Point> B){
    if(A.first.first!=B.first.first) return A.first.first>B.first.first;
    return A.first.second>=B.first.second;
}
int main(){

    int T,Q,x,y,freq; cin >> T;
    char c;
    Point center;
    while(T--){
        cin >> Q ; N=0; eset.clear();
        while(Q--){
            cin >> c >> x >> y;
            Point Pair=make_pair(x,y);
            if(c=='+') eset.insert(Pair),center.x+=Pair.x,center.y+=Pair.y,N++;
            else eset.erase(Pair),center.x-=Pair.x,center.y-=Pair.y,N--;
            double ans=0;
            if(N>=3){
                Point C=make_pair(center.x/(double)N,center.y/(double)N);
                vector <pair<pair<double, double>,Point> > DS;// vector <pair<pair<Slope/Angle, distance>,Point> >
                Point Fixed = *eset.begin();
                for(it=eset.begin();it!=eset.end();++it){
                    DS.push_back(make_pair(make_pair(getDirectAngle(Fixed,*it,C),getDistance(*it,C)),*it));
                }
               sort(DS.begin(),DS.end(),__cmp);
               Point prev=*eset.begin();
                for(it=eset.begin();it!=eset.end();++it){
                    ans+=getArea(prev,*it,C);
                    prev=*it;
                }
                ans+=getArea(prev,*eset.begin(),C);
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
