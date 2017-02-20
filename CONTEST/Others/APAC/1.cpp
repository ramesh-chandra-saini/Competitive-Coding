#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll N,string str,ll M,ll r=0,ll ans=0){
    for(ll i=0;i<N;i++)
        r+=(str[i]=='B');
    ans+=(M/N)*r;
    M-=(M/N)*N;
    for(ll i=0;i<N && M;i++,M--)
        ans+=(str[i]=='B');
    return ans;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll t; cin >> t;
    for(ll T=1;T<=t;T++)
    {
        string str; cin >> str;
        ll N = str.length();
        ll L,R;cin >> L >> R;
        cout<<"Case #"<<T<<": "<<(solve(N,str,R)-solve(N,str,L-1))<<endl;
    }
    return 0;

}

