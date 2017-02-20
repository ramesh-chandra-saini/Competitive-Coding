#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define gc getchar_unlocked
inline void read(int &x){
	register int c = gc();	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
ll __power(ll N){
    ll ans=1LL;int expo=1000000005;
    for(;expo; N=(N*N)%MOD,expo>>=1)
        if(expo&1) ans=(ans*N)%MOD;
    return ans;
}
void preprocessing(vector<vector<int > > &DS,vector<int>&SIZE,int N){
    DS[0].clear();SIZE[0]=0;int sz=0,i;
    for(int n=1;n<=N;n++){ sz=0,i=1;
        for(;i*i<n;i++)
            if(n%i==0)  DS[n][sz++]=i,DS[n][sz++]=n/i;
        if(i*i==n) DS[n][sz++]=i;
        SIZE[n]=sz;
    }
}
void bigTestCases(int N){
 int arr[N]; for(int i=0;i<N;i++) read(arr[i]);// scanf("%d",&arr[i]);
int Q,q; read(Q); //scanf("%d",&Q);
   vector<vector<int> > DS(N+1,vector<int>(150));
   vector<int>  SIZE(N+1);
    preprocessing(DS,SIZE,N);
    vector<long double> DP(N+1);
    vector<ll> ans(N+1);
    DP[0]=0.0;ans[0]=1LL;
    for(int r=1;r<=N;r++){
        DP[r]=0.0,ans[r]=1LL;
        for(ll i=1;i*r<N;i++){
            DP[r]+=log10(arr[i*r]);
            ans[r]=(ans[r]*arr[i*r])%MOD;
        }
    }
    int p,f,idx,r,oldValue,newValue;
    long double Digit;
    map<int,int> Query;
    map<int,int>::iterator it;
    while(Q--){
         read(q);//   scanf("%d",&q);
        if(q==1){
           read(p);read(f);p-=1;
           Query[p]=f;
        } else{
            for(it=Query.begin();it!=Query.end();++it){
                p=it->first,f=it->second,Query.erase(it);
                oldValue=arr[p],arr[p]=f,newValue=arr[p];
                for(int i=0;i<SIZE[p];++i){
                    idx=DS[p][i];
                    ans[idx]=((ans[idx]*__power(oldValue) %MOD)*newValue)%MOD;
                    DP[idx]=DP[idx]-log10(oldValue)+log10(newValue);
                }
            }
             read(r);Digit=DP[r]+log10(arr[0]);
            printf("%d %d\n",int(pow(10,Digit-floor(Digit))),(ans[r]*arr[0])%MOD);
        }
    }
}
void smallTestCases(ll N){
    ll arr[N]; for(ll i=0;i<N;i++) scanf("%lld",&arr[i]);
    ll Q,q,p,f,r; scanf("%lld",&Q); //cout<<Q<<endl;
     ll ANS,DIGIT,D;
      while(Q--){
         scanf("%lld",&q);
         if(q==1){
            scanf("%lld%lld",&p,&f);p-=1;arr[p]=f; //cout<<p<<" "<<f<<endl;
          } else if(q==2){
             scanf("%lld",&r); ANS=1LL;DIGIT=1LL;
             for(int i=0;i*r<N;i++){
                ANS=(ANS*arr[i*r])%MOD;
                DIGIT=(DIGIT*arr[i*r]);
            }
            do{D=DIGIT%10; DIGIT/=10LL;} while(DIGIT);
            printf("%lld %lld\n",D,ANS);
        }
    }
}
int main(){
    int N; read(N); //scanf("%d",&N);
   if(N<=10) smallTestCases(N);
   else bigTestCases(N);
    return 0;
}
