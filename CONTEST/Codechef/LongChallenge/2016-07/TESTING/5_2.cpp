/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
==============================================================
            #BruteForce
*/
#include<bits/stdc++.h>
using namespace std;
#define ll int
void copyVectorIntoSet(set<ll>&mySet,set<ll>&vec,int i){
    for(set<ll>::iterator it=vec.find(i);it!=vec.end();it++)
        mySet.insert(*it);
}
int main(){

    ll T; scanf("%d",&T);//cin >> T;
    while(T--){
        ll N ; scanf("%d",&N);//cin >> N;
        vector<ll> arr(N); for(ll i=0;i<N;i++) scanf("%d",&arr[i]);//cin >> arr[i];
        ll ans=0;
        map<ll,set<ll> > myMap;
        for(int i=0;i<N;i++) myMap[arr[i]].insert(i);
       // for(map<ll,vector<ll> >::iterator it=myMap.begin();it!=myMap.end();++it){ cout<<it->first<<") ." ;for(vector<ll> :: iterator vit=it->second.begin();vit!=it->second.end();++vit)cout<<*vit<<" "; cout<<endl;}
        set<ll> mySet;mySet.clear();mySet.insert(N);
        map<ll,bool> visit;
        for(ll i=0;i<N;i++){ visit.clear();
            for(ll j=i;j<N;j++){
                    if(!visit[arr[j]]) copyVectorIntoSet(mySet,myMap[arr[j]],j); visit[arr[j]]=true;
                    while(*mySet.begin()<=j) mySet.erase(mySet.begin());
                   //cout<<"{ "; for(int k=i;k<=j;k++) cout<<arr[k]<<" "; cout<<"} ";

                    //for(set<ll>::iterator it=mySet.begin();it!=mySet.end();it++){cout<<*it<<" ";} cout<<endl;
                    ll a=0,b=j; mySet.insert(N);
                    for(set<ll>::iterator it=mySet.begin();it!=mySet.end();it++){
                        a=b;b=*it;
                       // cout<<"["<<a<<","<<b<<"]"<<" ";
                        ll freq=max(0,(b-1)-(a+1)+1 );
                        ans+=(freq*(freq+1))/2;
                    } //cout<<" ==> "<<ans<<endl; mySet.erase(N); for(set<ll>::iterator it=mySet.begin();it!=mySet.end();it++){cout<<*it<<" ";} cout<<endl;
            }
        }    printf("%d\n",ans);
    }
    return 0;
}
