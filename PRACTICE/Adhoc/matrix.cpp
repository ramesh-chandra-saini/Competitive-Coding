#include<bits/stdc++.h>
using namespace std;
int **matMult(int s,int m,int n){

    int **arr=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++) arr[i]=(int*)malloc(n*sizeof(int));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=s++;
    int **trans=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)trans[i]=(int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            trans[j][i]=arr[i][j];


    int**ans=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)    ans[i]=(int*)malloc(m*sizeof(int));


    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            ans[i][j]=0;
            for(int k=0;k<n;k++)
                ans[i][j]+=arr[i][k]*trans[k][j];
        }
    }
    return ans;
}
int main(){
    int s,n,m;  cin >> s >> m >> n ;


    int **ans=matMult(s,m,n);
    for(int i=0;i<m;i++,cout<<endl)
        for(int j=0;j<m;j++)
            cout<<ans[i][j]<<" ";
    return 0;
}
