/*
    RAMESH CHANDRA 2 OCT 2015
    NATIONAL INSTITUTE OF TECHNOLOGY
    KARNATAKA SURATHKAL
    https://www.facebook.com/rameshc10695

    Simple
    Sorting, Combination
*/
#include<bits/stdc++.h>
using namespace std;


vector<int> fit;
int dp[100005][1003];
int main(){


    int n,m,c;

    scanf("%d%d%d",&n,&m,&c);

    int N[n];
    for(int i=0;i<n;i++){

        scanf("%d",&N[i]);
    }

    int M[m];
    for(int i=0;i<m;i++){

        scanf("%d",&M[i]);
    }

    sort(N,N+n);
    sort(M,M+m);

     for(int i=0,j=0;i<n && j<m;){

        int curr=N[i];
        int _n=0;
        int _m=0;

        for(;i<n && curr==N[i];_n++,i++);
        for(;j<m && curr==M[j];_m++,j++);

        if(_n &&  _m) fit.push_back(_n*_m);
     }
    memset(dp,0,sizeof(dp));

    int size=fit.size();

    /**********Now Time To Find DP State....How to construct DP*************/

    for(int i=0;i<size;i++){


    }

     return 0;
}
