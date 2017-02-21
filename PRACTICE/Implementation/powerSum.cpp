#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll MAT[303][303];
ll newMat[303][303];
ll R[303][303];
ll mat[303][303];
ll n;
inline ll power(ll exp){
    return exp%2?-1LL:1LL;
}
ll fastExpo(ll N,ll exp){
    ll ans=1LL;
    for(;exp;exp/=2LL,N=(N*N)%mod)
        ans=(exp%2)?(N*ans)%mod:ans%mod;
    return ans;
}
void multiply(long long P[][303], long long Q[][303])
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            R[i][j] = 0;

            for(int k=1; k<=n; k++)
                R[i][j] = (R[i][j] + P[i][k]*Q[k][j])%mod;
        }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            P[i][j] = R[i][j];
}

void expo(long long N)
{
    if(N==1)
        return;

    expo(N/2);
    multiply(newMat, newMat);

    if(N%2)
        multiply(newMat, mat);
}

int main(){
    ll p[5005];
    ll e[5005];
    for(ll i=2;i<=300;i++)
        mat[i][i-1]=1LL;
    ll t,x,ans; scanf("%lld",&t);while(t--){
        ll Q; scanf("%lld%lld",&n,&Q);
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
        e[0]=1LL;
        for(ll k=1LL;k<=n;k++){
            e[k]=0LL;
            for(ll i=1LL;i<=k;i++)
                e[k]=(mod+e[k]+power(i+1)*e[k-i]*p[i])%mod;
            e[k]=(e[k]*fastExpo(k,mod-2))%mod;
        }
        /*for(ll k=n+1;k<=5000;k++){
            p[k]=0LL;
            for(ll i=k-n;i<=k-1;i++)
                p[k] =(mod+p[k]+power(k-1+i)*e[k-i]*p[i])%mod;
       }*/
        for(ll i=1;i<=n;i++)
            mat[1][i]=power(i+1)*e[i];

        while(Q--){
            scanf("%lld",&x);
            ans=0LL;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    newMat[i][j]=mat[i][j];
            expo(x-n);
            for(ll i=1;i<=n;i++)
                ans=(mod+ans+newMat[1][i]*p[n-i+1])%mod;
            printf("%lld ",ans);
       } printf("\n");
    }
    return 0;
}
