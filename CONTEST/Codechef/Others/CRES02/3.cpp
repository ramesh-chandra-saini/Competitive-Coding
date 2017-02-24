#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<INT_MAX<<endl;
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> arr(N);
        for(int i=0;i<N;i++)
            cin >> arr[i];
        vector<int> left = arr;
        for(int i=1;i<N;i++)
            left[i] = max(left[i-1],arr[i]);
        vector<int> right = arr;
        for(int i=1;i<N;i++)
            right[i] = max(right[i-1],arr[i]);
        int ans = 0;
        for(int i=0;i<N;i++)
            ans += min(left[i],right[i])-arr[i];
        cout<<ans<<"\n";
    }
   return 0;
}
