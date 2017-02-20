#include<bits/stdc++.h>
#define debug false
using namespace std;
pair<int,int> mp(int a,int b){
    return make_pair(min(a,b),max(a,b));
}
bool  allVisited(vector<bool>&visit){
	for(int i=1;i<visit.size();i++)
		if(!visit[i])
			return false;
	return true;
}
void printGraph(vector<multiset<int> >&graph){
   if(!debug) return;
   cout<<"\n Graph \n";
    for(int i=1;i<graph.size();i++){
            cout<<"["<<i<<"]";
            for(multiset<int> ::iterator it=graph[i].begin();it!=graph[i].end();++it)
                cout<<*it<<" ";
		}cout<<endl;
}
void DFS(int curr,vector<multiset<int> >&graph,vector<bool>&visited,int&last, set<int>&myset,int &start){
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
    if(debug) {cout<<"["<<curr<<"] --> "<<last<<" ";printGraph(graph);}
    if(next == start){
        if(debug) cout<<"  END"<<endl;
        return;
    }
    return DFS(next,graph,visited,last,myset,start);
}
bool opti(int n,int m,vector<multiset<int> >&graph){
    if(n==1 && m==0)
        return true;
        cout<<"OPTI ";
		vector<bool> visited(n+1,false);
        set<int> myset;
		printGraph(graph);
		bool res = true;
		myset.insert(1);//you are at 1 initially
		int last = 1,start = 1;
		visited[1] = true;
		while(!graph.empty()){
            if(last!=start){
                if(debug) cout<<"NOT A CYCLE"<<endl;
                res = false;
                break;
            }
            for(int i=1;i<=n;i++)
                if(graph[i].empty())
                    myset.erase(i);
            if(myset.empty())
                break;
            if(debug)cout<<"START"<<endl;
            start = *myset.begin();//this should be 1 or already visited
            if(debug)cout<<"root ["<<start<<"] ";
            DFS(start,graph,visited,last,myset,start);
            if(debug)cout<<endl;
		}
        return res && allVisited(visited);
}
bool ans = true;
void DFS(int curr,vector<bool> &visited,vector<multiset<int> >&graph){
    for(multiset<int>::iterator i=graph[curr].begin();i!=graph[curr].end();i++){
        int next = *i;
        if(visited[next]==false){
            visited[next] = true;
            DFS(next,visited,graph);
        }
    }
}
bool BF(int n,int m,vector<multiset<int> >graph){
    if(m==0){
        if(n==1)
            return true;
        return false;
    }
    vector<bool> visited(n+1,false);
		ans = true;
		visited[1] = true;
		DFS(1,visited,graph);
        for(int i=1;i<=n;i++)
            ans = (visited[i]==false)?false:ans;
		for(int i=1;i<=n;i++)
			ans = (graph[i].empty() || graph[i].size()%2)?false:ans;
		return ans;
}
int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(time(NULL));
	int t; scanf("%d",&t); for(int T=0;T<t;T++){ cout<<T<<").";
		int n,m,u,v;
		n=1+rand()%10;m=rand()%10;
		//scanf("%d%d",&n,&m);//cin >> n >> m;
		//cout<<n<<" "<<m<<endl;
		vector<multiset<int> > graph(n+1,multiset<int>());
		for(int i=0;i<m;i++){
            u = 1+rand()%n;v = 1+rand()%n; //cout<<u<<" "<<v<<endl;
            //scanf("%d%d",&u,&v);//			cin >> u >> v ;
            if(u==v) continue;
			graph[u].insert(v);
			graph[v].insert(u);
		}
		vector<multiset<int> > A(graph);
		vector<multiset<int> > cp(graph);
		bool bf = BF(n,m,cp); cout<<bf<<"==";
		bool op = opti(n,m,graph);cout<<op<<endl;
		if(bf!=op){
            cout<<n<<" "<<m<<endl;
              cout<<"\n SEE \n";
            for(int i=1;i<A.size();i++){
                cout<<"["<<i<<"]";
                for(multiset<int> ::iterator it=A[i].begin();it!=A[i].end();++it)
                    cout<<*it<<" ";
                }
            cout<<endl;
            break;
		}
    }return 0;
}
