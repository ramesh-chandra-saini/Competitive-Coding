#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll N,ll curr,ll sum,ll arr[]){
    if(curr>sum){  // exceeded curr sum
        return INT_MAX;
    }
    if(N<0){    //no remaining item , choosen all types
        return sum-curr;
    }
/*    if(curr==sum){ //best choosen
        return sum-curr;
    }*/
    return min(  solve(N-1,curr,sum), solve(N,curr+arr[N],sum));

}
int main() {
    int t; cin >> t; while(t--){
        int n,k; cin >> n  >> k ;
        int arr[n]; for(int i=1;i<=n;i++) cin >> arr[i];
        cout<<k-solve(N,0,k,arr)<<endl;
    }  return 0;
}
