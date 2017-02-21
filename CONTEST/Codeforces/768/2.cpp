#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ans = 0;
void solve(ll ss,ll se,ll zero,ll qs,ll qe ){
    if(ss>se || qs>qe || se<qs || ss>qe || zero==0LL)
        return;
    ll mid = (ss+se)/2LL;
    if(qs<=mid && mid<=qe && zero%2LL==1LL)
        ans++;
    solve(ss,mid-1,zero/2LL,qs,qe);
    solve(mid+1,se,zero/2LL,qs,qe);
}
int main(){
    ll n,l,r; cin >> n >> l >> r;
    if(n==0){
        cout<<0<<endl; return 0;
    }
    ll live = (n>1LL)?1LL:0LL,zero = 0LL, one = 0LL;
    ll temp = n;
    while(temp>1)
        zero+=(temp%2)?0:live,
        one+=(temp%2)?live:0,live*=2LL,temp/=2LL;
    solve(1LL,n+zero,zero,l,r);
    cout<<(r-l+1)-ans<<endl;
}
