#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Point pair<ll,ll>
#define mp make_pair
#define x first
#define y second

bool __cmp(pair<Point,ll> A,pair<Point,ll>B){
    if(A.first.x!=B.first.x)
        return A.first.x<B.first.x;
    if(A.first.y!=B.first.y)
        return A.first.y<B.first.y;
    return A.second<B.second;
}
void lowerBoundX(vector<pair<Point,ll> >&point,ll L,ll R,ll x1,ll x2,ll &LId,bool &check){
    if(L>R) return;
    ll M = (L+R)/2;
    Point curr = point[M].first;
    ll currId = point[M].second;
    if(curr.x<x1){//right
        lowerBoundX(point,M+1,R,x1,x2,LId,check);
    }else if(curr.x>x2){//left
        lowerBoundX(point,L,M-1,x1,x2,LId,check);
    }else{ //valid one..go for lower bound---> go left
        LId=M; check=true;
        lowerBoundX(point,L,M-1,x1,x2,LId,check);
    }
}
void higherBoundX(vector<pair<Point,ll> >&point,ll L,ll R,ll x1,ll x2,ll &HId,bool &check){
    if(L>R) return;
    ll M = (L+R)/2;
    Point curr = point[M].first;
    ll currId = point[M].second;
    if(curr.x<x1){//right
        lowerBoundX(point,M+1,R,x1,x2,HId,check);
    }else if(curr.x>x2){//left
        lowerBoundX(point,L,M-1,x1,x2,HId,check);
    }else{ //valid one..go for lower bound---> go right
        HId=M;check=true;
        lowerBoundX(point,M+1,R,x1,x2,HId,check);
    }
}
void lowerBoundY(vector<pair<Point,ll> >&point,ll L,ll R,ll y1,ll y2,ll &LId,bool &check){
    if(L>R) return;
    ll M = (L+R)/2;
    Point curr = point[M].first;
    ll currId = point[M].second;
    if(curr.y<y1){//right
        lowerBoundX(point,M+1,R,y1,y2,LId,check);
    }else if(curr.y>y2){//left
        lowerBoundX(point,L,M-1,y1,y2,LId,check);
    }else{ //valid one..go for lower bound---> go left
        LId=M;check=true;
        lowerBoundX(point,L,M-1,y1,y2,LId,check);
    }
}
void higherBoundY(vector<pair<Point,ll> >&point,ll L,ll R,ll y1,ll y2,ll &HId,bool &check){
    if(L>R) return;
    ll M = (L+R)/2;
    Point curr = point[M].first;
    ll currId = point[M].second;
    if(curr.y<y1){//right
        lowerBoundX(point,M+1,R,y1,y2,HId,check);
    }else if(curr.y>y2){//left
        lowerBoundX(point,L,M-1,y1,y2,HId,check);
    }else{ //valid one..go for lower bound---> go right
        HId=M;check=true;
        lowerBoundX(point,M+1,R,y1,y2,HId,check);
    }
}
int main(){
    ll N,q; cin >> N >> q;
    vector<pair<Point,ll> > point(N+1);
    for(ll i=1;i<=N;i++){
        cin >> point[i].first.x >> point[i].first.y;
        point[i].second=i;
    }
    vector<pair<Point,ll> > cp(point);
    sort(point.begin()+1,point.end(),__cmp);
    map<Point,ll> temp;
    for(ll i=1;i<=N;i++)
        temp[cp[i].first]=i;
    //Sorte Id vs  Actual Id
    vector<ll> idResolver(N+1,0);
    for(ll i=1;i<=N;i++){
        ll id = temp[point[i].first];
        idResolver[id]=i;
    }
    vector<ll> fenceId(N+1,0);
    vector<pair<Point,Point>  > query(q+1);
    for(ll Q=1;Q<=q;Q++){

        string str; cin >> str;
        if(str=="query"){
            //cout<<"QUERY"<<endl;
            ll i,j;cin >> i >> j;//actual Id
            i=idResolver[i];
            j=idResolver[j];
         (fenceId[i]==fenceId[j])?cout<<"YES"<<endl:cout<<"NO"<<endl;
        }else if(str=="add"){
            //cout<<"ADD"<<endl;
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            ll LId = 1,HId=N;
            bool check=false;
            lowerBoundX(point,LId,HId,x1,x2,LId,check);
            higherBoundX(point,LId,HId,x1,x2,HId,check);
            lowerBoundY(point,LId,HId,y1,y2,LId,check);
            higherBoundY(point,LId,HId,y1,y2,HId,check);
            for(ll i=LId;i<=HId && check;i++)
                fenceId[i]=Q;
            query[Q]=mp(mp(x1,y1),mp(x2,y2));
        }else if(str=="delete"){
            //cout<<"DELETE"<<endl;
            ll qNo;cin >> qNo;
            ll x1,y1,x2,y2;
            x1=query[qNo].first.x;
            y1=query[qNo].first.y;
            x2=query[qNo].second.x;
            y2=query[qNo].second.y;//          cin >> x1 >> y1 >> x2 >> y2;
            ll LId = 1,HId=N;
            bool check=false;
            lowerBoundX(point,LId,HId,x1,x2,LId,check);
            higherBoundX(point,LId,HId,x1,x2,HId,check);
            lowerBoundY(point,LId,HId,y1,y2,LId,check);
            higherBoundY(point,LId,HId,y1,y2,HId,check);
            for(ll i=LId;i<=HId && check;i++)
                fenceId[i]=0;
        }
    }
    return 0;
}
