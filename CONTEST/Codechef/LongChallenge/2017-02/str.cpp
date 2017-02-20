#include<bits/stdc++.h>
using namespace std;

int f(string s,string w,int l,int r){
    string sub = w.substr(l,r);
    cout<<sub<<endl;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        ++ans;
        for(int j=0,k=i;j<w.length();j++,k++){
            if(k>=s.length() || s[k]!=w[j]){
                --ans;break;
            }
        }
    }
    return ans;
}
int main(){
    int n,m,q,k; cin >> n >> m >> q >> k;
    string s; cin >> s;
    int l[m],r[m];
    for(int i=0;i<m;i++)
        cin >> l[i] >> r[i];
    while(q--){
        string w; cin >> w;
        int a,b; cin >> a >> b;
        int ans = 0;
        for(int i=a;i<=b;i++)
            ans+=f(s,w,l[i],r[i]);
        cout<<ans<<endl;
    }
}
