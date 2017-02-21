#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define ld long double
#define point pair<ld,ld>
void print(set<pair<ld,point> > cir){
    set<pair<ld,point> >::iterator it;
     for(it=cir.begin();it!=cir.end();++it){
        ld R = it->first;
        point center = it->second;
        cout<<R<<" ["<<center.x<<" "<<center.y<<"]"<<endl;
    }
    cout<<endl;
}
ld dis(point A, point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
ld solve2Point(vector<point>plane,ll N,ll M,ld ans){
    set<pair<ld,point> > cir2;
    set<pair<ld,point> >::iterator it;
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            ld x1=plane[i].x,y1=plane[i].y;
            ld x2=plane[j].x,y2=plane[j].y;
            point center = make_pair(.5*(x1+x2),.5*(y1+y2));
            ld R = dis(center,plane[i]);
            cir2.insert(make_pair(R,center));
        }
    }
    for(it=cir2.begin();it!=cir2.end();++it){
        ld R = it->first;
        point center = it->second;
        ll ct=0;
        for(ll i=0;i<N;i++)
            ct+=(dis(center,plane[i])<=R);
        if(ct>=M)
            ans = min(ans,R);
    }
    return ans;
}
bool checkLine(ld x1,ld y1,ld x2,ld y2,ld x3,ld y3){
    return (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))!=0;
}
ld solve3Point(vector<point>plane,ll N,ll M,ld ans){
    set<pair<ld,point> > cir3;
    set<pair<ld,point> >::iterator it;
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            for(ll k=j+1;k<N;k++){
                ld x1=plane[i].x,y1=plane[i].y;
                ld x2=plane[j].x,y2=plane[j].y;
                ld x3=plane[k].x,y3=plane[k].y;
                if(checkLine(x1,y1,x2,y2,x3,y3)){
                    ld xc = ( (y1-y2)*(x3*x3+y3*y3) + (y2-y3)*(x1*x1+y1*y1) + (y3-y1)*(x2*x2+y2*y2) ) / (2.0*( x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
                    ld yc = ( (x1-x2)*(y3*y3+x3*x3) + (x2-x3)*(y1*y1+x1*x1) + (x3-x1)*(y2*y2+x2*x2) ) / (2.0*( y1*(x2-x3)+y2*(x3-x1)+y3*(x1-x2)));
                    point center = make_pair(xc,yc);
                    ld R = dis(center,plane[i]);
                    cir3.insert(make_pair(R,center));
                }
            }
        }
    }
    for(it=cir3.begin();it!=cir3.end();++it){
        ld R = it->first;
        point center = it->second;
        ll ct=0;
        for(ll i=0;i<N;i++)
            ct+=(dis(center,plane[i])<=R);
        if(ct>=M)
            ans = min(ans,R);
    }
    return ans;
}
int main(){
    //freopen("in.txt","r",stdin);
    ll N,M;  cin >> N >> M;
    vector<point> plane(N);
    for(ll i=0;i<N;i++){
        cin >> plane[i].x >> plane[i].y;
        plane[i].x*=10000.0,plane[i].y*=10000.0;
    }
    ld ans = DBL_MAX;
    cout<<setprecision(50);
    //cout<<ans<<endl;
    if(N==1 || M==1){
        ans=0;
    }else{
        //two point circle
        ans=solve2Point(plane,N,M,ans);
        //three point circle
        if(M>=3)
            ans=solve3Point(plane,N,M,ans);
    }
   // ans/=100.0;
    ans = sqrt(ans);
    ans/=10000.0;
    //cout<<ans<<endl;
    printf("%.9LF\n",ans);
    return 0;
}
