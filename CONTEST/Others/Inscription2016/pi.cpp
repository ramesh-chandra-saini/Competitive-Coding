#include<bits/stdc++.h>
#define debug false
using namespace std;
set<int> myset;
int last = 1;
int start = 1;
pair<int,int> mp(int a,int b){
    return make_pair(min(a,b),max(a,b));
}
bool  allVisited(vector<bool>&visit){
	for(int i=1;i<visit.size();i++)
		if(!visit[i])
			return false;
	return true;
}
void DFS(int curr,vector<multiset<int> >&graph,vector<bool>&visited){
    if(graph[curr].empty())
        return ;
    int next = *graph[curr].begin();

    multiset<int>::iterator i = graph[curr].find(next);
    multiset<int>::iterator j = graph[next].find(curr);
    graph[curr].erase(i);
    graph[next].erase(j);

    myset.insert(next);
    visited[next] = true;
    last = next;
    if(next == start){
        return;
    }
    return DFS(next,graph,visited);
}
int main(){

	int t; scanf("%d",&t); while(t--){
		int n,m,u,v; scanf("%d%d",&n,&m);//cin >> n >> m;
		vector<multiset<int> > graph(n+1,multiset<int>());
		vector<bool> visited(n+1,false);
		while(m--){
            scanf("%d%d",&u,&v);//			cin >> u >> v ;
			if(u==v) continue;
			graph[u].insert(v);
			graph[v].insert(u);
		}
		bool res = true;
		myset.insert(1);//you are at 1 initially
		last = 1;start = 1;
		visited[1] = true;
		while(!graph.empty()){
            if(last!=start){
                res = false;
                break;
            }
            for (set<int>::iterator it = myset.begin(); it != myset.end(); ) {
                if (graph[*it].empty()) {
                     myset.erase(it++);
                }
                else {
                    ++it;
                }
            }
            if(myset.empty())
                break;
            start = *myset.begin();//this should be 1 or already visited
            DFS(start,graph,visited);
		}
        ((n==1 && m==0)||(res && allVisited(visited)))? printf("Possible!!\n"):printf("Danger!!\n");
    }return 0;
}
