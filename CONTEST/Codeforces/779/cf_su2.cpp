#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll  get_value(vector<ll>&decimal){
    ll ans = 0;
    for(int i=0;i<decimal.size();i++)
        ans = ans*10+decimal[i];
    return ans;
}
vector<ll> get_decimal(ll N){
    vector<ll> decimal; decimal.clear();
    do{
        decimal.push_back(N%10);
        N/=10;
    }while(N);

    for(size_t i=0,j=decimal.size()-1;i<j;i++,j--){
        ll temp = decimal[i];
        decimal[i]=decimal[j];
        decimal[j]=temp;
    }
    //reverse(decimal.begin(),decimal.end());
    return decimal;
}

int main(){
    ll  n,k; cin >> n >> k;
    if(n==0){ //handle corner case
        cout<<"0"<<endl;
        return 0;
    }
    vector<ll> decimal = get_decimal(n);
    ll  size = decimal.size();
    ll num = pow(10LL,k); cout<<num<<endl;
    ll ans = 0;
    ll  idx = decimal.size()-1;
    while(get_value(decimal)%num!=0 && idx>=0){
        if(decimal[idx]!=0)
            ++ans,decimal.erase(decimal.begin()+idx);
        idx--;
    }
    if(get_value(decimal)==0)
        ans = size-1;//removed all digits except one zero
    cout<<ans<<endl;
     return 0;
}

