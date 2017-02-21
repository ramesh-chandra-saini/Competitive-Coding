#include<bits/stdc++.h>
using namespace std;
#define ll int
typedef struct __pair{
    ll x;
    ll y;
} Point;
Point make_point(ll x, ll y){
    Point temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
typedef struct __line{
    ll x1;
    ll y1;
    ll x2;
    ll y2;
    ll id;
} Line;
Line make_line(ll x1,ll y1,ll x2,ll y2,ll id){
    Line temp;
    temp.x1=x1;
    temp.y1=y1;
    temp.x2=x2;
    temp.y2=y2;
    temp.id=id;
    return temp;
}
vector<Line> H;
vector<Line> V;
vector<ll>ans(100005,0LL);
vector<ll> hor(100005,0LL);
vector<ll> horCum(100005,0LL);
vector<ll> ver(100005,0LL);
vector<ll> verCum(100005,0LL);
ll finalAns=0;
bool validate( Point  cross, Line  h){
    return (  h.x1<=cross.x && cross.x<= h.x2  &&  h.y1<=cross.y && cross.y<=h.y2);
}
bool endPoint(Point cross, Line  h){
    return (cross.x==h.x1 && cross.y==h.y1)||(cross.x==h.x2 && cross.y==h.y2);
}
void crossPoint(Point  cross,Line h, Line v){
   if( !validate(cross,h) || !validate(cross,v))
        return;
    //cout<<"valid "<<cross.x<<" "<<cross.y<<endl;
    if( endPoint(cross,h) && endPoint(cross,v))
        return;
    //cout<<"endPoint "<<cross.x<<" "<<cross.y<<endl;
    ans[h.id]++, ans[v.id]++,finalAns++;
}

bool __cmp( Line A,Line B){
    if(A.x1 != B.x1)
        return A.x1 < B.x1;
    return A.x2 <= B.x2;
}
void binSearch(vector<Line>&h,ll low,ll high,ll key,ll &lw){
    if(low>high)
        return;
    ll mid = (low+high)/2;
    if(  key<h[mid].x2 )
        binSearch(h,mid+1,high,key,lw);
    else{
        lw = mid;
        binSearch(h,low,mid-1,key,lw);
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    ll n; cin >> n;
    for(ll i=1,X1,Y1,X2,Y2;i<=n;i++){
        cin >> X1 >> Y1 >> X2 >> Y2;
        ll x1 = min(X1,X2);
        ll y1 = min(Y1,Y2);
        ll x2 = max(X1,X2);
        ll y2 = max(Y1,Y2);

        if(x1==x2){
            V.push_back(make_line(x1,y1,x2,y2,i));
            ver[]
        }else
            H.push_back(make_line(x1,y1,x2,y2,i));
    }
    sort(H.begin(),H.end(),__cmp);
    for(ll i=0;i<V.size();i++){
        ll lw=0;
        //binSearch(H,0,H.size()-1,V[i].x2,lw);
        for(ll j=lw;j<H.size();j++){
            //if(H[j].x1>V[i].x1)break;
            Point cross = make_point(V[i].x1,H[j].y1);
            crossPoint(cross,H[j],V[i]);
        }
    }
    cout<<finalAns<<endl;
    for(ll i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
}
