#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q; cin >> n >> q;
    vector<int> arr(n+1); for(int i=1;i<=n;i++) cin >> arr[i];
    while(q--){
        bool flag=false; int D; cin >> D;
        pair<int,int> ans(INT_MAX,INT_MIN);
        int i=1,j=n;
        while(i<n){
            while(i<n&&arr[i]>=arr[i+1])i++;
            if(i==n) break;
            ans.first=i;
            while(i<=n&&arr[i]>=arr[i-1]){
                if(arr[i]-arr[ans.first]==D){
                        ans.second=i; flag=true;break;
                }
                i++;
            } cout<<ans.first<<" "<<ans.second<<endl;
        }


        (flag)?cout<<ans.first<<" "<<ans.second<<endl:cout<<"-1"<<endl;
    }
    return 0;
}
