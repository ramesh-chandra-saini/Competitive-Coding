#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> f1(6,0),f2(6,0);
    for(int i=0,x;i<n;i++)
        cin >> x,f1[x]++;
    for(int i=0,x;i<n;i++)
        cin >> x,f2[x]++;
     int ans=0;
     for(int i=1;i<=5;i++){

        if((f1[i]+f2[i])%2){
            cout<<"-1"<<endl;
            return 0;
        }
        ans+=abs(f1[i]-f2[i])/2;
     }
     cout<<ans/2<<endl;
     return 0;
}
