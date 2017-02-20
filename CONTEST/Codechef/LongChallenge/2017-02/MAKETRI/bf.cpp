#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll N,L,R; cin >> N >> L >> R;
    ll arr[N];
    for(ll i=0;i<N;i++)
        cin >> arr[i];
    ll ans = 0;
    for(ll X = L;X<=R;X++){
        bool check = false;
        for(ll i=0;i<N;i++){
            for(ll j=i+1;j<N;j++){
                ll  side[] = {arr[i],arr[j],X};
                sort(side,side+3);
                ll a = side[0],b=side[1],c=side[2];

                check = (a+b>c)?true:check;
            }
        }
        ans+=check;
    }
    cout<<ans<<endl;
    return 0;
}
