#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll T; cin >> T;
    while(T--){
        ll N; cin >> N;
        ll arr[N+1],ans=0;
        for(ll i=1;i<=N;i++)
            cin >> arr[i];
        while(true){
            ll done = true;
            for(ll i=N;i>=2;){
                if(arr[i-1]==0 && arr[i] == 1){
                    done = false;
                    swap(arr[i-1],arr[i]);
                    i-=2;
                } else{
                    i-=1;
                }
            }
            if(done) break;
            ++ans;
        }
        cout<<ans<<endl;
    }return 0;
}
