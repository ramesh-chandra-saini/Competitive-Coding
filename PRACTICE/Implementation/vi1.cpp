#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;  vector<bool> v(m+1,false);
    while(n--){
        int k; cin >> k; while(k--){
            int val; cin >> val; v[val]=true;
        }
    }
        bool ans=true;       for(int i=1;i<=m;i++) ans=ans&v[i];
        (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
}
