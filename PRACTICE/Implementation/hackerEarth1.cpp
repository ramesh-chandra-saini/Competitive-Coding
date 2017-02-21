#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getOne(ll N){
	return (!N)?0LL:(N%2LL)+getOne(N/2LL);
}
int main(){
	ll t; cin >> t; while(t--){
		map<ll,set<pair<ll,ll> > >m;
		ll n; cin >> n; for(int i=0;i<n;i++){
			ll val; cin >> val;m[getOne(val)].insert(make_pair(val,i));
		} for(map<ll,set<pair<ll,ll> > >::iterator it = m.begin();it!=m.end();++it)
			for(set<pair<ll,ll> >::iterator sit=(it->second).begin();sit!=(it->second).end();++sit)
				cout<<sit->first<<" ";
		cout<<endl;
	} return 0;
}
