#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
  ll t,r,g,b,k;
  scanf("%lld",&t);
  while(t--)
  {
  	scanf("%lld%lld%lld",&r,&g,&b);
  	scanf("%lld",&k);
  	int flagr=0,flagg=0,flagb=0;
  	flagr=r<k?1:0;
  	flagg=g<k?1:0;
  	flagb=b<k?1:0;
  	ll ans=0;
  	if((flagr&&flagg)||(flagr&&flagb)||(flagb&&flagg))
  	{
  		int maxi=max(r,max(g,b));
  		ans=k+(r+g+b)-maxi;
	  }
	else if(flagr||flagg||flagb)
	{
		int mini=min(r,min(g,b));
		ans=mini+2*k-1;
	}
	else
	ans=3*(k-1)+1;
	printf("%lld\n",ans);
  }
  return(0);
  }
