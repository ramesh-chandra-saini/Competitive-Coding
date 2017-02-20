#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll t,N,M; cin >> t;
    while(t--){
        cin >> N >> M;
        if( (N == 1 && M == 2 ) || (N == 2&& M == 1) ) cout<<"Yes"<<endl;
        else if(N == 1 || M == 1) cout<<"No"<<endl;
        else if( N%2 == 0 || M%2 == 0 ) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
