#include<bits/stdc++.h>
using namespace std;
map< pair<int,int> ,int > edges;
set<int> myset;
int last = 1;
pair<int,int> mp(int a,int b){
    return make_pair(min(a,b),max(a,b));
}
bool  allVisited(vector<bool>&visit){
	for(int i=1;i<visit.size();i++)
		if(!visit[i])
			return false;
	return true;
}
void DFS(int curr,vector<vector<int> >&graph,vector<bool>&visit){
    last = curr;
    for(int i=0;i<graph[curr].size();i++){
        int next = graph[curr][i];
        myset.insert(next);
        visit[next] = true;
        if(edges.find(mp(curr,next))==edges.end()){
            continue;
        }else{
            int ct = edges[mp(curr,next)];
            edges[mp(curr,next)]--;
            if(ct==1)
                edges.erase(mp(curr,next));
                last = next;
                cout<<" --> "<<last<<" ";
            return DFS(next,graph,visit);
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
	int t; cin >> t; while(t--){
        edges.clear();
		int n,m,u,v; cin >> n >> m;
		vector<vector<int> > graph(n+1,vector<int>());
		vector<bool> visit(n+1,false);
		while(m--){
			cin >> u >> v ;
			edges[mp(u,v)]++;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
        ll res = true;
		myset.insert(1);
		last = 1;
		start = 1;
		while(!edges.empty()){
            if(last!=start){
                res = false;
                break;
            }



		}



		last = 1;visit[1]=true;

		cout<<"1 ";
		DFS(1,graph,visit);
        cout<<endl;
		cout<<"last "<<last<<endl;
		for(int i=1;i<=n;i++) cout<<visit[i]<<" "; cout<<endl;
		for(map< pair<int,int> ,int > ::iterator it=edges.begin();it!=edges.end();++it){
            cout<<"["<<it->first.first<<" "<<it->first.second<<"] "<<it->second<<endl;
		}
		int root = 1; myset.insert(1);


		/*while(!edges.empty()){


            bool flag = false;
            if(root != last){
                break;
            }
            for(int i=1;i<=n;i++){
                if(edges)
            }
            for(int i = 1;i<=n;i++){

            }
		}*/

        (edges.empty()&&last==1 && allVisited(visit))?cout<<"Possible!!"<<endl:cout<<"Danger!!"<<endl;
	}return 0;
}
