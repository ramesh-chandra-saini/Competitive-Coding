#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000006
vector<ll> primeList;
void seive(){
    vector<bool> primeChecker(MAX,true);
    for(ll i=2LL;i*i<MAX;i++)
        if(primeChecker[i])
            for(ll j=i*i;j<MAX;j+=i)
                primeChecker[j]=false;
    for(ll i=2;i<MAX;i++)
        if(primeChecker[i])
            primeList.push_back(i);
}
void  checkerForSquaredNumber(ll N,ll &ans){
    for(ll i=0;i<primeList.size();i++){
        if(N%(primeList[i]*primeList[i])==0LL) ans=primeList[i];
        else if(N%primeList[i]==0LL) N/=primeList[i];
    }
    ll sqrtOfN = sqrt(N);
    while(sqrtOfN*sqrtOfN<N ) sqrtOfN++;
    if(sqrtOfN*sqrtOfN==N && sqrtOfN>1)
        ans=sqrtOfN;
}
int main(){
    seive();
    ll t; cin >> t;
    while(t--){
        ll N,ans=0LL; cin >> N;
        ll arr[N]; for(ll i=0;i<N;i++) cin >> arr[i];
        for(ll i=0;i<N;i++)
            for(ll j=i+1;j<N;j++)
               if(__gcd(arr[i],arr[j])>1LL)
                    ans=__gcd(arr[i],arr[j]);
        for(ll i=0;i<N;i++)
            checkerForSquaredNumber(arr[i],ans);
        cout<<ans<<endl;
    }
    return 0;
}
