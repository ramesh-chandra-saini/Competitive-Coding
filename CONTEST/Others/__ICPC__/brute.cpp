#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isGood(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    for(int i=0;i<n-1;i++)
        if(arr[i+1]%arr[i])
            return false;
    return true;
}
ll BF(ll n,int arr[]){
    ll N = (1LL<<n);
        ll ans = 0;
        for(ll i=1;i<N;i++){
            ll temp = i;
            vector<int> curr; curr.empty();
            for(int j=0;temp;temp/=2LL,j++)
                if(temp%2LL)
                    curr.push_back(arr[j]);
             bool check = isGood(curr);//cout<<check<<" --> ";for(int j=0;j<curr.size();j++) cout<<curr[j]<<" "; cout<<endl;
            ans+=(check)?1:0;
        }
        return ans;
}
int main(){
    int t; cin >> t;

    while(t--){
        int n;    cin >> n;
        int arr[n];for(int i=0;i<n;i++) cin >> arr[i];
        ll bf = BF(n,arr);
        cout<<bf<<endl;

    }

}
