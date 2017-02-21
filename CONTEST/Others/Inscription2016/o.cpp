#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    return b==0LL?a:gcd(b,a%b);
}
int main(){
    //freopen("t.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    ll n,m; cin >> n >> m;
    vector<vector<ll> > mat(n,vector<ll>(m,0LL));
    for(ll i=0LL;i<n;i++){
        string str;cin >> str; //cout<<str<<endl;
        for(ll j=0LL;j<m;j++)
            mat[i][j]=(str[j]=='0')?0LL:1LL;
    } //for(ll i=0;i<n;i++,cout<<endl) for(int j=0;j<m;j++) cout<<mat[i][j]; cout<<endl;
    ll r=0LL,p = 1LL,q = 1LL;;
    for(ll i=0LL;i<m;i++) //cout<<"["<<i<<" "<<i<<"]"<<endl;
        for(ll b=1LL;b<=m-1LL-i;b++)//cout<< "B "<< b<<endl;
            for(ll k=n-1,ct=0LL;k>=0LL;k--)
                if(mat[k][i]==0LL&&mat[k][i+b]==0LL)
                    ++ct,r+=(ct-1LL);
    if(r>0LL){
        p = 5LL*1LL+(r-1LL)*1LL*6LL;
        q = 6LL*r;
        ll g = gcd(p,q);
        p/=g,q/=g;
    }
    cout<<p<<" "<<q<<endl;
    return 0;
}
