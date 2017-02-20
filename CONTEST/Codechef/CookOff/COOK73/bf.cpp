#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t; while(t--){
        int n; cin >> n;
        int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int> A;A.clear();
            for(int j=0;j<n;j++){
                if(i!=j)
                    A.push_back(arr[i]);
            }
            if(isAP(A)){
                ans=min(ans,arr[i]);
            }
        }
        cout<<ans<<endl;
    } return 0;
}
