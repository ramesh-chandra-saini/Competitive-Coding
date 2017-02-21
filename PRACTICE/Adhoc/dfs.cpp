#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (1LL<<50)
ll DFS(ll start,vector<vector<pair<ll,ll> > > &graph,ll n,vector<ll>&List){
      vector<ll> dist(n+1,INF);
        set<pair<ll,ll> > nodes; nodes.clear();
        nodes.insert(make_pair(0,start));
        dist[start]=0;
        while(!nodes.empty()){
            ll curr = nodes.begin()->second;
            nodes.erase(nodes.begin());
            for(ll i=0;i<graph[curr].size();i++){
                ll next = graph[curr][i].first;
                ll weight = graph[curr][i].second;
                if(dist[next]>dist[curr]+weight){
                    if(dist[next]!=INF)
                        nodes.erase(make_pair(dist[next],next));
                    dist[next] = dist[curr]+weight;
                    nodes.insert(make_pair(dist[next],next));
                }
            }
        }
       ll ans = 0LL;
      cout<<start<<" --> ";
       for(ll i=0;i<List.size();i++){
            ans+=dist[List[i]]; cout<<dist[List[i]]<<" ";
       } cout<<
       return ans;
}
int main(){
 //   freopen("in.txt","r",stdin);
    ll t;cin >> t; while(t--){
        ll n,m; cin >> n >> m ;
        vector<vector<pair<ll,ll> > > graph(n+1LL,vector<pair<ll,ll> >());
        for(ll i=0,u,v,w;i<n-1;i++){
            cin>>u>>v>>w;
            graph[u].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(u,w));
        }
        vector<ll> List(m); for(ll i=0;i<m;i++) cin >> List[i];
        ll Ans = 0;
        for(ll i=0;i<m;i++){
            Ans+=DFS(List[i],graph,n,List);
        }
        ll N = m*m;
        ll gcd = __gcd(Ans,N);
        cout<<Ans/gcd<<" "<<N/gcd<<endl;

    }
    return 0;
}
