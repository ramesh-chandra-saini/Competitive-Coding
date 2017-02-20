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
int main(){

    ll T; cin >> T;
    while(T--){
        ll N ; cin >> N;
        ll arr[N]; for(ll i=0;i<N;i++) cin >> arr[i];
        ll ans=0;
        for(int i=0;i<N-1;i++){
            set<ll> A;A.clear();
            for(int j=i;j<N-1;j++){
                A.insert(arr[j]);
                for(int k=j+1;k<N;k++){
                    set<ll> B; B.clear();
                    for(int l=k;l<N;l++){
                        B.insert(arr[l]);
                        set<ll> C; C.insert(A.begin(),A.end()); C.insert(B.begin(),B.end());
                        ans+=(A.size()+B.size()==C.size());
                        if((A.size()+B.size()==C.size()))cout<<"["<<i<<","<<j<<"] "<<"["<<k<<","<<l<<"] \n";
                    }
                }
            }
        } cout<<ans<<endl;
    }
    return 0;
}
