#include<bits/stdc++.h>
using namespace std;
void print(int N,vector<multiset<int> > adj){
    for(int i=1;i<=N;i++){
        cout<<i<<" --> ";
        for(multiset<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    } cout<<endl;
    return ;
}
bool deadlock(int n,vector<set<int> > adj){

    bool flag = true;
    for(int i=1;i<=n;i++){
        flag = (adj[i].empty() || adj[i].size()%2==1)?false:flag;
    }
    return flag;
}
int main(){
    int N,E; cin >> N >> E;
    vector<multiset<int> > adj(N+1,multiset<int>());
    vector<set<int> > ADJ(N+1,set<int>());
    vector<pair<int,int> > edges(E);
    for(int i=0;i<E;i++){
        int u,v; cin >> u >> v;
        edges[i]=(make_pair(u,v));
        adj[u].insert(v);
        adj[v].insert(u);

        ADJ[u].insert(v);
        ADJ[v].insert(u);
    }
    //print(N,adj);
    bool flag = true;
    multiset<int> holder;
    for(int i=1;i<=N;i++){
        holder.insert(i);
        flag = (adj[i].empty()==true || adj[i].size()%2==1)?false:flag;
    }
    vector<multiset<int> > ans(N+1,multiset<int>());
    if(deadlock(N,ADJ)==false){
        printf("NO\n");
    }else{
        printf("YES\n");
        int curr = 1;
        holder.erase(1);
        while(true){
            if(adj[curr].empty()){
                if(holder.empty()){
                    break;
                }else{
                    curr = *holder.begin();
                    holder.erase(curr);
                }
            }else{
                int next = *adj[curr].begin();
                ans[curr].insert(next);
                //printf("%d %d\n",curr,next);
                multiset<int> ::iterator itNext = adj[curr].find(next);
                adj[curr].erase(itNext);
                multiset<int> ::iterator itCurr = adj[next].find(curr);
                adj[next].erase(itCurr);
                curr = next;
                //print(N,adj);
            }
        }
        //printf("\n");
        for(int i=0;i<edges.size();i++){
            int curr = edges[i].first;
            int next = edges[i].second;
            if(ans[curr].find(next)!=ans[curr].end()){
                printf("%d %d\n",curr,next);
            }else{
                printf("%d %d\n",next,curr);
            }
        }
    }
    return 0;
}
