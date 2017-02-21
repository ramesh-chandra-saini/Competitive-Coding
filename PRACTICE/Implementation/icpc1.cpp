#include<bits/stdc++.h>
using namespace std;
map<pair<vector<int>,int>,int> dp;
vector<int> removeSame(vector<int> f,int k){
    int idx = 0,mx = 0;
    for(int i=0;i<26;i++)
        if(f[i]>mx)
            mx = f[i],idx = i;
    f[idx]=max(f[idx]-k,0);
    return f;
}
vector<int> removeDiff(vector<int> f,int k){
            for(int i=0,K=0;i<26&&K<k;i++)
                if(f[i])
                    f[i]--,K++;
    return f;
}
int solve(int k,vector<int> freq){

    bool flag = true;
    for(int i=0;i<26;i++)
        if(freq[i]) flag = false;
    if(flag) return 0;
     if(dp.find(make_pair(freq,k))!=dp.end())
        return dp[make_pair(freq,k)];
    return dp[make_pair(freq,k)]=1+min(solve(k,removeSame(freq,k)),solve(k,removeDiff(freq,k)));
}
int main(){
    int t; cin >> t; while(t--){ dp.clear();
        string s; cin >> s;
        int k ; cin >> k;
        vector<int> f(26,0); for(int i=0;i<s.length();i++) f[s[i]-'a']++;
        cout<<solve(k,f)<<endl;
    } return 0;
}
