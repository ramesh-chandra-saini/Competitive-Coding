#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll> getFactor(ll N){
    map<ll,ll>factors;
    for(ll i=2;i*i<=N;i++)
        if(N%i==0){
            ll freq=0;
            while(N%i==0) N/=i,freq++;
            factors[i]=freq;
        }
    if(N>1) factors[N]=1;
    return factors;
}
int main(){
    ll N; cin >> N;
    map<ll,ll>factors=getFactor(N);
    map<ll,ll >mFactors; for(map<ll,ll>::iterator it=factors.begin();it!=factors.end();++it) mFactors[it->first]=2*it->second;
    for(map<ll,ll>::iterator it=factors.begin();it!=factors.end();++it) cout<<it->first<<"["<<it->second<<"] "; cout<<endl;
    for(map<ll,ll>::iterator it=mFactors.begin();it!=mFactors.end();++it) cout<<it->first<<"["<<it->second<<"] "; cout<<endl;

   while(true){
        bool flag=false;
        for()

    }
    //for(set<ll>::iterator it=factors.begin();it!=factors.end();++it) cout<<*it<<" "; cout<<endl;
    map<ll,bool> visit;
    ll ans=0;
    for(set<ll>::iterator it=factors.begin();it!=factors.end();++it)
        for(ll i=*it,j=i;j<=N;j+=i)  if( (N*N)%j==0 && N%j!=0 &&visit[j]==false) visit[j]=true, ans++;
    cout<<ans<<endl;  */ return 0;
}
