#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;

}


#include<bits/stdc++.h>
using namespace std;

set<int> adj[1000006];
int   parent[1000006];
int  visited[1000006];
int     dist[1000006];
int    depth[1000006];

int N;
int max_dist;

int bfs(int root,int flag){

    if(flag){
        for(int i=1;i<=N;i++){

            parent[i] = i;
            visited[i] = false;
            dist[i] = 0;
        }
    }

    queue<int> Q;
    Q.push(root);

    parent[root] = root;
    visited[root] = true;
    max_dist = 0;
    dist[root] = 0;
    int endPoint = root;

    while(!Q.empty()){

        int u = Q.front();
       // cout<<u<<" ";
        Q.pop();
        endPoint = u;

        for(set<int>::iterator j=adj[u].begin();j!=adj[u].end();j++){

            int next = *j;

            if(!visited[next]){

                visited[next] = true;
                parent[next] = u;
                dist[next] = dist[u]+1;
                max_dist = max(max_dist,dist[next]);
                Q.push(next);
            }
        }
    }
    //cout<<endl;
    return endPoint;
}

vector<int> getDia(){

    int A = bfs(1,1);
    int B = bfs(A,1);
   // cout<<A << " " << B<<endl;
    int u = B;
    vector<int> diameter;
    while(parent[u]!=u){
        diameter.push_back(u);
        u = parent[u];
    }
    diameter.push_back(u);

    return diameter;
}
pair<int,int> solve(vector<int> &A){

    /*cout<<"A";
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    } cout<<endl;*/

    int mx = INT_MIN;
    int pivot = 0;
    for(int i=0;i<A.size();i++){
        if(mx<i+depth[A[i]]){
            mx = i+depth[A[i]];
            pivot = i;
        }
    }
///   cout<<A[pivot]<<" "<<mx<<endl;


    int p = 0;
    int m_x = INT_MAX;
    for(int i=0;i<=pivot;i++){

        if(max(i,mx-i)<m_x){
            m_x = max(i,mx-i);
            p = i;
        }
    }
   // cout<<A[p]<<" "<<m_x<<endl<<endl;
    return make_pair(A[p],m_x);
}
int main(){

   // freopen("in.txt","r",stdin);

    scanf("%d",&N);

    for(int i=1LL;i<N;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[v].insert(u);
        adj[u].insert(v);
    }

    if(N == 2){

        cout<<0<<endl;
        cout<<1<<" "<<2<<endl;
        return 0;
    }

    vector<int> diameter=getDia();
    /*for(int i=0;i<diameter.size();i++){

        cout<<diameter[i]<<" ";
    } cout<<endl;*/

    ///cut down in tree into forests
    for(int i=1;i<diameter.size();i++){

        int u = diameter[i-1];
        int v = diameter[i];
        adj[v].erase(u);
        adj[u].erase(v);

    }

    for(int i=1;i<=N;i++){
        visited[i]=false;
    }


    for(int i=0;i<diameter.size();i++){

        bfs(diameter[i],0);
        depth[diameter[i]]=max_dist;
        //cout<<diameter[i]<<" "<<max_dist<<endl;
    }

    vector<int> A;
    vector<int> B;

    int mid = (diameter.size()+1)/2;

    ///first
    for(int i=0;i<mid;i++){
        A.push_back(diameter[i]);

    }
    for(int i=diameter.size()-1;i>=mid;i--){
        B.push_back(diameter[i]);
    }

    ///solve for including mid in A

    pair<int,int > A1 = solve(A);
    pair<int,int > B1 = solve(B);

    ///solve for including mid in B

    int mid_point = A.back();
    A.pop_back();
    B.push_back(mid_point);

    pair<int,int > A2 = solve(A);
    pair<int,int > B2 = solve(B);

    if( max(A1.second,B1.second)<max(A2.second,B2.second)){
        cout<<max(A1.second,B1.second)<<endl;
        cout<<A1.first<<" "<<B1.first<<endl;

    }else{

        cout<<max(A2.second,B2.second)<<endl;
        cout<<A2.first<<" "<<B2.first<<endl;

    }
    return 0;
}
