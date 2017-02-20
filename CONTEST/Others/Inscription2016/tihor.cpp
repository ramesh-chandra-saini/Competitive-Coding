#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> prime;
#define mod 1000000007

vector<bool> isPrime(105005,true);
void seive(){
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i*i<105005;i++)
        if(isPrime[i])
            for(ll j=i*i;j<105005;j+=i)
                isPrime[j]=false;
    for(ll i=2;i<105005;i++)
        if(isPrime[i]) prime.push_back(i);
    //for(ll i=0;i<12;i++)    cout<<prime[i]<<" "; cout<<endl;
}
ll fastExpo(ll N,ll expo){
    ll ans = 1LL;
    while(expo){
        if(expo%2)
            ans= (ans*N)%mod;
        N=(N*N)%mod;
        expo=expo/2LL;
    }
    return ans;
}
int main(){
    ///freopen("in.txt","r",stdin);
    seive();
    ll n,q; cin >> n >> q;
    vector<ll> arr(n+1); for(int i=1;i<=n;i++) cin >> arr[i];
    vector<map<ll,ll> > MP(n+1);MP.clear();
    for(ll x=1;x<=n;x++){
            map<ll,ll> mp;mp.clear();
            ll temp = arr[x];
            for(ll y=0;prime[y]*prime[y]<=temp;y++){
                    ll ct = 0; //cout<<prime[y]<<" ";
                    while( temp%prime[y]==0)
                        ct++,temp/=prime[y];
                    if(ct)mp[prime[y]]=ct;
            }
             if(isPrime[temp])
                mp[temp]=max(mp[temp],1LL);
            MP[x]=mp;
            //cout<<arr[x]<<" "; for(map<ll,ll>::iterator it = mp.begin();it!=mp.end();++it)cout<<it->first<<"^"<<it->second<<" "; cout<<endl;
        }

    ll a,b,c,d; cin >> a >> b >> c >> d ;
    ll ans = 0LL;
    for(ll i=1;i<=q;i++){
        ll L = 1 + (a*ans+i*b)%n;
        ll R = L + (c*ans+i*d)%(n-L+1);
        //cout << L <<" "<< R <<"-->" ;
        map<ll,ll> mp;mp.clear();
        for(ll x=L;x<=R;x++)
            for(map<ll,ll>::iterator it = MP[x].begin();it!=MP[x].end();it++)
                mp[it->first] = max(mp[it->first],it->second);
        //for(map<ll,ll>::iterator it = mp.begin();it!=mp.end();++it){cout<<it->first<<" "<<it->second<<"   ";} cout<<endl;
        ll curr = 1LL;
        for(map<ll,ll>::iterator it = mp.begin();it!=mp.end();++it){
            ll phiP = it->first-1;
            ll exp = it->second;
            ll here = fastExpo(phiP,exp);// cout<<it->first<<"^"<<it->second<<" "<<here<<" ";
            curr = (curr*here)%mod;
        } //cout<<endl;
        cout<<curr<<endl;
        ans=curr;
    }return 0;
}
