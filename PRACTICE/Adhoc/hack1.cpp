#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n; vector<int> arr(n+1); for(int i=0;i<n;i++) cin >> arr[i];
    long long int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(arr[i]==arr[j] && arr[i]==-1){
                ans+=getNumOfWays(i,j);
            }
        }
    } cout<<ans<<endl;
    return 0;
}
