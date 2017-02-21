#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int N,M; cin >> N >> M;
        vector<vector<char> > mat(N+2,vector<char>(M+2,'N'));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin >> mat[i][j];
            }
        }
        bool flag = true;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(mat[i][j]=='B'){

                    if(mat[i+1][j]=='W' || mat[i+1][j]=='A')
                        flag = false;

                }else if(mat[i][j]=='W'){

                        if(mat[i-1][j]=='B')
                            flag = false;
                        if(mat[i][j-1]=='N' || mat[i][j-1]=='A')
                            flag = false;
                        if(mat[i+1][j]=='N' || mat[i+1][j]=='A')
                            flag = false;

                        if(mat[i][j+1]=='N' || mat[i][j+1]=='A')
                            flag = false;
                }else{ //air don't check anything
                }
               // printf("%d ",flag);
                } //printf("\n");
            }
        (flag)?cout<<"yes"<<endl:cout<<"no"<<endl;
    }
    return 0;
}
