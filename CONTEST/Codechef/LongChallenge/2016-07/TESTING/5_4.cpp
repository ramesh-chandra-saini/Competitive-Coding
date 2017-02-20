/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll numOfSubset(ll I, ll J){
    ll numOfElement = max(0LL,(J-1)-(I+1)+1LL);
    return (numOfElement*(numOfElement+1))/2LL;
}
int main(){
    ll T; scanf("%lld",&T);
    for(ll t=1;t<=T;t++){
        ll N ; scanf("%lld",&N);
        vector<ll> arr(N+1); for(ll i=1;i<=N;i++) scanf("%lld",&arr[i]);
        ll ans=0;map<ll,set<ll> > myMap;for(int i=1;i<=N;i++) myMap[arr[i]].insert(i);
        ll finalAns=0;
        for(ll i=1;i<=N;i++){ map<ll,bool> visit;set<ll> mySet;mySet.insert(i-1); mySet.insert(N+1); ans=numOfSubset(i-1,N+1);
            for(ll j=i;j<=N;j++){
                    if(!visit[arr[j]]) {
                        for(set<ll>::iterator it=myMap[arr[j]].find(j);it!=myMap[arr[j]].end();++it){
                            mySet.insert(*it);
                            set<ll>::iterator setIt = mySet.find(*it);
                            ll a =*(-- setIt),b=*(++ setIt),c=*(++ setIt);
                            ans = ans-numOfSubset(a,c) +numOfSubset(a,b)+numOfSubset(b,c);
                        }
                    } finalAns+=ans;visit[arr[j]]=true;
            }
        }    printf("%lld\n",finalAns);
    }
    return 0;
}
