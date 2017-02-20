#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> path;
void DFS(ll curr, ll target,ll ans,ll &XOR,ll arr[],vector<set<ll> >&tree,vector<bool>&visit){
    if(curr==target){
        XOR=ans;
        return;
    }
    for(set<ll>::iterator i=tree[curr].begin();i!=tree[curr].end();i++){
        ll node = *i;
        if(visit[node]==false){
            visit[node]=true; //cout<<node<<"";
            ans=(ans ^ arr[node]);
            DFS(node,target,ans,XOR,arr,tree,visit);
            ans=(ans ^ arr[node]);
        }
    }
    return;
}

int main(){
    ll t; cin >> t;while(t--){
        ll n; cin >> n;
        ll arr[n+1]; for(ll i=1;i<=n;i++) cin >> arr[i];
        vector<set<ll> > tree(n+1,set<ll>());
        for(ll i=1,u,v;i<n;i++){
            cin >> u  >> v;
            tree[u].insert(v),tree[v].insert(u);
        }
        vector<ll> parent(n+1,0);
        vector<bool> visit(n+1,0);
        queue<ll> que;
        que.push(1), parent[1]=0,visit[1]=true;
        while(!que.empty()){
            queue<ll> nextQue;
            while(!que.empty()){
                ll node = que.front(); que.pop();
                for(set<ll> ::iterator it = tree[node].begin();it!=tree[node].end();++it)
                    if(visit[*it]==false)
                        parent[*it]=node,nextQue.push(*it),visit[*it]=true;
            }
            que=nextQue;
        }

        map<ll,set<ll> > myMap;for(int i=1;i<=n;i++)          myMap[i].insert(i);
        for(ll i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(ll curr=j;parent[curr]!=0; curr=parent[curr]){
                    if(parent[curr]==i){
                        myMap[i].insert(j); break;
                    }
                }
            }
        }
        map<pair<ll,ll>,ll > yourMap;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                ll curr=i,target=j;
                ll XOR =arr[curr],ans=arr[curr];
                vector<bool>  visit(n+1,false);
                DFS(curr,target,ans,XOR,arr,tree,visit);
                yourMap[make_pair(i,j)]=XOR;
            }
        }

       // for(map<ll,set<ll> >::iterator it=myMap.begin();it!=myMap.end();++it){ cout<<it->first<<" "; for(set<ll> ::iterator sit = it->second.begin();sit!=it->second.end();++sit){ cout<<*sit<<" ";   } cout<<endl;     }
       // for(ll i=1;i<=n;i++)      cout<<i<<"["<<parent[i]<<"] "; cout<<endl;
        for(ll node = 1;node<=n;node++){
            vector<ll> childs;childs.clear();
            ll ans=0;
            for(set<ll> ::iterator sit = myMap[node].begin();sit!=myMap[node].end();++sit)
                childs.push_back(*sit);
            for(int i=0;i<childs.size();i++)
                for(int j=0;j<childs.size();j++)
                    ans=max(ans,yourMap[make_pair(childs[i],childs[j])]);
            cout<<ans<<endl;
        }
    }
    return 0;
}
