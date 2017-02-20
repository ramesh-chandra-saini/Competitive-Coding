#include<bits/stdc++.h>
using namespace std;
#define ll long long
void binSearch(vector<ll>&B,ll low,ll high,ll key,ll &idx){
    if(low>high)
        return;
    ll mid = (low+high)/2;
    if(B[mid]>=key){
        idx = mid;
        binSearch(B,low,mid-1,key,idx);
    }else{
        binSearch(B,mid+1,high,key,idx);
    }
}
ll getEnergy(ll m,vector<ll>&box,vector<ll>&arr,ll n,ll k,ll Energy=0LL){
    /*map<ll,ll> my; for(ll i=0;i<n;i++) my[box[i]]++;
    ll N = my.size();
    vector<ll>B(N);vector<ll>freq(N);
    ll p=0;
    for(map<ll,ll>::iterator it = my.begin();it!=my.end();it++,p++){
        B[p]=(it->first);
        freq[p]=(it->second);
    }
    for(int i=1;i<N;i++)
        freq[i]+=freq[i-1];

*/
   vector<ll>freq(m+1,0);
   for(ll i=0;i<n;i++) freq[box[i]]++;
    for(int i=1;i<=m;i++)
        freq[i]+=freq[i-1];
    for(ll i=0;i<n;i++){
        ll ct =freq[m]-freq[box[i]];
        Energy+=ct*arr[(i+k)%n];
    }    return Energy;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t;   cin >> t;
    while(t--){
        ll n,m; cin >> n >> m ;
        vector<ll> arr(n); for(ll i=0;i<n;i++) cin >> arr[i];
        if(m%n==0){
            cout<<"0"<<endl;
            continue;
        }
        ll fans = 1LL<<62;
        sort(arr.begin(),arr.end());
        for(int c=1;c<=m;c++){
            vector<ll> box(n,0);
            ll M = m;
            for(ll i=0;i<n;i++){
                if(M<c){
                    box[i]=M;M=0; break;
                }else{
                    box[i]=c;
                    M-=c;
                }
            } box[n-1]+=M;M=0; // for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
            sort(box.begin(),box.end());
            for(ll k=0;k<n;k++){
                //for(ll i=0;i<n;i++) cout<<box[i]<<" "; cout<<endl;
                fans = min(fans,getEnergy(m,box,arr,n,k));
                /*ll val=box.back(); box.pop_back();
                box.insert(box.begin(),val);*/
            }
        }    cout<<fans<<endl;
    }return 0;
}
