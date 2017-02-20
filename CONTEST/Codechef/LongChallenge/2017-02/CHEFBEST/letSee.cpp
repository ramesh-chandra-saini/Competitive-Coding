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
        ll ans = 0;
        for(ll i=N,pos=N,lastOne=N+1;i>=1;i--){
            if(arr[i]==0){
                ans = max(ans,(pos-i)+(lastOne-i-1));
                --pos;
            }else{
                lastOne = i;
            }
        }
        cout<<ans<<endl;
    }return 0;
}
