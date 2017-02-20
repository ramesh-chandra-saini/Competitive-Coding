#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll ans=INT_MAX;
bool finbase(ll n,ll base)
{
    while(n)
    {
       if(n%base!=1)
       {
           return false;
       }
     n/=base;
    }
    return true;

}
int findirect(ll n,ll base)
{

    while(n)
    {
       if(n%base>1)
       {
           return 1;
       }
      n/=base;
    }
    return 0;

}
void binery(ll state,ll l,ll r,ll n)
{
    if(l>r)
    {
        return ;

    }
    ll mid=(l+r)/2;
    if(finbase(n,mid)==true)
    {
        ans=min(ans,mid);

    }
    int dir=findirect(n,mid);
    if((state==1&&dir==1)||(state==0&&dir==0))
    {

        binery(1,mid+1,r,n);
    }
    else
    {
       binery(0,l,mid-1,n);
    }

}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
   int t,t1;
     cin>>t;
     ll n;
    for(t1=1;t1<=t;t1++)
     {
         ans=INT_MAX;
     cin>>n;
     binery(0,2,n,n);
     binery(1,2,n,n);
    // cout<<ans<<endl;
     printf("Case #%d: %lld\n",t1,ans);
     }

}
