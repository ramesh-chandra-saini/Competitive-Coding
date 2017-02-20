#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,q;
    cin >> n >> m >> q;

    bool M[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> M[i][j];
    int ans[n]; memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)
        for(int j=0,count=0;j<m;j++)
            if(M[i][j]==0) count=0;
            else count++,ans[i]=max(ans[i],count);
    while(q--){

        int x,y;
        cin >> x >> y;

        M[x-1][y-1]=true xor M[x-1][y-1];
        ans[x-1]=0;
        for(int j=0,count=0;j<m;j++){
            if(M[x-1][j]==0)
                count=0;
            else count++;
            ans[x-1]=max(ans[x-1],count);
        }
        int final_ans=0;
        for(int i=0;i<n;i++)
            final_ans=max(final_ans,ans[i]);
        cout<<final_ans<<endl;
    }
    return 0;
}
