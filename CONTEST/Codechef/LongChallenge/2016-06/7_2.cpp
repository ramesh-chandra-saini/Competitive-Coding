#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int mult[100000000];
ll ans,temp;
int size=0,carry;
void multiply(vector<ll>&mult,ll N){
	temp=0,carry=0;
	for(ll i=0;i<size;i++){
		temp=carry+mult[i]*N;
		mult[i]=temp%10;
		carry=temp/10;
	}
	while(carry)
		mult[size++]=(carry%10),carry/=10;
}
void preprocessing(vector<set<ll> > &DS,ll N){
    DS[0].clear();
    for(ll n=1LL;n<=N;n++){ //cout<<n<<" : ";
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                DS[n].insert(i); //cout<<i<<" "<<(n/i)<<" ";
                DS[n].insert(n/i);
            }
        } //cout<<endl;
    }
    for(ll i=1;i<=N;i++){ cout<<i<<" :: ";
        for(set<ll> ::iterator it=DS[i].begin();it!=DS[i].end();++it){
            cout<<*it<<" "; }   cout<<endl;
    }
}
void precalculation(vector<vector<ll> > &DP,vector<ll> &ans,ll arr[],ll N){

    for(ll r=1;r<N;r++){
        DP[r].clear();ans[r]=1LL;
        for(ll i=1;i*r<N;i++){
            multiply(DP[r],arr[i*r]);
            ans[r]=(ans[r]*arr[i*r])%MOD;
        }
    }
}
int main(){

    int n,q,choice,p,f,r; scanf("%d",&n);
    vector<set<ll> > DS(n+1);
    preprocessing(DS,n);
    int arr[n+1]; for(ll i=1;i<=n;i++) scanf("%d",&arr[i]);
    vector<vector<ll> > DP(n+1);
    vector<ll> ans(n+1);
    precalculation(DP,ans,arr[],n);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&choice);
        if(choice==1LL){
            scanf("%d%d",&p,&f); p=-1;
            if(p==0)  arr[p]=f;
            else{

            }
        }
        if(choice==1LL) { arr[p]=f ;   }
        else{   scanf("%d",&r); size=0,mult[size++]=1LL,ans=1LL;
                for(ll i=0;1+i*r<=n;i++){
                    ans=(ans*arr[1+i*r])%1000000007;
                    multiply(arr[1+i*r]);
				}
				printf("%d %lld\n",mult[(size-1)],ans);
        }
    }
    return 0;
}
