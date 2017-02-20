#include<bits/stdc++.h>
using namespace std;
#define Point pair<int,int>
bool __compare(Point a, Point b){
   if (a.second != b.second)   return a.second < b.second;
        return a.first < b.first;
}
Point pivot;
int ccw(Point a, Point b, Point c) {
    int area = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (area > 0) return -1;
    else if (area < 0) return 1;
    return 0;
}
double sqrDist(Point a, Point b)  {
    double dfirst = a.first - b.first, dsecond = a.second - b.second;
    return dfirst * dfirst + dsecond * dsecond;
}
bool POLAR_ORDER(Point a, Point b)  {
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}
stack<Point> grahamScan(vector<Point> points, int N)    {
    stack<Point> hull; while(!hull.empty()) hull.pop();
    if (N < 3)        return hull;
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if ( __compare(points[i] , points[leastY]) ) leastY = i;
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;
    pivot = points[0];
    sort(points.begin() + 1, points.end(), POLAR_ORDER);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}
double getArea(Point A,Point B,Point C){
    double area=abs( A.first*(B.second-C.second)+B.first*(C.second-A.second)+C.first*(A.second-B.second) );
    area = (area)/(double)2.0;
    return area;
}
Point getCenter(vector<Point> point,int N){
    double n = (double) N;
    double X=0,Y=0;
    for(int i=0;i<N;i++) X+=point[i].first, Y+=point[i].second;
    return make_pair(X/n,Y/n ) ;
}
vector<Point> eset;
vector<Point> ::iterator it;

int main(){
    int T,Q,X,Y,freq,i; cin >> T;
    char c;
    while(T--){
        cin >> Q; eset.clear();
        while(Q--){
            cin >> c >> X >> Y;
            if(c=='-'){
                 for(i=0,it = eset.begin();it != eset.end();++it){
                    if(*it==make_pair(X,Y)){ eset.erase(it); break;}
                 }
            }
            else eset.push_back(make_pair(X,Y));
            //cout<<c<<" "<<first<<" "<<second<<"("<<N<<")"<<endl;
            vector<Point> points; points.clear();
            for(i=0,it = eset.begin();it != eset.end();++it){
                points.push_back(make_pair(it->first,it->second));// cout<<points[i].first<<" "<<points[i++].second<<endl;
            }
            stack<Point> hull = grahamScan(points,points.size());
            points.clear();
            for(i=0;!hull.empty();i++){
                points.push_back(hull.top());hull.pop();// printf("(%lf, %lf)\n", allPoints[i].first, allPoints[i].second);

            }
            double ans=0;
            if(points.size()>=3){
                Point center = getCenter(points,points.size());
                for(int i=1;i<points.size();i++) ans+=getArea(points[i-1],points[i],center);
                ans+=getArea(points[points.size()-1],points[0],center);
            }
            printf("%lf\n",ans);
        }
    }
    return 0;
}

