
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool ans=false;
void Solve( ll N, ll sum, ll low, ll high){

    if(low>high) return;
    ll mid = (low+high)/2LL;
    ll
}
int main(){

    ll T; cin >> T;
    while(T--){

        ll N,Sum,a,d;
        cin >> N >> Sum;
        ans=false;
        Solve(N,Sum,0,Sum);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
