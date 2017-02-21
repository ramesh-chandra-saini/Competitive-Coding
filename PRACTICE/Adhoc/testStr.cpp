#include<bits/stdc++.h>
using namespace std;
typedef struct __pt{
    int x;
    int y;
} Point;
Point make_point(int x,int y){
    Point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
vector<Point> v;
bool __cmp(Point A, Point B){
    if(A.x!=B.x)
        return A.x<B.x;
    return A.y<B.y;
}
int main(){
    int n; cin >> n;
    for(int i=0,x,y;i<n;i++){
        cin >> x >> y;
        v.push_back(make_point(x,y));
    }
    sort(v.begin(),v.end(),__cmp);
    for(int i=0;i<n;i++){
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
}
