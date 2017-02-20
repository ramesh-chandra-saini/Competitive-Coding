#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll T; cin >> T;
    while(T--){
        ll N; cin >> N;
        ll arr[N+1];
        for(ll i=1;i<=N;i++)
            cin >> arr[i];
        ll status = 0,fine=0;
        for(ll i=1;i<=N;i++){
            status+=arr[i];
            if(status == i)
                continue;
            else
                fine+=100LL;
        }
        ll total = (N-status)*1000LL+fine;
        cout<<total<<endl;
    } return 0;
}
