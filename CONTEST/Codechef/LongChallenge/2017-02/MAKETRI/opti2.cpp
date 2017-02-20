#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll N,L,R; cin >> N >> L >> R;
    ll arr[N];
    for(ll i=0;i<N;i++)
        cin >> arr[i];
    vector<pair<ll,ll> > X;
    sort(arr,arr+N);
    //find the interval for valid X
    for(ll i=1;i<N;i++){
        ll minX = max(L,arr[i]-arr[i-1]+1LL);
        ll maxX = min(R,arr[i]+arr[i-1]-1LL);
        if(minX>maxX)
            continue;
        X.push_back(make_pair(minX,maxX));
    }
    sort(X.begin(),X.end());
    //join overlapping X interval
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
    ll ans = 0LL; //cal calculate final answer
    while(!disJointX.empty()){
        pair<ll,ll> top = disJointX.top();disJointX.pop();
        ans+=(top.second-top.first+1LL);
    }
    cout<<ans<<endl;

    return 0;
}
