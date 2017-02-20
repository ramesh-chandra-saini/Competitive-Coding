#include<bits/stdc++.h>
using namespace std;

int main(){

    int r,c,n,k;
    cin >> r >> c >> n >> k;
    bool mat[r][c];
    memset(mat,false,sizeof(mat));
    while(n--){
        int x,y;
        cin >> x >> y;
        mat[x-1][y-1]=true;
    }
    int ans=0;
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            for(int width=1;width<=r-x;width++){
                for(int length=1;length<=c-y;length++){
                    int count=0;
                    for(int i=x;i<x+width && i<r;i++){
                        for(int j=y;j<y+length && j<c;j++){
                            if(mat[i][j]) count++;
                        }
                    }
                    ans+=(count>=k)?1:0;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
