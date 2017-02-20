#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

vector<vector<long long int> > matrix_mat(vector<vector<long long int> >&A,
                vector<vector<long long int> >&B){

    vector<vector<long long int> > C(2);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            long long int sum=0;
            for(int k=0;k<2;k++)
                sum+=A[i][k]*B[k][j];
            C[i].push_back((sum%M));
        }
    }
    return C;
}
long long int matMaxExpo(long long int N){

   vector<vector<long long int> > A(2);
    A[0].push_back(1); A[0].push_back(1);
    A[1].push_back(1); A[1].push_back(0);

    vector<vector<long long int> > Ans(A);N--;

    while(N){
        if(N%2)
            Ans=matrix_mat(Ans,A);
        A=matrix_mat(A,A);
        N/=2;
    }
    return Ans[1][0];
}
int main(){

    long long int T,N;
    cin >> T;
    while(T--){
        cin >> N;
        cout<<matMaxExpo(N)<<endl;
    }
    return 0;
}
