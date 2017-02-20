#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void modifiedBinarySearch(ll arr[],ll stidx,ll endidx,ll key,ll &idx){
    if(stidx>endidx) return ;
    if(arr[(stidx+endidx)/2LL]<key) return modifiedBinarySearch(arr,(stidx+endidx)/2LL+1,endidx,key,idx=(stidx+endidx)/2LL);
    return  modifiedBinarySearch(arr,stidx,(stidx+endidx)/2LL-1,key,idx);
}
int main(){
    ll n,k,idx,ans=0LL;
    scanf("%lld%lld",&n,&k);
    ll arr[n];
    for(ll i=0;i<n;i++)scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    for(ll i=0;i<n-1;i++) modifiedBinarySearch(arr,i+1,n-1,k-arr[i],idx=i),ans+=(idx-i);
    printf("%lld\n",ans);return 0;
}
