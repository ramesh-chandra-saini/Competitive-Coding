#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
ll num_of_digit(ll N){
    return N>0?1+num_of_digit(N/10):0;
}
ll min_num(ll digit,ll value = 0){
    while(digit--)
        value=value*10+2;
    return value;
}
ll max_num(ll digit,ll value = 0){
    while(digit--)
        value=value*10+7;
    return value;
}
vector<ll> get_decimal_rep(ll N,vector<ll> digits = vector<ll> ()){
    while(N)
        digits.pb(N%10),N/=10;
    return digits;
}
ll get_value(vector<ll>digits,ll L=0){
    for(ll i=digits.size()-1;i>=0;i--)
        L=L*10+digits[i];
    return L;
}
vector<ll> lower_bound(vector<ll> digits){
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
    return digits;
}
int main(){
    clock_t runtime = clock();
    ll first, last;
    scanf("%lld%lld",&first,&last);
    vector<ll> L = lower_bound(get_decimal_rep(first));
    vector<ll> numbers;
    do{
        numbers.push_back(get_value(L));
        //cout<<get_value(L)<<" ";
        L[0]+=1;//next number
        L=lower_bound(L);//get lower bound for this number
    }while(get_value(L)<=last);
    printf("%llu\n",numbers.size());
    runtime =clock()-runtime;
    printf("%.9lf\n",double(runtime)/CLOCKS_PER_SEC);

    /*for(ll i=0;i<numbers.size();i++)
        printf("%lld\n",numbers[i]);
    printf("\n");*/
    return 0;
}
