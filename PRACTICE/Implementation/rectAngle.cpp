#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define mp make_pair

//(x1(y2–y3)+x2(y3–y1)+x3(y1–y2))
ll Area(pair<ll,ll>&A,pair<ll,ll>&B,pair<ll,ll>&C){
    ll area = 0;
    cout<<area<<endl;
    return area;
}
ll dist(pair<ll,ll>&A,pair<ll,ll>&B){
    if(A==B) return 50;
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
int main(){
    ll q; cin >> q; while(q--){
        ll n; cin >> n;
        vector<pair<ll,ll> > points(n);

        ll xmin=INT_MAX,xmax=INT_MIN,ymin=INT_MAX,ymax=INT_MIN;

        for(ll i=0;i<n;i++){
            cin >> points[i].x >> points[i].y;
            xmin = min(xmin,points[i].x);
            xmax = max(xmax,points[i].x);
            ymin = min(ymin,points[i].y);
            ymax = max(ymax,points[i].y);
        }
        pair<ll,ll> A = mp(xmin,ymin);
        pair<ll,ll> B = mp(xmax,ymin);
        pair<ll,ll> C = mp(xmax,ymax);
        pair<ll,ll> D = mp(xmin,ymax);
        bool flag = true;
        for(ll i=0;i<n;i++){//check for where points lies
            flag = (Area(A,B,points[i])==0LL||Area(B,C,points[i])==0LL||
                    Area(C,D,points[i])==0LL||Area(D,A,points[i])==0LL)?flag:false;
            cout<<i<<"-->"<<flag<<endl;
        }
        //check for side length
        flag = (dist(A,B)==0LL||dist(B,C)==0LL||dist(C,D)==0LL||dist(D,A)==0LL)?false:flag;
        (flag)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}
