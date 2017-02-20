#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N,Q;
ll A[2002][2002];
vector<vector<ll> > BIT(2002,vector<ll>(2002,0));
void func(ll a, ll b, ll c){
    ll num = a;
    ll M = 1000000007;
    for(ll i=1; i<=N; i++)
    {
        for(ll j=1; j<=N; j++)
        {
            A[i][j] = num;
            num = (num*b+c)%M;
        }
    }
}
void update(ll x1,ll y1,ll N,ll value){
    for(ll x=x1;x<=N;x+=(x&(-x)))
        for(ll y=y1;y<=N;y+=(y&(-y)))
            BIT[x][y]+=value;
}
ll query(ll x,ll y,ll sum=0){
    for(ll i=x;i>0;i-=(i&-i))
        for(ll j=y;j>0;j-=(j&-j))
                sum+=BIT[i][j];
    return sum;
}
ll getSum(ll x,ll y,ll X,ll Y){
    return query(X,Y)-query(x-1,Y)-query(X,y-1)+query(x-1,y-1);
}
ll get(ll x1,ll y1, ll x2,ll y2,ll sum=0){
    ll xmid = (x1+x2)/2;
    ll ymid = (y1+y2)/2;
    ll hor = getSum(x1,ymid,x2,ymid);
    ll vert  = getSum(xmid,y1,xmid,y2);
    return hor+vert-A[xmid][ymid];
}
int main(){
     cin >> N >> Q;
    ll a,b,c; cin >> a >> b >> c;
    func(a,b,c);
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            update(i,j,N,A[i][j]);
               // cout<<A[i][j]<<" ";
        } //cout<<endl;
    }
    while(Q--){
        char c; scanf(" %c",&c); //cout<<c<<endl;
        if(c=='F'){
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2 ;
            cout<<get(x1,y1,x2,y2)<<endl;
        }else{
            ll x,y,value; cin >> x >> y >> value;
            update(x,y,N,value-A[x][y]);
            A[x][y]+=value - A[x][y];
        }
    }    return 0;
}
