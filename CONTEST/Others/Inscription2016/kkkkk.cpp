#include<bits/stdc++.h>
using namespace std;
bool ans = true;
void DFS(int curr,vector<bool> &visited,vector<vector<int> >&graph){
    for(int i=0;i<graph[curr].size();i++){
        int next = graph[curr][i];
        if(visited[next]==false){
            visited[next] = true;
            DFS(next,visited,graph);
        }
    }
}
vector<bool> visited(n+1,false);
		ans = true;
		visited[1] = true;
		DFS(1,visited,graph);
        for(int i=1;i<=n;i++)
            ans = (visited[i]==false)?false:ans;
		for(int i=1;i<=n;i++)
			ans = (graph[i].empty() || graph[i].size()%2)?false:ans;
		return (ans||(n==1 && m==0));

		?cout<<"Possible!!"<<endl:cout<<"Danger!!"<<endl;bool bruteFore(){

}
int main(){
	int t; cin >> t; while(t--){
		int n,m,u,v; cin >> n >> m;
		vector<vector<int> > graph(n+1,vector<int>());
		while(m--){
			cin >> u >> v ;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

	}return 0;
}
