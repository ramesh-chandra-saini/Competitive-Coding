#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll N,M; cin >> N >> M;
    ll arr[N+1];
    for(ll i=1;i<=N;i++)
        cin >> arr[i];
    while(M--){
        ll L,R,K,ans = -1; cin >> L >> R >> K;
        for(ll i=L;i<=R;){
            ll temp = arr[i],ct=0;
            while(i<=R && temp == arr[i])
                ++ct,++i;
            if(ct>=K)
                ans = temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
