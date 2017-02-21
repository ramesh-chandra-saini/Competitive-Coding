#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> vec(1001,0);
        int arr[n],mx=INT_MIN; for(int i=0;i<n;i++) cin >> arr[i],vec[arr[i]]++,mx=max(mx,arr[i]);

            int first=-1,second=-1,i=1000;
            for(;i>=0;i--)
                if(vec[i]>=4) {first=i;second=i;i--;break; }
                else if(vec[i]>=2){first=i;i--;break;}
            if(second<0){
                for(;i>=0;i--)
                    if(vec[i]>=2) {second=i; break;}
            } //cout<<first<<" "<<second<<endl;
            if(first<0 || second<0) cout<<"-1"<<endl;
            else cout<<(first*second)<<endl;
    } return 0;
}
