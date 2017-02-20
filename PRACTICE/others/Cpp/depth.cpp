#include<bits/stdc++.h>
using namespace std;
int ans=0;
void DFS(int Id,bool visit[],vector<vector<int> > &Edge ){
    for(int i=0;i<Edge[Id].size();i++){
        if(visit[Edge[Id][i]] == false){
            visit[Edge[Id][i]] =true; ans++;
            DFS(Edge[Id][i],visit,Edge);
        }
    }
    return ;
}
int main(){

    int n,m,x,y,temp;
    scanf("%d%d",&n,&m);
    vector<vector<int> > Edge(n);
    set<pair<int,int> >Eset;
    for(int i=0;i<n;i++)
        Edge[i].clear();
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--,y--;
        Edge[x].push_back(y);
    }
    for(int i=0;i<n;i++) {for(int j=0;j<Edge[i].size();j++) {cout<<"("<<(i+1)<<"-->"<<(1+Edge[i][j])<<") "; }cout<<endl;}
    ans=0;
    bool visit[n];
    for(int i=0;i<n;i++)
        visit[i]=false;
    for(int i=0;i<n;i++){

        if(Edge[i].size() != 0 ){
            visit[i]=true;
            DFS(i,visit,Edge);
        }
    }
    cout<<ans<<endl;
    if(ans <= 1)printf("%d\n",ans);
    else{
        for(int i=2;i*i<=ans;i++){

            while(ans%i==0){
                cout<<i<<" ";ans/=i;
            }
        }
        if(ans!=1) cout<<ans<<" ";
        cout<<endl;

    }

    return 0;
}
