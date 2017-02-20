#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

    ll t; cin >> t;
    while(t--){

        ll n,m,i,j,c; cin >> n >> m;
        ll arr[n][n]; memset(arr,0,sizeof(arr));
        while(m--){
            cin >> i >> j >> c; i--,j--;
            arr[i][j]+=c; arr[j][i]+=c;
            //0 - r
            //1 - b

            ll color[n]; memset(color,0,sizeof(color));
            ll ans=INT_MIN;
            for(ll i =0;i<pow(2,n);i++){
            ll temp=i;
                for(ll i=0;i<n;i++,temp/=2) color[i]=temp%2;
                int ctOne=0; for(int i=0;i<n;i++) if(color[i]==1) ctOne++;
                if(ctOne==n/2){
            ll M=0,L=0;

            for(ll i=0;i<n;i++){
                for(ll j=i;j<n;j++){
                    if( color[i] == 0 && color[j] == 0) M+=arr[i][j];
                    if(color[i]==1 && color[j]==1) L+=arr[i][j];
                }
            }
            ans=max(ans, abs(M-L));
            }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
