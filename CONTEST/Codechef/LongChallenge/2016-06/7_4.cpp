#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll start=0;
ll __power(ll N,ll expo){
    ll ans=1LL;
    for(;expo; N=(N*N)%MOD,expo/=2)
        if(expo%2)
            ans=(ans*N)%MOD;
    return ans;
}
void preprocessing(vector<set<ll> > &DS,ll N){
    DS[0].clear();
    for(ll n=1;n<=N;n++)
        for(ll i=1;i*i<=n;i++)
            if(n%i==0) DS[n].insert(i),DS[n].insert(n/i);
}
void multiply(vector<ll>&mult,ll N){
    ll temp=0LL,carry=0LL;
    for(ll i=0;i<mult.size();i++){
        temp=carry+mult[i]*N;
        mult[i]=temp%10;
        carry=temp/10;
    }
    while(carry) mult.push_back(carry%10),carry/=10;
    ll numOfDigits=31;
    if(mult.size()>numOfDigits){
        ll st=mult.size()-numOfDigits;
        for(int i=0;i<numOfDigits;i++)  mult[i]=mult[i+st];
        mult.erase(mult.begin()+numOfDigits,mult.end());
    }
}
vector<ll> divide(vector<ll>&div,ll N){
    ll temp=0LL;
    vector<ll> ans; ans.clear();
    for(int i=div.size()-1;i>=0;i--){
        temp=(temp*10)+div[i];
        ans.push_back(temp/N);
        temp=temp-(temp/N)*N;
    }
    while(!ans.empty() && ans[0]==0) ans.erase(ans.begin());
    for(int i=0,j=ans.size()-1;i<j;i++,j--)
        swap(ans[i],ans[j]);
    if(ans.empty())ans.push_back(1);
    return ans;
}
void precalculation(vector<vector<ll> > &DP,vector<ll> &ans,ll arr[],ll N){
    ans[0]=1LL;DP[0].push_back(1LL);
    for(ll r=1;r<=N;r++){
        ans[r]=1LL;DP[r].push_back(1LL);
        for(ll i=1;i*r<N;i++){
            ans[r]=(ans[r]*arr[i*r])%MOD;
            multiply(DP[r],arr[i*r]);
        }
    }
}
void ansWer(vector<ll> & ans,ll N){
    ll temp=0,carry=0;
    ll Final=0;
    for(int i=0;i<ans.size();i++){
        temp=carry+ans[i]*N;
        Final=(temp%10);
        carry=temp/10;
    }
    while(carry) Final=(carry%10),carry/=10;
    printf("%lld ",Final);
}
void UPDATE(ll p,ll f,ll arr[],vector<ll>&ans,vector<set<ll> > & DS, vector<vector<ll> > &DP){
                    ll oldValue=arr[p]; arr[p]=f;
                    ll newValue=arr[p];
                    for(set<ll>::iterator it = DS[p].begin();it!=DS[p].end();++it){
                        ll idx=(*it);
                        //cout<<"update : ";cout<<idx<<"). ";
                        ans[idx]=(((ans[idx]*__power(oldValue,MOD-2))%MOD)*newValue)%MOD;
                        DP[idx]=divide(DP[idx],oldValue);
                        multiply(DP[idx],newValue);
                    }
}
int main(){
    ll n; scanf("%lld",&n);
    vector<set<ll> > DS(n+1);
    preprocessing(DS,n);
    ll arr[n+1]; for(ll i=0;i<n;i++) scanf("%lld",&arr[i]);//cin >> arr[i];
    vector<vector<ll> > DP(n+1);
    vector<ll> ans(n+1);arr[n]=1LL;
    precalculation(DP,ans,arr,n);
    ll Q; scanf("%lld",&Q);
    map<ll,ll> Query;
    int q,p,f,r;
    while(Q--){
        scanf("%lld",&q);
        if(q==1){
            scanf("%lld%lld",&p,&f);  Query[p-1]=f;
        }else{
            for(map<ll,ll>::iterator it = Query.begin();it!=Query.end();++it)
                UPDATE(it->first,it->second,arr,ans,DS,DP),Query.erase(it);
             scanf("%lld",&r);
            ansWer(DP[r],arr[0]);
            printf("%lld\n",(arr[0]*ans[r])%MOD);
        }
    }
    return 0;
}
