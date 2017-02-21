#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool checkDigit(vector<ll>&dig,ll m){
    for(int i=0,ct=0;i<dig.size();i+=2){
        ct++;
        if(ct>m)  return false;
        if(i+1<dig.size() && dig[i+1]==-2)
            ct=0;
    }
    return true;
}
void print(vector<ll>&dig){
    for(int i=0;i<dig.size();i+=2){
        cout<<dig[i];
        if(dig[i+1]==-2)
            cout<<"  ";
    }
    cout<<endl;
}
vector<ll> toggle(vector<ll>&dig,ll id){
    vector<ll>toggled(dig);
    toggled[id]=-2;
    return toggled;
}
void solve(ll curr,ll id,ll m,vector<ll>dig,ll x,ll y,ll &ans){
   if(curr>y)
        return;
    else{
       if(x<=curr && curr<=y){
            if(checkDigit(dig,m)){
                ll gcd = 0;
                for(ll i=0,num=0;i<dig.size();i+=2){
                    num=num*10+dig[i];
                    if(i+1==dig.size() || dig[i+1]==-2)
                        gcd = __gcd(gcd,num),  num=0;

                } //cout<<"GCD :"<<gcd<<endl;
                ans=max(ans,gcd);
            }
        }
        if(id<dig.size() && curr<=y){
            solve(curr,id+2,m,dig,x,y,ans);
            solve(curr+1,id+2,m,toggle(dig,id),x,y,ans);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string str; cin >> str; //cout<<str<<endl;
        ll ans = 0;
        vector<ll> dig(2*n-1,-1);
        for(int i=0,j=0;i<2*n-1;i+=2,j++)
            dig[i]=str[j]-'0';
       //for(int i=0;i<dig.size();i++)cout<<dig[i]; cout<<endl;
        //print(dig);
        ll m,x,y; cin >>m>>x>>y;
        solve(0LL,1LL,m,dig,x,y,ans);
        cout<<ans<<endl;
    }
    return 0;
}
