#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;cin >> n;
    ll arr[n][n];
    ll I=0,J=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==0){
                I=i,J=j;
            }
        }
    }
    if(n==1)cout<<"1"<<endl;
    else{
        ll a=0,b=0;
        if(I==0){
            for(ll j=0;j<n;j++){
                a+=arr[I][j];
            }
            for(ll j=0;j<n;j++){
                b+=arr[I+1][j];
            }
        }else{
            for(ll j=0;j<n;j++){
                b+=arr[I-1][j];
            }
            for(ll j=0;j<n;j++){
                a+=arr[I][j];
            }
        }
        if(a>=b) cout<<"-1"<<endl;
        else{
            arr[I][J]=b-a;

        set<int> s;s.clear();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=arr[i][j];
            }
            s.insert(sum);
        }
        if(s.size()!=1){
            cout<<"-1"<<endl;
        }else{ s.clear();
            for(int j=0;j<n;j++){
                int sum=0;
                for(int i=0;i<n;i++){
                    sum+=arr[i][j];
                }
                s.insert(sum);
            }
            if(s.size()!=1) cout<<"-1"<<endl;
            else{

                int sum1=0,sum2=0;
                for(int i=0,j=0;i<n && j < n ; i++,j++){
                    sum1+=arr[i][j];
                }
                for(int i=0,j=n-1;i<n && j>=0;i++,j--){
                    sum2+=arr[i][j];
                }
                if(sum1!=sum2){
                    cout<<"-1"<<endl;
                }else{
                    cout<<(b-a)<<endl;
                }
            }
        }
    }
    }
    return 0;
}
