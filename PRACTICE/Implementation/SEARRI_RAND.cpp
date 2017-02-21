#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    srand(time(NULL));
    ll n,k,d; cin >> n >> k >> d;
    set<ll>idx;for(ll i=0;i<n;i++) idx.insert(i);
    vector<ll> arr(n); for(ll i=0;i<n;i++) cin  >> arr[i];
    set<ll> dlIdx;
    for(ll i=0;i<min(d,n);i++){
        ll curr = rand()%n;
        if(idx.find(curr)!=idx.end()){
            dlIdx.insert(curr);
            idx.erase(curr);
        }
    }
    vector<pair<ll,ll> > swIdx;
    for(ll i=0;i<k;i++){
        ll a = 1+rand()%n;
        ll b = 1+rand()%n;
        if(idx.find(a)!=idx.end() && idx.find(b)!=idx.end()){
            swIdx.push_back(make_pair(a,b));
            ll temp = arr[a]; arr[a]=arr[b];arr[b]=temp;
        }
    }
    vector<ll> newArr;
    for(ll i=0;i<n;i++){
        if(dlIdx.find(i)==dlIdx.end())
            newArr.push_back(i);
    }
    ll global = (1LL<<62);
    ll A=rand()%100,D=0;
    for(int i=0;i<newArr.size();i++)
            D+=abs(arr[newArr[i]]);
    D = D/max(1LL,(ll)newArr.size());
    cout<<A<<" "<<D<<endl;

    for(set<ll>::iterator it = dlIdx.begin();it!=dlIdx.end();++it){
        cout<<"2 "<<1+*it<<endl;
    }
    for(vector<pair<ll,ll> >::iterator it = swIdx.begin();it!=swIdx.end();++it){
        cout<<"1 "<<1+it->first<<" "<<1+it->second<<endl;
    }
    cout<<"-1"<<endl;
}
