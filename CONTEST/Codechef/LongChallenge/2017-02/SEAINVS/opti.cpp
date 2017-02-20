#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define pc putchar_unlocked
#define gc getchar_unlocked
inline void read(ll &x)
{
	register ll c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
inline void write(long long int a)
{
    char snum[35];
    int i = 0;
    do
    {
        snum[i++] = a%10 +48;
        a = a/10;

    }while(a!= 0);
    --i;
    while(i>=0)
        pc(snum[i--]);
    pc('\n');
}
int main(){

    ll T; read(T);
    while(T--){
        ll N,M; read(N),read(M);
        ll P[N+1];

        for(ll i=1;i<=N;i++)
            read(P[i]);
        vector<ll> left,right;
        while(M--){
            ll l1,r1,l2,r2; read(l1),read(r1),read(l2),read(r2);
            ll S = r1-l1+1;
             left.clear(),right.clear();
            for(ll i=l1,j=l2;i<=r1 && j<=r2;i++,j++)
                left.push_back(P[i]),
                right.push_back(P[j]);
            sort(left.begin(),left.end());
            sort(right.begin(),right.end());
            ll ans = 1LL,i=0,ct=0;
            for(ll j=0;j<right.size();j++){
                for(;i<left.size();i++){
                    if(left[i]<right[j])
                        ct++;
                    else
                        break;
                }
                ans = (ans*(ct-j))%MOD;
            }
            write(ans);
        }
    }
    return 0;
}
