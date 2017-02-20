#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
ll power(ll a,ll b)
{
	if(b==0)
	return(1);
	ll sum=1;
	while(b>0)
	{
		if(b&1)
		sum=(sum*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return(sum);
}
int main(){
	ll t,n,x,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&x,&m);
		ll arr[n],i;
		for(i=0;i<n;arr[i]%=M,i++)
		scanf("%lld",&arr[i]);
		m--;
		ll ans=0,j=x-1,val=1,upp=1,lower=1;
		i=1;
		ans+=(arr[j]*(val%M))%M;
		j--;
		while(j>=0)
		{
		   upp=(upp*((m+i)%M))%M;
		   lower=(lower*(i%M))%M;
		   ll denom=power(lower,M-2);
		   val=(upp*denom)%M;
		   cout<<val<<endl;
		   ans=(ans+arr[j]*val)%M;
		   j--;
		   i++;
		}
		printf("%lld\n",ans);
	}
	return(0);
}
