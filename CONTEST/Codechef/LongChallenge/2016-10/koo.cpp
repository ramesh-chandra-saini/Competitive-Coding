#include<bits/stdc++.h>
using namespace std;
set<int> colors;
void dfs(int node,vector<set<int > >&adj,vector<bool>&visited,vector<int>&a){
    for(set<int>::iterator it=adj[node].begin();it!=adj[node].end();it++)
        if(!visited[*it])
            visited[*it]=true,colors.insert(*it),dfs(*it,adj,visited,a);

}
int main(){
    int n,m,k,l,r; cin>>n>>m>>k;
    vector<int> a(n+1);for(int i=1;i<=n;i++)  cin>>a[i];
    vector<set<int> >adj(n+1,set<int>());
    while(m--)
        cin>>l>>r,adj[l].insert(r),adj[r].insert(l);
    int ans=0;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            colors.clear();  colors.insert(i);
            visited[i]=true;
            dfs(i,adj,visited,a);
            map<int,int> see;
            for(set<int>::iterator it = colors.begin();it!=colors.end();++it)
                see[a[*it]]++;
            int freq = INT_MIN;
            int final_color = 0;
            for(map<int,int>::iterator it=see.begin();it!=see.end();it++)
                if(it->second>freq)
                    final_color=it->first,freq= it->second;
            for(set<int>::iterator it = colors.begin();it!=colors.end();++it)
               if(final_color!=a[*it])
                    ans++;
        }
    }
    cout<<ans<<endl;
return 0;
}
