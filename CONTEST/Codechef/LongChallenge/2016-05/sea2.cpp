#include<bits/stdc++.h>
using namespace std;
vector<int> primeFactor(int i){
    vector<int> factor; factor.clear();
    if(i%2==0) factor.push_back(2);
    if(i%3==0) factor.push_back(3);
    if(i%5==0) factor.push_back(5);
    if(i%7==0) factor.push_back(7);
    return factor;
}
int solve( int pos,int n,vector<bool> &M,int m){
    if(pos==n) return 1;
    int ans=0;
    for(int i=1;i<=m;i++){
        if(M[i]==true){
            vector<int> p=primeFactor(i);
            vector<bool>__m(M);
            for(int j=0;j<p.size();j++){
               for(int k=p[j];k<=m;k+=p[j])
                    __m[k]=false;
            }
            ans+=solve(pos+1,n,__m,m);
        }
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,m,pos=0; cin >> n >> m;
        vector<bool> M(m+1); M[0]=false;for(int i=1;i<=m;i++) M[i]=true;
        cout<<solve(pos,n,M,m)<<endl;
    }
}
