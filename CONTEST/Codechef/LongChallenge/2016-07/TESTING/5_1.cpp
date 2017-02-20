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
int main(){

    ll T; scanf("%d",&T);//cin >> T;
    for(ll t=1;t<=T;t++){
        ll N ; scanf("%d",&N);//cin >> N;
        ll arr[N]; for(ll i=0;i<N;i++) scanf("%d",&arr[i]);//cin >> arr[i];
        ll ans=0;
        set<ll> mySet; mySet.clear();
        for(int i=0;i<N-1;i++){
            mySet.clear();
            for(int j=i;j<N-1;j++){
                mySet.insert(arr[j]);
                ll ct=0;
                for(int k=j+1;k<N;k++){
                    if(mySet.find(arr[k])!=mySet.end()) {
                        ans=ans+(ct*(ct+1))/2LL; ct=0;
                    }else ct++;
                }
                ans=ans+(ct*(ct+1))/2LL; ct=0;
            }
        } printf("%d\n",ans);//cout<<ans<<endl;
    }
}
