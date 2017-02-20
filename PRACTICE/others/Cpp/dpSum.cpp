#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Mod 1000000007

ll rep(ll n,ll f){
    ll ans=1LL;
    while(f){
        if(f%2)
            ans=(ans*n )%Mod;
        n=(n*n)%Mod;
        f/=2LL;
    }
    return ans;
}
int main(){

  ll n,k; cin >> n >> k;
  ll arr[n],sum=0,f=0;
  for(int i=0;i<n;i++){
    cin >> arr[i];
    arr[i]=arr[i]%k;
    sum+=arr[i];
    f+=(arr[i]==0)?1:0;
  }
  ll ans=(f==0)?0:(Mod+rep(2LL,f)-1)%Mod;
  ll __sum=(sum/k)*k;
  if(__sum!=0){
        bool dp[__sum+1][n+1];
        for(ll i=0;i<=n;i++) dp[0][i]=true;
        for(ll i=1;i<=__sum;i++) dp[i][0]=false;

        for( ll i =1;i<=__sum;i++){

            for(ll j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1];
                if(i>=arr[j-1]) dp[i][j]=(dp[i][j] || dp[i-arr[j-1]][j-1]);
            }
        }
    for(ll _sum=k;_sum<=__sum;_sum+=k){

        for(ll i=1;i<=n;i++){
            ans+=dp[__sum][i];
        }
        ans%=Mod;
    }
}
  cout<<ans<<endl;
  return 0;
}
