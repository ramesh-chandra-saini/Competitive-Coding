#include<bits/stdc++.h>
using namespace std;
bool isPossible(long maxDist, long i, long j,long K,long N,long arr[]){
    if(j>=N-1) //reached till end
        return true;
    if(K<=0) //you're used all moves,yet not reached to end
        return false;
    if(arr[j+1]-arr[i]<=maxDist) //if j+1 can be covered in curr move
        isPossible(maxDist,i,j+1,K,N,arr);//combine this point in curr jump
    else
        isPossible(maxDist,j,j,K-1,N,arr);//take next jump
}
int main(){
    //freopen("in.txt","r",stdin);
    long T; scanf("%ld",&T);
    while(T--){
        long N,K;scanf("%ld%ld",&N,&K);
        long  arr[N];
        for(long i=0;i<N;i++)
            scanf("%ld",&arr[i]);
        long low = arr[i], high = arr[N-1], ans=1e9;
        while(low<=high){
            long mid = (low+high)>>1;
            if(isPossible(mid,0,0,K,N,arr))
                ans = mid,high = mid-1;
            else
                low = mid+1;
        }
        printf("%ld\n",ans);
    }
    return 0;
}
