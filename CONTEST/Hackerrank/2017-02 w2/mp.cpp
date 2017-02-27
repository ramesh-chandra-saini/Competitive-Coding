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
    for(ll i=0;i<len-1;i++){
        if(digits[i]<=2)
            digits[i]=2;
        else if (digits[i]<=3)
            digits[i]=3;
        else if(digits[i]<=5)
            digits[i]=5;
        else if(digits[i]<=7)
            digits[i]=7;
        else
            digits[i]=2,digits[i+1]+=1; // like pass carry
    }
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
   // freopen("in.txt","r",stdin);
   // clock_t runtime = clock();
    ll first, last;
    scanf("%lld%lld",&first,&last);
    ll ans = 0;
    for(ll i=first;i<=last;i++){
        ll temp = i,check=1;
        if(isPrime(temp)){ //check for prime
            while(temp) //checking for mega prime
                check = isPrime(temp%10)?check:0,temp/=10;
        } else{ //not prime
            check = 0;
        }
        if(check)
            cout<<i<<"\n";
        ans+=check;
    } cout<<"\n";
    printf("%lld\n",ans);
    return 0;
    vector<ll> L=get_decimal_rep(first);
    lower_bound(L);
    vector<ll> numbers;
    do{
        ll N = get_value(L);

        //check if not prime...just to reduce compexity..basic level checking
        //if(!isFactorOfPrime(N,primeList))
            numbers.push_back(N);
        //cout<<get_value(L)<<" ";
        L[0]+=1;//next number
        lower_bound(L);//get lower bound for this number
    }while(get_value(L)<=last);
    //printf("%zu\n",numbers.size());

     ans = 0;
    for(ll i=0;i<numbers.size();i++)
        ans+=isPrime(numbers[i]);
    printf("%lld\n",ans);
    //runtime =clock()-runtime;
    //printf("%.9lf\n",double(runtime)/CLOCKS_PER_SEC);

    return 0;
}
