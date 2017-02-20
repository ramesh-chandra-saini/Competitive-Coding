/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
==============================================================
            #BruteForce
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
       // for(map<ll,vector<ll> >::iterator it=myMap.begin();it!=myMap.end();++it){ cout<<it->first<<") ." ;for(vector<ll> :: iterator vit=it->second.begin();vit!=it->second.end();++vit)cout<<*vit<<" "; cout<<endl;}
        ll lastIndex=N+1;
        ll finalAns=0;
        for(ll i=1;i<=N;i++){ map<ll,bool> visit;set<ll> mySet;mySet.insert(i-1); mySet.insert(lastIndex); ans=numOfSubset(i-1,lastIndex);
            for(ll j=i;j<=N;j++){ //cout<<"SubSet=>[";for(int k=i;k<=j;k++) cout<<arr[k]<<" "; cout<<"] ";
                    for(set<ll>::iterator it=myMap[arr[j]].find(j);it!=myMap[arr[j]].end();++it){
                        if(!visit[arr[j]]) {  //cout<<"== > {";
                            mySet.insert(*it);//for(set<ll>::iterator temp=mySet.begin();temp!=mySet.end();temp++) cout<<*temp<<" "; cout<<"} :: ";
                            set<ll>::iterator setIt = mySet.find(*it);
                            ll a =*(-- setIt),b=*(++ setIt),c=*(++ setIt); //cout<<"["<<a<<","<<b<<","<<c<<"]"<<"  ";
                            ans = ans-numOfSubset(a,c) +numOfSubset(a,b)+numOfSubset(b,c);
                        }
                    } //cout<<"{";for(set<ll>::iterator temp=mySet.begin();temp!=mySet.end();temp++) cout<<*temp<<" "; cout<<"} ";cout<<ans<<endl;
                    finalAns+=ans;
                    visit[arr[j]]=true;
            }
        }    printf("%lld\n",finalAns);
    }
    return 0;
}
