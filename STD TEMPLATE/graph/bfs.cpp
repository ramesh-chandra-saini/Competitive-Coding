#include<bits/stdc++.h>
using namespace std;

void bfs(int source,int total ,int **adj){

    if(!total) return;

    queue<int> q;
    int ct=1;
    int visit[total+1]; for(int i=0;i<=total;visit[i]=false,i++);
    q.push(source);
    visit[source]=true;

    while(!q.empty()){

        int curr=q.front(); q.pop();
        for(int i=1;i<=total;i++){

            if(!visit[i] && adj[curr][i]){

                    cout<<curr<<"->"<<i<<"   ";
                    visit[i]=true;
                    q.push(i);
            }
        }
    }
    cout<<endl;
    return ;
}
void dfs(int source,int total,int **adj){

    if(!total) return;
    int visit[total+1];
    for(int i=0;i<=total;i++) visit[i]=false;

    stack<int> s; s.push(source);
    visit[source]=true;

    while(!s.empty()){

        int curr=s.top(),i;
        for(i=1;i<=total ;i++){
            if(!visit[i] && adj[curr][i]){

                visit[i]=true;
                s.push(i);
                cout<<curr<<"->"<<i<<"   ";
                break;
            }
        }
        if(i>total) s.pop();
    } cout<<endl;
    return ;
}
void dfsrec(int source,int size,bool *visit,int **adj){

        for(int i=1;i<size;++i){

            if(!visit[i] && adj[source][i]){

                cout<<source<<"->"<<i<<"   ";
                visit[i]=true;
                dfsrec(i,size,visit,adj);
            }
        }
}
int main(){

    int total;
    cout<<"Total number of Node(Vertices) : ";
    cin>>total;
    int size=total+1;
    int **adj=(int**)malloc(size*sizeof(int *));

    for(int i=0;i<size;i++)
        adj[i]=(int *)malloc(size*sizeof(int));

    cout<<"Enter Adjacency Matrix : "<<endl;
    for(int i=1;i<=total;i++)
        for(int j=1;j<=total;j++)
            cin>>adj[i][j];

    cout<<"BFS TRAVERSAL "<<endl; for(int  i=1;i<=total;i++) bfs(i,total,adj);
    cout<<"DFS TRAVERSAL "<<endl;  for(int  i=1;i<=total;i++)  dfs(i,total,adj);
    bool *visit=(bool *)malloc(size*sizeof(bool));
    cout<<"DFS TRAVERSAL "<<endl;
    for(int  i=1;i<=total;i++){
        for(int _i=0;_i<size;visit[_i]=false,_i++);
     visit[i]=true;dfsrec(i,size,visit,adj); cout<<endl;}
    return 0;
}
