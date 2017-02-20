#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
ll fact[100005];
ll power(ll N,ll expo){
    ll ans=1LL;
    for(;expo;expo/=2,N=(N*N)%MOD) if(expo%2) ans=(ans*N)%MOD;
    return ans;
}
ll C(ll N,ll K){
    ll ans=(N==K);
    if(N>K){
        ll n=fact[N],k=fact[K],n_k=fact[N-K];
        ll denom = (k*n_k)%MOD;
        ans=(n*power(denom,MOD-2))%MOD;
    }//cout<<N<<"C"<<K<<"("<<ans<<") ";
     return ans;
}
ll Solve(ll N,ll K,ll zero){
    ll ans=0LL;
    if(zero){
        for(;K>=0;K--)ans=(ans+C(N,K))%MOD;
    }
    else{
        for(;K>=0;K-=2)ans=(ans+C(N,K))%MOD;
    } //cout<<endl;
    return ans;
}
void permute(vector<bool> &a, ll l, ll r,set<vector<bool> > &maskPermute){
   ll i; bool temp;
   if (l == r) maskPermute.insert(a);
   else{
       for (i = l; i <= r; i++){
            temp=a[l]; a[l]=a[i];a[i]=temp;
            permute(a, l+1, r,maskPermute);
            temp=a[l]; a[l]=a[i];a[i]=temp;
       }
   }
}
set<vector<bool> > allPermute(vector<bool> & mask){
    set<vector<bool> > maskPermute;
    permute(mask, 0LL, mask.size()-1,maskPermute);
    return maskPermute;
}
void __solve(ll N,ll K,ll arr[],set<vector<ll> > &ans){
    vector<bool> mask(N,false);
    for(int i=0;i<K;i++) mask[i]=true;
    set<vector<bool> > permute=allPermute(mask);
    for(set<vector<bool> > :: iterator it=permute.begin();it!=permute.end();++it){
        vector<ll> comb; comb.clear();
        vector<bool> checker=*it;
        for(int j=0;j<N;j++)
            if(checker[j]) comb.push_back((-1)*arr[j]);
            else comb.push_back(arr[j]);
        ans.insert(comb);
    }
}
ll bruteForce(ll N,ll K,ll arr[]){
    set< vector<ll> > ans; ans.clear();
    for(;K>=0;K-=2){
        if(N>=K)__solve(N,K,arr,ans);
    }
    for(set<vector<ll> >:: iterator it=ans.begin();it!=ans.end();++it){
        vector<ll> vec = *it;
        for(int i=0;i<vec.size();i++) cout<<vec[i]<<" "; cout<<endl;
    }
    return ans.size();
}
int main(){
    fact[0]=1LL;
    for(ll i=1LL;i<100005;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    ll t;   cin >> t;
    while(t--){
        ll n,K; cin >> n >> K;
        ll arr[n],zero=0;
        for(ll i=0;i<n;i++) cin >> arr[i], zero+=(arr[i]==0);
         //cout<<bruteForce(n,K,arr)<<endl;
        if(n==1) cout<<"1"<<endl;
        else n-=zero,cout<<Solve(n,K,zero)<<endl;

    }return 0;
}
