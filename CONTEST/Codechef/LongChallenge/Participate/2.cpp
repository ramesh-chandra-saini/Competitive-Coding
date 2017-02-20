/**
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    int n;scanf("%d",&n);
    ll arr[n];
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    int a=0,b=1;
    long long ans=0;
    while(a<n && b<n){
        if(arr[a]<arr[b]) ans++,a++,b++;
        else b++;
    }
    printf("%lld\n",ans);
    return 0;
}
