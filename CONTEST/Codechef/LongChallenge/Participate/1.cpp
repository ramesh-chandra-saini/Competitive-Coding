/**
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define s(x) scanf("%lld",&x);
#define sf(x) scanf("%f",&x);
#define p(x) printf("%lld ",x);
#define pf(x) printf("%f ",x);
#define line printf("\n")
#define mp make_pair
#define pb push_back
#define pair pair<ll,ll>
int main(){

    ll arr[2];
    scanf("%lld%lld",&arr[0],&arr[1]);
    bool stop=true;
    long long int ans=0;
    while(stop){

        if(arr[0]<=arr[1]) arr[0]++,arr[1]-=2;
        else arr[1]++,arr[0]-=2;
        if(arr[0]>=0 && arr[1]>=0) ans++;
        if(arr[0]<=0 || arr[1]<=0) stop =false;
    }
    printf("%lld\n",ans);
    return 0;
}
