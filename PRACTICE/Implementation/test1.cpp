#include<bits/stdc++.h>
 using namespace std;
 #define ll int
 #define MOD 1000000007
 void dfs(ll curr,vector<ll>&visited,vector<vector<ll> >&adj,ll &ct,vector<ll>&colorList,ll color){
     for(ll j=0;j<adj[curr].size();j++){
         ll next = adj[curr][j];
         if(visited[next]==false && colorList[next]==color){
             visited[next]=true, ++ct;
             dfs(next,visited,adj,ct,colorList,color);
         }
     }
 }
 bool safe(ll n,vector<vector<ll> >&adj,vector<ll>&colorList,ll color){
     vector<ll> visited(n+1,false);
     bool isSafe = true;
     ll ct = 0;
     for(ll i=1;i<=n;i++){
         if(visited[i]==false && colorList[i]==color){
             visited[i]=true,ct=1;
             dfs(i,visited,adj,ct,colorList,color);
             if(ct==1){
                 isSafe = false;
                 break;
             }
         }
     }
     return isSafe;
 }
 int main(){
     ll n; cin >> n;
     vector<vector<ll> > adj(n+1,vector<ll>());
     for(ll i=1;i<=n-1;i++){
         ll u,v; cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     ll ans = 0;
     vector<ll> colorList(n+1,0);
     while(true){
         bool reggy = safe(n,adj,colorList,0); ///reggy --> 0
         bool betty = safe(n,adj,colorList,1); ///betty --> 1
         ans+=(reggy & betty);
         ll bits = 0;
         for(ll i=1;i<=n;i++)
             bits+=colorList[i];
        /* ll N = 0;
         for(int i=1;i<=n;i++)
            N=N*2+colorList[i],cout<<colorList[i]; cout<<"  -->  "<<N<<endl;
           */
         if(bits==n)
             break;
         colorList[n]++;
         ll carry = 0,temp;
         for(int i=n;i>=1;i--){
             temp = carry + colorList[i];
             colorList[i] = temp%2;
             carry = temp/2;
         }

     };
     cout<<(ans%MOD)<<endl;
 }
