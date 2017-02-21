
/*
*
*   Ramesh Chandra
*   National Institute of Technology Karnataka Surathkal
*
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    ll M = pow(10,9)+7;
    ll T,N;
    cin >> T;

    while(T--){

        cin  >> N;

        ll arr[N+1LL],patt_arr[N+1LL],ans=0;

        for(ll i=0;i<=N;i++)
            cin >> arr[i];

        patt_arr[0]=(2LL*arr[0]) % M;
        for(ll i=1,fact=2;i<=N;i++,fact=(fact*2) % M )
            patt_arr[i]=(fact*arr[i] + patt_arr[i-1]) % M ;

        for(ll i=N,fact=1;i>=1;i--,fact=(fact*2) % M)
            ans=(ans+arr[i] * ( (fact*patt_arr[i-1] )  % M ) ) % M;

        /*
        for(ll i=1LL,fact=2LL;i<=N;i++,fact=(fact*2LL)% M )
            patt_arr[i]=(patt_arr[i-1LL]+ ( ( fact*arr[i] ) % M ) ) % M;
        //for(ll i=0;i<=N; i++) cout<<patt_arr[i]<<" "; cout<<endl;
        for(ll i=N,fact=1LL;i>=1;i--,fact=(fact*2LL)%M )
            ans= ( ans+ ( (arr[i]* (fact*patt_arr[i-1LL]) % M ) % M ) ) % M;
        */
        cout<<ans<<endl;
    }
    return 0;
}
