#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
/*bool TH(ll n,vector<ll> &A,ll ans=0LL){
	for(ll i=0;i<n;i++)
		ans = (ans^A[i]);
	return ans==0;//0-->yes
}
bool MY(ll n,vector<ll>&A){
    map<ll,ll>mp;mp.clear();
	for(ll i=0;i<n;i++)
		mp[A[i]]++;
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();++it)
		if((it->second)%2LL!=0LL) return false;
	return true;
}*/
int main(){
	ll t; cin >> t; while(t--){
		ll n; cin >> n;
		vector<ll> arr(n);for(ll i=0;i<n;i++) cin >>arr[i];
		ll N = (1LL<<n);
		ll ans = 0;
		map<ll,ll>

		for(ll i=1;i<N;i++){
			ll temp=i;
			 map<ll,ll>mp;mp.clear();
			 ll ANS = 0LL;
			for(ll j=0;j<n && temp;j++,temp/=2)
				if(temp%2){
					ANS = (ANS^arr[j]);
					mp[arr[j]]++;
				}
			bool th = true;
			for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();++it)
				if((it->second)%2LL!=0LL) {th=false;break;}
			ll my = (ANS==0);
			ans+=(th==my); //cout<<th<<" "<<my<<endl;
		} cout<<ans<<endl;
	}
    return 0;
}
