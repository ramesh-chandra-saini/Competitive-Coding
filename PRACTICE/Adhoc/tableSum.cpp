/**

     RAMESH CHANDRA
      NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define s(n) scanf("%lld",&n);

int main(){

    ll n; s(n);
    ll arr[n];
    for(ll i=0;i<n;i++) s(arr[i]);
    set< pair < ll, pair< ll, ll> > > ds;ds.clear();
    for(ll i=0;i<n;i++)
        ds.insert(make_pair( (arr[i]+i +1), make_pair(i+1,arr[i])));
    ll ans[n],add=0;
    set< pair < ll, pair< ll, ll> > > :: iterator it;
    for(int i=0;i<n;i++){
            ans[i]=ds.rbegin()->first+add++;
            pair < ll, pair< ll, ll> > A(n-1-i+1+arr[n-1-i],make_pair(n-1-i+1,arr[n-1-i]));
            ds.erase(A);
            A=make_pair(1-add+arr[n-1-i],make_pair(1-add,arr[n-1-i]));
            ds.insert(A);
    }
    for(int i=0;i<n;i++) printf("%lld ",ans[i]); printf("\n");
    return 0;
}
