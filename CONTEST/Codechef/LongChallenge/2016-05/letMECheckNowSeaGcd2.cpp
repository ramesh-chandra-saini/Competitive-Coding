#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
vector<bool> seive(101);
set<ll> prime;
ll dp[101];
ll dpInverse[101];
void Seive(){
    for(ll i=0;i<=100;i++) seive[i]=true;seive[0]=seive[1]=false;
    for(ll i=2;i*i<=100;i++){
        if(seive[i]){
            for(ll j=i*i;j<=100;j+=i)
                seive[j]=false;
        }
    }
    prime.clear(); //cout<<"PRIME : ";
    for(ll i=0;i<=100;i++){
        if(seive[i] == true){
            prime.insert(i);
            //cout<<i<<" ";
        }
    } //cout<<endl;
}
set<ll> primeFactor(ll N){
    set<ll> factors; factors.clear();
    //cout<<N<<"-->";
    for(set<ll> :: iterator i=prime.begin();i!=prime.end();i++){
        if(N%(*i) == 0){
            factors.insert(*i);
            //cout<<(*i)<<" ";
        }
    } //cout<<endl;
    return factors;
}
ll checkGcd(ll N,set<ll> primeList){
    set<ll> factor(primeFactor(N));
    for(set<ll>::iterator i=factor.begin();i!=factor.end();i++){
        if(primeList.find(*i)!=primeList.end()){
            return (*i);
        }
    }
    return 1LL;
}
ll power(ll N,ll expo){
    ll ans=1LL;
    while(expo){
        if(expo%2)
            ans=(ans*N)%MOD;
        N=(N*N)%MOD;
        expo/=2LL;
    }
    return ans;
}
ll solve(ll n,ll m,ll pos,ll count,ll lastInsertedItem,set<ll> primeList,set<ll> M,set<ll> value,ll p){
    if(pos==-1 || lastInsertedItem<=2 || count>=p || primeList.size()>=p || M.size()==0){
        ll A=dp[n],B=dpInverse[n-count];
       //cout<<"VALUE ";for(set<ll>::reverse_iterator i=value.rbegin();i!=value.rend();i++) cout<<(*i)<<" "; cout<<"   ";
       // cout<<"ans "<< (A*B)%MOD<<endl;
        return (A*B)%MOD;
    }
    ll ans=0LL;

    //cout<<"M "; for(set<ll>::iterator it=M.begin();it!=M.end();++it)cout<<(-(*it))<<" "; cout<<" || ";
    //for(set<ll>::iterator it=primeList.begin();it!=primeList.end();++it)cout<<((*it))<<" ";cout<<endl;
    for(set<ll>::iterator it=M.begin();it!=M.end();++it){
        ll i=-(*it);
        if(i==1){
            set<ll> __value(value);
            __value.insert(i); ans=(ans+solve(n,m,pos-1,count,i,primeList,M,__value,p))%MOD;}
        else{
            if(checkGcd(i,primeList)==1){
                set<ll>newPrime(primeFactor(i));
                set<ll> __m; __m.clear();
                for(set<ll>::iterator __it=it;__it!=M.end();++__it){
                    ll j=-(*__it);
                    if(checkGcd(j,newPrime)==1){
                        __m.insert(-j);
                    }
                }
                set<ll> PrimeList(primeList);
                for(set<ll>::iterator __it=newPrime.begin();__it!=newPrime.end();++__it){
                    PrimeList.insert(*__it);
                }
            set<ll> __value(value);
            __value.insert(i);
                ans=(ans+solve(n,m,pos-1,count+1,i,PrimeList,__m,__value,p))%MOD;
            }
        }
    }
    return ans;
}
int main(){
    clock_t s=clock(),e;
    Seive();
    e=clock();

    dp[0]=1LL;
    for(ll i=1;i<=100;i++){
        dp[i]=(dp[i-1]*i)%MOD;
    }
    for(ll i=0;i<=100;i++){
        dpInverse[i]=power(dp[i],MOD-2LL);
    }
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        s=clock();
        ll pos=n-1LL,count=0,lastInsertedItem=m+1;
        set<ll> primeList; primeList.clear();
        set<ll> M; M.clear();
        for(ll i=1;i<=m;i++){
            M.insert(-i);
        }
        set<ll>value;value.clear();ll p=0;
        for(set<ll> :: iterator i=prime.begin();i!=prime.end() && m>=*i;i++,p++);
        cout<<solve(n,m,pos,count,lastInsertedItem,primeList,M,value,p)<<endl;
        e=clock();   float duration = (float)(e-s)/CLOCKS_PER_SEC; cout<<duration<<endl;
    }
    return 0;
}
