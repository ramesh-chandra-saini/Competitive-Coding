#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll unitMat[2][2]={{1,0},{0,1}};
ll fibMat[2][2]={{1,1},{1,0}};
ll invMat[2][2]={{0,1},{1,-1}};
ll result[2][2];
ll sumArr[100005][2][2];
ll   arrN[100005][2][2];
#define gc getchar_unlocked
using namespace std;
typedef ll INT;
inline void read(ll &x){
	register INT c = gc(); x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
inline void write( ll a){
    char snum[35];
    ll i = 0;
    do{
        snum[i++] = a%10 +48;
        a = a/10;
    }while(a!= 0);
    --i;    while(i>=0) putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
}
void copyMat(ll A[2][2],ll B[2][2]){
  A[0][0]=B[0][0],A[0][1]=B[0][1],A[1][0]=B[1][0],A[1][1]=B[1][1];
}
void addMat(ll A[2][2],ll B[2][2],ll res[2][2]){
    res[0][0] = (A[0][0] + B[0][0])%mod;
    res[1][0] = (A[1][0] + B[1][0])%mod;
    res [0][1]= (A[0][1] + B[0][1])%mod;
    res[1][1] = (A[1][1] + B[1][1])%mod;
}
void multMat(ll A[2][2],ll B[2][2],ll res[2][2]){
    res[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%mod;
    res[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%mod;
    res[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%mod;
    res[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%mod;
}
void powMat(ll N[2][2],ll ans[2][2],ll pow){
    for(copyMat(ans,unitMat);pow;pow>>=1){
        if(pow&1)
            multMat(N,ans,result),copyMat(ans,result);
        multMat(N,N,result),copyMat(N,result);
    }
}
ll fastExpo(ll N,ll pw){
    ll ans=1LL;
    for(;pw;pw>>=1){
        if(pw&1) ans=(ans*N)%mod;
        N=(N*N)%mod;
    }  return ans;
}
void calSumArr(ll n){ ll res[2][2];
            for(ll i=1;i<=n;++i){
                multMat(sumArr[i-1],arrN[i],res);
                copyMat(sumArr[i],res);
            }
}
void getINV(ll A[2][2], ll invMatrix[2][2]){
    ll K = ( (A[0][0]*A[1][1]+mod)%mod-(A[1][0]*A[0][1]+mod)%mod+mod)%mod; //cout<<"K :: "<<K<<endl;
    invMatrix[0][0]=A[1][1];     invMatrix[0][1]=mod-A[0][1];
    invMatrix[1][0]=mod-A[1][0]; invMatrix[1][1]=A[0][0];
    ll invMod= fastExpo(K,mod-2);
    invMatrix[0][0]= (invMatrix[0][0]*invMod+mod)%mod;
    invMatrix[1][0] =(invMatrix[1][0]*invMod+mod)%mod;
    invMatrix[0][1]= (invMatrix[0][1]*invMod+mod)%mod;
    invMatrix[1][1] =(invMatrix[1][1]*invMod+mod)%mod;
}
int main(){
   ll n,m,val;    read(n); read(m);
   ll  N[2][2],res[2][2],sum[2][2];
    copyMat(arrN[0],unitMat);copyMat(sumArr[0],unitMat);//fill 0-indexed entry forever
   for(ll i=1;i<=n;++i){
        read(val);
        copyMat(N,fibMat);
        powMat(N,arrN[i],val); //cout<<(arr[i])<<")."<< An[0][0]<<endl;
        addMat(unitMat,arrN[i],arrN[i]);
   }
   calSumArr(n);
   register INT c; ll x,y;
   while(m--){
       c = gc(); for(;(c!=67&& c!=81);c = gc());
        read(x); read(y);
        if(c==67) {
            copyMat(N,fibMat);
            powMat(N,arrN[x],y); //cout<<(arr[i])<<")."<< An[0][0]<<endl;
            addMat(unitMat,arrN[x],arrN[x]);
            calSumArr(n);
        }
        else{
                ll invMatrix[2][2],result[2][2];
                getINV(sumArr[x-1],invMatrix);
                multMat(invMatrix,sumArr[y],result);
                write(result[0][1]);
        }
   }
    return 0;
}
