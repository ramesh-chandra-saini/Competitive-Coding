#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>
using namespace std;
vi prime;
vi sqr;
void sieve()
{
	vector<bool> b(1000000,0);
	prime.push_back(2);
	//mark(1,b);
	for(ll i=2;i<=1000000;i+=2)
	{
		if(!b[i]) { prime.push_back(i+1);
			int j=i;
	    for(;j<=1000000;j+=(i+1))
		b[j]=1;
		}
	}
	for(int i=0;i<100;i++) cout<<prime[i]<<" "; cout<<prime[prime.size()-1]<<endl;
}
ll gcd(ll a,ll b)
{
	if(a<b) {a^=b; b^=a; a^=b; }
	if(b==0) return a;
	return gcd(b,a%b);
}
ll issquare(ll a)
{
	int n=prime.size();
	for(int i=0;i<n;++i)
	{
		if((a%(prime[i]*prime[i]))==0) return prime[i];
		else if(a%prime[i]==0) a/=prime[i];
	}
	ll tmp=sqrt(a);
	if(tmp*tmp==a) return tmp;
	return 0;
}
int main(){
	sieve();
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vi a(n);for(int i=0;i<n;++i) cin>>a[i];
		ll ans=-1;bool bl=false;
		for(int i=0;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				if(gcd(a[i],a[j])>1){
					ans=gcd(a[i],a[j]);
					bl=true;break;
				}
			}
		}
			for(int i=0;i<n;++i){
				if(issquare(a[i])>1){
					ans=issquare(a[i]);
					break;
				}
			}
		cout<<ans<<"\n";
	}
}
