#include<bits/stdc++.h>
using namespace std;

int R[1000001][100];
int C[1000001][100];
int main(){

    int T;
    scanf("%d",&T);
    while(T--){

        int N,M;
        scanf("%d%d",&N,&M);
        int arr[N][M];
        memset(R,0,sizeof(R));
        memset(C,0,sizeof(C));

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                scanf("%d",&arr[i][j]);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                R[arr[i][j]][i]++,C[arr[i][j]][j]++;

        cout<<endl;
        for(int i=1;i<=3;i++,cout<<endl)
            for(int j=0;j<3;j++)
                cout<<R[i][j]<<" ";
        cout<<endl;
        for(int i=1;i<=3;i++,cout<<endl)
            for(int j=0;j<3;j++)
                cout<<C[i][j]<<" ";
        cout<<endl;

    }
    return 0;
}
