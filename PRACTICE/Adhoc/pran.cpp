#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool fun(string s, ll k,ll ct=0){
    for (ll i = 0;i<=s.length()-2;i++)
        ct+=(s[i] != s[i + 1]);
    return (ct >= k);
}
ll ans = 0;
void solve(ll pos, ll n, ll open, ll close,ll k,string str){
  if(close == n){
    cout<<str<<endl;
    ans=(ans+fun(str,k))%mod;
    return;//done return :->  backtrack
  }  else{
    if(open > close) {
        str[pos] = ')';
        solve(pos+1, n, open, close+1,k,str);
    }
    if(open < n) {
       str[pos] = '(';
       solve(pos+1, n, open+1, close,k,str);
    }
  }
}
int main(){
    ll q; cin >> q; while(q--){
        ll n,k; cin >> n >> k;
        if(n%2){ cout<<"0"<<endl;
        }else{
            ans = 0;
            string str;  for(ll i=0;i<n;i++) str.push_back(' ');
            solve(0,n/2,0,0,k,str);
            cout<<ans<<endl;
        }
    } return 0;
}
