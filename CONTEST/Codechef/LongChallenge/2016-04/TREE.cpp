#include<bits/stdc++.h>
using namespace std;
int main(){

    int t; scanf("%d",&t);
    while(t--){
        int n,;scanf("%d",&n); if(n==1){printf("0\n");}
        int Graph[n+1][n+1],hash[n+1]; int Tree[n+1][2]; memset(Tree,0,sizeof(Tree));
        memset(Graph,0,sizeof(Graph));memset(hash,0,sizeof(hash));
        for(int i=0,x,y,w;i<n-1;i++){
            scanf("%d%d%d",&x,&y,&w); if(x>y) swap(x,y);
            Tree[y][0]=x; Tree[y][1]=w;Graph[x][y]=Graph[y][x]=w;hash[x]++; hash[y++];
        }
        vector<vector<int> > RealLeaf(n+1); for(int i=0;i<=n;i++) RealLeaf.clear();
        int arrLeaf[n+1],arrLeafSize=0; int ans[n+1]; memset(ans,0,sizeof(ans));
        for(int i=2;i<=n;i++){ if(hash[i]==1){arrLeaf[arrLeafSize++]=i; ans[i]=0;} }
    }
    return 0;
}
