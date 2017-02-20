#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,I,J,k; cin >> n >> m >> I >> J >> k;
//    n=m=9;I=J=5;k=3;

    vector<vector<bool> > mat(n+2,vector<bool>(m+2,false));

    for(int i=I ;i>=max(1,I-k);i--){
        for(int j=min(m,J+k-(I-i));j>=J;j--){
            mat[i][j]=true;
        }
    }
    for(int i=I ;i>=max(1,I-k);i--){
        for(int j=max(1,J-k+(I-i) );j<=J;j++){
            mat[i][j]=true;
        }
    }
    for(int i=I ;i<=min(n,I+k);i++){
        for(int j=max(1,J-k+(i-I));j<=J;j++){
            mat[i][j]=true;
        }
    }
    for(int i=I ;i<=min(n,I+k);i++){
        for(int j=min(m,J+k-(i-I));j>=J;j--){
            mat[i][j]=true;
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mat[i][j]<<" ";
        } cout<<endl;
    }
    return 0;
}
