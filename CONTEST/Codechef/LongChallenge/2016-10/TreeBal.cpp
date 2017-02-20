#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll findMaximum(ll arr[], ll low, ll high){
   if (low == high)
     return arr[low];
   if ((high == low + 1) && arr[low] <= arr[high])
      return arr[low];
   if ((high == low + 1) && arr[low] > arr[high])
      return arr[high];
   ll mid = (low + high)/2;
   if ( arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])
      return arr[mid];
   if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
     return findMaximum(arr, low, mid-1);
   else
     return findMaximum(arr, mid + 1, high);
}
ll getTime(vector<pair<ll,ll> >&edge,ll X,ll time=0){
    for(ll i=0;i<edge.size();i++)
        time+=edge[i].second*abs(edge[i].first-X);
    return time;
}
vector<vector<ll> > path;
void DFS(ll curr,vector<ll>&currPath,vector<vector<ll> >&List,vector<bool>&visit){
    if(List[curr].size()==1){
        path.push_back(currPath);
        return;
    }
    for(ll i=0;i<List[curr].size();i++){
        ll node = List[curr][i];
        if(!visit[node]){
            visit[node]=true;
            currPath.push_back(node);
            DFS(node,currPath,List,visit);
            currPath.pop_back();
        }
    }
}
int main(){
   freopen("in.txt","r",stdin);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll> > arr(n+1);
        map<pair<ll,ll>,pair<ll,ll> > mymap;
        vector<vector<ll> > List(n+1,vector<ll>());

        for(ll i=1,u,v,c,d;i<n;i++){
            cin >>  u >> v >> c >> d;
            mymap[make_pair(u,v)]=make_pair(c,d);
            mymap[make_pair(v,u)]=make_pair(c,d);
            List[v].push_back(u);
            List[u].push_back(v);
            arr[i]=make_pair(u,v);
        }
        vector<bool> visit(n+1,false);
        path.clear();
        vector<ll> currPath; currPath.clear();
        currPath.push_back(1); visit[1]=true;
        DFS(1,currPath,List,visit);
        /*for(ll i=0;i<path.size();i++,cout<<endl)
            for(ll j=0;j<path[i].size();j++)
                cout<<path[i][j]<<" "; cout<<endl;
*/
        vector<pair<ll,ll> > info(path.size());
        vector<ll> Index(path.size());
        vector<pair<ll,ll> > extra(path.size());
        ll mn  = INT_MAX,mx = INT_MIN;
        for(ll i=0;i<path.size();i++){
            ll sum  = 0;
            ll D = INT_MAX;
            for(ll j=1;j<path[i].size();j++){
             pair<ll,ll> curr =  mymap[make_pair(path[i][j-1],path[i][j])];
                sum+=curr.first;
                if(D>curr.second){
                    D=curr.second;
                    extra[i]=make_pair(path[i][j-1],path[i][j]);
                }
            }
            mn = min(mn,sum);
            mx = max(mx,sum);
            info[i]=make_pair(sum,D);
        }

        ll ans = (1LL<<62);
        ll val = mn;
        for(ll i =mn;i<=mx;i++){
            ll curr = getTime(info,i);
            if(curr<=ans){
                ans=curr;
                val = i;
            }
        }
        cout<<ans<<endl;
        map<pair<ll,ll>,pair<ll,ll> > yourMap(mymap);
        //cout<<val<<endl;
        for(ll i=0;i<path.size();i++){
            pair<ll,ll> swp=extra[i];
            ll sum  = info[i].first;
            ll p =  mymap[make_pair(swp.first,swp.second)].first;
            yourMap[make_pair(swp.first,swp.second)].first = val-(sum-p);
            yourMap[make_pair(swp.second,swp.first)].first = val-(sum-p);
        }
        for(ll i=1;i<n;i++)
            cout<<yourMap[arr[i]].first<<endl;
    }
    return 0;
}
