#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll> idx;
map<ll,ll> rev_idx;
vector<pair<ll,ll> > intervals[100005];
ll solve(ll num,ll index,ll K,ll L,ll R){
    ll low=0,high = intervals[idx[num]].size()-1;
    while(low<=high && high>=0){
      ll mid = (low+high)/2;
      pair<ll,ll> curr = intervals[idx[num]][mid];
      if(index<curr.first) //go to left
        high = mid-1;
      else if(curr.second<index) //go to right
        low = mid+1;
      else{ //exact interval
            //cout<<"EXACT "<<curr.first<<" "<<curr.second<<endl;
            return  (min(curr.second,R)-max(curr.first,L)+1)>=K?num:-1LL;

        }
    }
    return -1LL;
}
void print(ll k){
    for(ll i=1;i<=k;i++){
        if(intervals[i].size()){
            cout<<rev_idx[i]<<" ";
            for(ll j=0;j<intervals[i].size();j++)
                cout<<"["<<intervals[i][j].first<<" "<<intervals[i][j].second<<"] ";
            cout<<endl;
        }
    }
}
int main(){
    ll N,M; cin >> N >> M;
    ll arr[N+1],k=0;
    for(ll i=1;i<=N;i++){
        cin >> arr[i];
        if(idx.find(arr[i])==idx.end())
            idx[arr[i]]=++k;//compress
    }
    for(ll i=1;i<=N;){
        ll temp = arr[i],L=i,R=i;
        while(i<=N && temp==arr[i])
            R=i,i++;
        intervals[idx[temp]].push_back(make_pair(L,R));
    }
    for(map<ll,ll> ::iterator it = idx.begin();it!=idx.end();++it)
        rev_idx[it->second]=rev_idx[it->first];

    for(ll i=1;i<=k;i++)
        sort(intervals[i].begin(),intervals[i].end());

   // print(k);

    while(M--){
        ll L,R,K; cin >> L >> R >> K;
        ll size = (R-L+1);
        if(size%2){
            ll num = arr[(L+R)/2]; //cout<<" num "<<num<<endl;
            cout<< solve(num,(L+R)/2,K,L,R)<<endl;
        }else{
            ll num1 = arr[((L+R)/2)+1];
            ll ans1 = solve(num1,((L+R)/2)+1,K,L,R);

            ll num2 = arr[size/2];
            ll ans2 = solve(num2,((L+R)/2),K,L,R);
            if(ans1!=-1)
                cout<<ans1<<endl;
            else
                cout<<ans2<<endl;
        }
    }
    return 0;
}
