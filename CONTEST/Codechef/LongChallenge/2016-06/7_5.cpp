#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll __power(ll N){
    ll ans=1LL;int expo=1000000005;
    for(;expo; N=(N*N)%MOD,expo>>=1)
        if(expo&1)
            ans=(ans*N)%MOD;
    return ans;
}
void preprocessing(vector<set<int > > &DS,int N){
    DS[0].clear();
    for(int n=1;n<=N;n++)
        for(int i=1;i*i<=n;i++)
            if(n%i==0) DS[n].insert(i),DS[n].insert(n/i);
}
int DIGIT(long double N){

if(N<0.30103) return 1;
if(N<0.477121) return 2;
if(N<0.60206) return 3;
if(N<0.69897) return 4;
if(N<0.778151) return 5;
if(N<0.845098) return 6;
if(N<0.90309) return 7;
if(N<0.954243) return 8;
return 9;
}
int start=0,size=0;
int mult[9000000];
int arr2[9000000];
void multiply(ll N){

    ll temp=0LL;
    int carry=0;
    start=max(0,size-9);
    for(ll i=start;i<size;i++){
        temp=carry+N*mult[i];
    mult[i]=temp%10;
        carry=temp/10;
    }
    while(carry) mult[size++]=(carry%10), carry/=10;
}
void SolveBig(int N,int Q,int arrQuery[][5]){
    vector<set<int> > DS(N+1);
    preprocessing(DS,N);
    vector<long double> DP(N+1);
    vector<ll> ans(N+1);
    DP[0]=0.0;ans[0]=1LL;
    for(int r=1;r<=N;r++){
        DP[r]=0.0,ans[r]=1LL;
        for(ll i=1;i*r<N;i++){
            DP[r]+=log10(arr2[i*r]);
            ans[r]=(ans[r]*arr2[i*r])%MOD;
        }
    }
    int q,p,f,idx,r,oldValue,newValue;
    int ANS[Q][2];
    for(int k=0;k<Q;k++){
        if(arrQuery[k][0]==1){
           p=arrQuery[k][1]; f=arrQuery[k][2]; //scanf("%d%d",&p,&f);
           oldValue=arr2[p-1],arr2[p-1]=f,newValue=arr2[p-1];
           for(set<int>::iterator it=DS[p-1].begin();it!=DS[p-1].end();++it){
                idx=*it;
                ans[idx]=((ans[idx]*__power(oldValue) %MOD)*newValue)%MOD;
                DP[idx]=DP[idx]-log10(oldValue)+log10(newValue);
           }
        } else{
             r=arrQuery[k][1]; //scanf("%d",&r);// cin >> r;
            long double Digit=DP[r]+log10(arr2[0]);
            Digit=Digit-floor(Digit);
            ANS[k][0]=DIGIT(Digit); ANS[k][1]=(ans[r]*arr2[0])%MOD;
            //printf("%d %lld\n",DIGIT(Digit),(ans[r]*arr[0])%MOD);
        }
    }
    for(int i=0;i<Q;i++){
        if(arrQuery[i][0]==2)printf("%d %d\n",ANS[i][0],ANS[i][1]);
    }
}
void SolveSmall(int N,int arr[],int Q,int arrQuery[][5]){
    int p,f,r;
    int ANS[Q][2];
    bool flag=false;
    clock_t s=clock(),e; double dur;
    for(int k=0;k<Q;k++){


        if(arrQuery[k][0]==1){
            p=arrQuery[k][1];f=arrQuery[k][2];
           arr[p-1]=f;
        } else{
            r=arrQuery[k][1];
            mult[0]=1;size=1;
            ll ans=1LL;
            for(int i=0;i<N;i+=r){
                  e= clock();  dur=(double) (e-s)/CLOCKS_PER_SEC;
                    if(dur>0.31) SolveBig(N,Q,arrQuery);
                ans=(ans*arr[i])%MOD;
                multiply(arr[i]);
            }
            ANS[k][0]=mult[size-1]; ANS[k][1]=ans;
            //printf("%d %d\n",mult[size-1],ans);
        }
    }
    for(int i=0;i<Q;i++)   if(arrQuery[i][0]==2)printf("%d %d\n",ANS[i][0],ANS[i][1]);

}
int main(){
    int N;  scanf("%d",&N);
    int arr[N]; for(int i=0;i<N;i++) scanf("%d",&arr[i]),arr2[i]=arr[i];
    int Q,q; scanf("%d",&Q);
    int arrQuery[Q][5];
    for(int i=0;i<Q;i++){
        scanf("%d",&arrQuery[i][0]);
        if(arrQuery[i][0]==1) scanf("%d%d",&arrQuery[i][1],&arrQuery[i][2]);
        else scanf("%d",&arrQuery[i][1]);
    }
    //SolveSmall(N,arr,Q,arrQuery);
    SolveBig(N,Q,arrQuery);
    return 0;
}
