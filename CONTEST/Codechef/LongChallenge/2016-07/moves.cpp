#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,m,x,y,k;
     cin >> n >> m >> x >> y >> k;
     //n=m=9;x=y=4;k=3;
    vector<vector<bool> > matrix(n+1,vector<bool>(m+1,false));

   ///1st quardrant
    for(int i=y-k;i<=y;i++){
        for(int j=x+(i-(y-k));j>=x;j--){
            matrix[i][j]=true;
        }
    }
   ///2nd quardrant
    for(int i=y-k;i<=y;i++){
        for(int j=x-(i-(y-k));j<=x;j++){
            matrix[i][j]=true;
        }
    }
///3rd quardrant
    for(int i=y+k;i>=y;i--){
        for(int j=x-((y+k)-i);j<=x;j++){
            matrix[i][j]=true;
        }
    }

    ///4th quardrant
    for(int i=y+k;i>=y;i--){
        for(int j=x+(y+k-i);j>=x;j--){
            matrix[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<matrix[i][j]<<" ";
        } cout<<endl;
    }
    return 0;
}
