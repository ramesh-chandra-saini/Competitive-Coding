#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll N,L,R; cin >> N >> L >> R;
    ll arr[N];
    for(ll i=0;i<N;i++)
        cin >> arr[i];
    vector<pair<ll,ll> > X;
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            ll minX = max(L,abs(arr[i]-arr[j])+1LL);
            ll maxX = min(R,arr[i]+arr[j]-1LL);
            if(minX>maxX)
                continue;
            X.push_back(make_pair(minX,maxX));
        }
    }
    sort(X.begin(),X.end());
    //for(ll i=0;i<X.size();i++) cout<<"["<<X[i].first<<" "<<X[i].second<<"]\t"; cout<<endl;
    stack<pair<ll,ll> > disJointX;

    for(ll i=0;i<X.size();i++){
        if(disJointX.empty()){
            disJointX.push(X[i]);
        }else{
            pair<ll,ll> top = disJointX.top();
            if(top.first<=X[i].first && X[i].first<=top.second)
                disJointX.pop(),disJointX.push(make_pair(top.first,max(top.second,X[i].second)));
            else
                disJointX.push(X[i]);
        }
    }
    ll ans = 0LL;
    while(!disJointX.empty()){
        pair<ll,ll> top = disJointX.top();disJointX.pop();
        //cout<<"["<<top.first<<" "<<top.second<<"]\t";
        ans+=(top.second-top.first+1LL);
    } //cout<<endl;
    cout<<ans<<endl;

    return 0;
}
