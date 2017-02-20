#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
set<ll> PrimeList;
vector<ll> Values;
set<ll> factor;
ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll dp[101];
ll dpInverse[101];
ll power(ll N,ll pow,ll mod){
    ll ans=1;
    while(pow){
        if(pow%2) ans=(ans*N)%mod;
        N=(N*N)%mod;pow/=2;
    }
    return ans;
}
set<ll> primeFactor(ll i){
    factor.clear();
    for(int j=0;j<25;j++)
       if(i%prime[j]==0) factor.insert(prime[j]);
    return factor;
}
ll checkGcd(ll i,set<ll> &primeList){
    set<ll> fact(primeFactor(i));
    for(set<ll> :: iterator k=fact.begin();k!=fact.end();++k)
            if(primeList.find(*k)!=primeList.end()) return (*k);
    return 1;//co prime
}
set<ll> __m__;
set<ll> newPrime;
ll solve(ll n, ll m,ll pos,ll lastInsertedItem,ll count,set <ll> &primeList,set <ll> &__M__ ){
    //cout<<pos<<" "<<lastInsertedItem<<" "<<PrimeList.size()<<endl;
    if(pos==-1 || lastInsertedItem<=2 || primeList.size()>=25 || count>=25){
        return ((dp[n]*dpInverse[n-count] )%MOD);
    }
    cout<<"HELL"<<endl;
    ll ans=0,i,__i;
    for(set<ll>::iterator it=__M__.begin();it!=__M__.end();++it){
        i=-(*it);
        cout<<i<<" ";
        if(checkGcd(i,primeList)==1){
            newPrime=primeFactor(i); __m__.clear();
            for(set<ll>::iterator __it=it;__it!=__M__.end();++__it){
                __i=-(*__it);
                if(checkGcd(__i,newPrime)==1) __m__.insert(-__i);
            }
            PrimeList=primeList;for(set<ll>::iterator j=newPrime.begin();j!=newPrime.end();++j) PrimeList.insert(*j);
            cout<<"SOLVE("<<n<<","<<m<<","<<(pos-1)<<","<<i<<","<<(count+1)<<",PRIMELIST : ( ";
            for(set<ll>::iterator l=PrimeList.begin();l!=PrimeList.end();l++) cout<<*l<<" "; cout<<" ) __M__ ( ";
            for(set<ll>::iterator l=__m__.begin();l!=__m__.end();l++) cout<<*l<<" "; cout<<") \n";
            ans=(ans+solve(n,m,pos-1,i,count+1,PrimeList,__m__))%MOD;
        }
    }
    return ans;
}
int main(){
    ll t; cin >> t;
    set<ll> primeList;
    set<ll>__M__;
    vector<ll> values;
    dp[0]=1; for(int i=1;i<=100;i++) dp[i]=(dp[i-1]*i)%MOD;
    for(int i=0;i<=100;i++)dpInverse[i]=power(dp[i],MOD-2,MOD)%MOD;
    while(t--){
        ll n,m; cin >> n >> m;
        primeList.clear();
        ll lastInsertedItem=m+1,pos=n-1,ct=0;__M__.clear();
        for(ll i=1;i<=m;i++) __M__.insert(-i);
        cout<<"SOLVE("<<n<<","<<m<<","<<(pos)<<","<<"?,"<<(ct)<<",PRIMELIST : ( ";
        for(set<ll>::iterator l=primeList.begin();l!=primeList.end();l++) cout<<*l<<" "; cout<<" ) __M__ ( ";
        for(set<ll>::iterator l=__M__.begin();l!=__M__.end();l++) cout<<*l<<" "; cout<<")) \n";
        //for(set<ll>::iterator it=__M__.begin();it!=__M__.end();++it)std::cout << ' ' << (*it); cout<<endl;
        cout<<solve(n,m,pos,lastInsertedItem,ct,primeList,__M__)<<endl;;
    }
    return 0;
}
