#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum(ll L,ll R,ll cumm[]){
    ll ans = cumm[R];
    if(L>0)
        ans-=cumm[L-1];
    return ans;
}
ll getSum(ll L,ll R,ll N,ll cumm[]){
    if(L>R)
        return sum(L,N-1,cumm)+sum(0LL,R,cumm);
    return sum(L,R,cumm);
}
int main(){
    ll T; scanf("%lld",&T);
    while(T--){
        ll o1,o2; scanf("%lld%lld",&o1,&o2);
        ll N= o1*o2;
        ll arr[N];
        ll cumm[N];
        for(ll i=0;i<N;i++)
            cin >> arr[i],cumm[i]=arr[i];
        for(ll i=1;i<N;i++)
            cumm[i]+=cumm[i-1];

        ll ans = 0;
        for(ll i=0;i<o2;i++){
            ll st_ct = 0 ;
            for(ll j=i,done=0;done<N;){
                ll L = j%N,R=(N+j+o2-1)%N;
                st_ct+=(2*getSum(L,R,N,cumm)>=o2+1);
                j+=o2,done+=o2;
            }
            if(2*st_ct>=o1+1){
                ans = 1;
                break;
            }
        }
        printf("%lld\n",ans);
    }

}
