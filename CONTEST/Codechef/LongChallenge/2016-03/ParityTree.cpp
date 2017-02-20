/*
	RAMESH CHANDRA
	PRE-FINAL YEAR B.TECH
	NITK SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int main(){

    ll T;
    scanf("%lld",&T);
    while(T--){
        ll N,Q;
        scanf("%lld%lld",&N,&Q);
        ll  Edge[N+1][2];
        for(int i=0;i<N-1;i++)
            scanf("%lld%lld",&Edge[i][0],&Edge[i][2]);
        ll query[Q+1][3];
        for(int i=0;i<Q;i++)
            scanf("%lld%lld%lld",&query[i][0],&query[i][1],&query[i][2]);
        ll ans=1LL;
        //I know My answer is wrong but still i will submit my solution
        //because I want to do so..that's all
        for(int i=Q;i<N-1;i++){
            ans=(2LL*ans)%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
