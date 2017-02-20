#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll getMin(vector<ll>&arr,vector<ll>&A,ll ct){
    if(ct==1){  for(ll i=0;i<arr.size();i++) {if(arr[i]!=A[i]) return arr[i]; }
    }else{  ll mx = INT_MAX;    for(ll i=0;i<arr.size();i++) mx=min(mx,arr[i]); return mx;}
}
ll fun(int n,ll D,vector<ll>&arr){
    ll ans=INT_MAX;
    vector<ll> A(n),B(n);
    A[0]=arr[0];
    ll DF=D;     ll ct = 0;
    for(int i=1;i<n;i++) {
        A[i]=A[0]+DF;        DF+=D;
        if(A[i]!=arr[i])         ct++,  DF-=D;
    }
    if(ct<2)  ans=min(ans,getMin(arr,A,ct));
    B[1]=arr[1]; B[0]=B[1]-D;
    ct =0;    DF=D;
    if(B[0]!=arr[0]){
        ct++;
        DF=D;
    }
    for(int i=2;i<n;i++){
        B[i]=B[1]+DF; DF+=D;
        if(B[i]!=arr[i])   ct++,DF-=D;
    }
    if(ct<2)    ans=min(ans,getMin(arr,B,ct));
    return ans;
}
int main(){
        int t; scanf("%lld",&t);while(t--){
            ll n; scanf("%lld",&n);
            vector<ll> arr(n); for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);
                set<ll> mySet; mySet.clear();mySet.insert(arr[1]-arr[0]);
                for(int i=2;i<n;i++)mySet.insert(arr[i]-arr[i-2]),mySet.insert(arr[i]-arr[i-1]);// cout<<mySet.size()<<endl;
                ll ans=INT_MAX;
                if(mySet.size()>100) ans=-1;
                else{
                    for(set<ll>::iterator it = mySet.begin();it!=mySet.end();++it)
                        ans=min(ans,fun(n,*it,arr));
                    ans=(ans==INT_MAX)? -1:ans;

                }
                printf("%lld\n",ans);
            }
}
