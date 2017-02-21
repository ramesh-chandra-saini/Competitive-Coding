#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("t.txt","r",stdin);
    freopen("b.txt","w",stdout);
    ll n,m; cin >> n >> m;
    vector<vector<ll> > mat(n,vector<ll>(m,0LL));
    for(ll i=0;i<n;i++){
        string str;cin >> str; //cout<<str<<endl;
        for(ll j=0;j<m;j++)
            mat[i][j]=(str[j]=='0')?0LL:1LL;
    } //for(ll i=0;i<n;i++,cout<<endl) for(int j=0;j<m;j++) cout<<mat[i][j]; cout<<endl;
    ll r=0LL;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            for(ll l=1;l<=n-1-i;l++)
                for(ll b=1;b<=m-1-j;b++)
                    r+=(mat[i][j]+mat[i+l][j]+mat[i+l][j+b]+mat[i][j+b]==0LL);
    ll p = 1LL,q = 1LL; //cout<<r<<" "<<endl;
    if(r>0){
        p = 5LL*1LL+(r-1LL)*1LL*6LL;
        q = 6LL*r;
        ll g = __gcd(p,q);
        p/=g,q/=g;
    }
    cout<<p<<" "<<q<<endl;
    return 0;
}
