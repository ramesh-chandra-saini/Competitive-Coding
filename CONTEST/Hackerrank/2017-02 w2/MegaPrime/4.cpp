#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

vector<ll> get_decimal_rep(ll N,vector<ll> digits = vector<ll> ()){
    while(N)
        digits.pb(N%10),N/=10;
    return digits;
}
ll get_value(vector<ll>&digits,ll L=0){
    for(ll i=digits.size()-1;i>=0;i--)
        L=L*10+digits[i];
    return L;
}
void lower_bound(vector<ll>&digits){
    digits.push_back(0); ///just push 0 to handle carry
    ll len = digits.size();
    ll toggle = 0;
    for(ll i=0;i<len-1;i++){
        if(digits[i]==0 || digits[i]==1)
            digits[i]=2,toggle=i;
        else if (digits[i]==4)
            digits[i]=5,toggle=i;
        else if(digits[i]==6)
            digits[i]=7,toggle=i;
        else if(digits[i]==8 || digits[i]==9)
            digits[i+1]+=1,toggle=i+1; // like pass carry
    }
    for(ll i=toggle-1;i>=0;i--)
            digits[i]=2;

    if(digits[len-1]==0)
        digits.pop_back();
    else
        digits[len-1]=2;
    return;
}

bool isPrime(ll N){
    if(N<=1) return false;
    for(ll i=2;i*i<=N;i++)
        if(N%i==0)
            return false;
    return true;
}
int main(){
    //freopen("in.txt","r",stdin);
    clock_t runtime = clock();
    ll first, last;
    scanf("%lld%lld",&first,&last);
    vector<ll> L=get_decimal_rep(first);
    lower_bound(L);
    vector<ll> numbers;
    do{
        ll N = get_value(L);
        numbers.push_back(N);
        L[0]+=1;//next number
        lower_bound(L);//get lower bound for this number
    }while(get_value(L)<=last);
    ll ans = 0;
    vector<ll> prime;
    for(ll i=2;prime.size()<1000;i++)
        if(isPrime(i))
            prime.pb(i);
    for(ll i=0;i<numbers.size();i++){
        bool flag = true;
        for(ll j=0;j<prime.size() && prime[j]*prime[j]<=numbers[i] && flag;j++)
            if(numbers[i]%prime[j]==0)
                flag = false;
        ans+=flag;
    }
    printf("%lld\n",ans);
   /* for(ll i=0;i<numbers.size();i++)
        ans+=isPrime(numbers[i]);
    printf("%lld\n",ans);
    */


    runtime =clock()-runtime;
    //printf("%.9lf\n",double(runtime)/CLOCKS_PER_SEC);

    return 0;
}
