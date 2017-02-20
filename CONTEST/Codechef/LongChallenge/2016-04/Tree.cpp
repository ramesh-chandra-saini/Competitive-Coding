#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n); int tree[n+5][2]; tree[1][0]=1; tree[1][1]=0; int hash[n+5]; memset(hash,0,sizeof(hash));
        for(int i=0,x,y,w;i<n-1;i++){
            scanf("%d%d%d",&x,&y,&w); if(x>y) swap(x,y);
            tree[y][0]=x;tree[y][1]=w; hash[x]++;hash[y]++;
        }
        vector<int> Leaf,Releaf; Leaf.clear(); Releaf.clear(); bool Loop = true;
        for(int i = 2;i <= n;i++) if(hash[i] == 1) Leaf.push_back(i);
        int DS[n+5][3]; memset(DS,0,sizeof(DS));
        while(Loop){
            Releaf.clear();
            for(int i=0,x,y,z;i<Leaf.size();i++){
                y=Leaf[i];x=tree[y][0];z=DS[x][1];
                if(DS[x][0]==0){
                    DS[x][0]=1+DS[y][0];DS[x][1]=y;DS[x][2]=tree[y][1]+DS[y][2];
                }else{
                    if(tree[z][1]+DS[z][2]>tree[y][1]+DS[y][2]){
                        DS[x][0]=1+DS[z][0];DS[x][1]=z;DS[x][2]=tree[z][1]+DS[z][2];
                    }else{
                        DS[x][0]=1+DS[y][0];DS[x][1]=y;DS[x][2]=tree[y][1]+DS[y][2];
                    }
                }
                hash[x]--;hash[y]--;
                if(x!=1 && hash[x]==1) Releaf.push_back(x);
            }
            if(Releaf.size()) Leaf=Releaf;
            else Loop = false;
        }
        for(int i=1;i<=n;i++) printf("%d\n",DS[i][2]);
    }
    return 0;
}
