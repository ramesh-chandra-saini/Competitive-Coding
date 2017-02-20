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
int solve( int pos,int n,set<int>&M){
    if(pos==n) return 1;
    if(M.size()==0) return 0;

    int ans=0;
    for(set<int> :: iterator i=M.begin();i!=M.end();++i){
            vector<int> p=primeFactor(*i);
            set<int>__m(M);
            for(int j=0;j<p.size();j++){
               for(set<int> :: iterator k=__m.begin();k!=__m.end();){
                    if(__gcd(*k,p[j])>1) __m.erase(k++);
                    else ++k;
               }
            }
            ans+=solve(pos+1,n,__m);
        }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,m,pos=0; cin >> n >> m;
        set<int> M;M.clear(); for(int i=1;i<=m;i++) M.insert(i);
        cout<<solve(pos,n,M)<<endl;
    }
}
