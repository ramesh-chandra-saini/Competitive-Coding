/*
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/

#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

long long int dpA[100001];
long long int dpB[100001];

void fun(int T){

    if(T<=0)
        dpA[0]=1,dpB[0]=0;
    else if(T==1)
        dpA[1]=0, dpB[1]=1;
    else if(T==2)
        dpA[2]=2, dpB[2]=1;
    else {
        if(dpA[T-3]==-1) fun(T-3);
        if(dpA[T-2]==-1) fun(T-2);
        if(dpA[T-1]==-1) fun(T-1);
        dpA[T]=(dpA[T-1]+dpA[T-2]+dpA[T-3])%M;
        dpB[T]=(dpB[T-1]+dpB[T-2]+dpB[T-3])%M;
    }
}

int main(){

    int t,n;
    scanf("%d",&t);

    for(int i=0;i<=100000;i++)
        dpA[i]=dpB[i]=-1;

    while(t--){
        scanf("%d",&n);
        fun(n);
        printf("%lld %lld\n",dpA[n],dpB[n]);
    }
    return 0;
}
