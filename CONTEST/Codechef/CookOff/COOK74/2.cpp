#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX (1LL<<62)
ll getMin(vector<ll>&arr,vector<ll>&A,ll ct){
    if(ct==1){  for(ll i=0;i<arr.size();i++) {if(arr[i]!=A[i]) return arr[i]; }
    }else{  ll mx = MAX;    for(ll i=0;i<arr.size();i++) mx=min(mx,arr[i]); return mx;}
}
ll fun(int n,ll D,vector<ll>&arr){
    ll ans=MAX;
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
    clock_t start = clock();
        int t; cin >> t; while(t--){
            ll n; cin >> n;
            vector<ll> arr(n); for(ll i=0;i<n;i++) cin >> arr[i];
                set<ll> mySet; mySet.clear();
                for(int i=1;i<n;i++)         mySet.insert(arr[i]-arr[i-1]);// cout<<mySet.size()<<endl;
                if(mySet.size()>3) cout<<"-1"<<endl;
                else{
                    ll ans=MAX;
                    for(set<ll>::iterator it = mySet.begin();it!=mySet.end();++it)
                        ans=min(ans,fun(n,*it,arr));
                        (ans==MAX)? cout<<"-1"<<endl: cout<<ans<<endl;
                }
            }
        clock_t end = clock();
        double dur = double(end-start)/CLOCKS_PER_SEC;
        cout<<dur<<endl;
         return 0;
}
