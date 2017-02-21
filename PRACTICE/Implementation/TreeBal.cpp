#include<bits/stdc++.h>
using namespace std;
#define ll long long
int findMaximum(int arr[], int low, int high){
   if (low == high)
     return arr[low];
   if ((high == low + 1) && arr[low] <= arr[high])
      return arr[low];
   if ((high == low + 1) && arr[low] > arr[high])
      return arr[high];
   int mid = (low + high)/2;
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
        vector<pair<ll,ll> > arr(n);
        map<pair<ll,ll>,pair<ll,ll> > mymap;
        vector<vector<ll> > List(n+1,vector<ll>());
        for(ll i=1,u,v,c,d;i<n;i++){
            cin >>  u >> v >> c >> d;
            mymap[make_pair(u,v)]=make_pair(c,d);
            mymap[make_pair(v,u)]=make_pair(c,d);
            List[v].push_back(u);
            List[u].push_back(v);
            arr[i-1]=make_pair(u,v);
        }
        vector<bool> visit(n+1,false);
        path.clear();
        vector<ll> currPath; currPath.clear();
        currPath.push_back(1); visit[1]=true;
        DFS(1,currPath,List,visit);
        for(int i=0;i<path.size();i++,cout<<endl)
            for(int j=0;j<path[i].size();j++)
                cout<<path[i][j]<<" "; cout<<endl;

        vector<pair<ll,ll> > info(path.size());
        vector<ll> Index(path.size());
        ll mn  = INT_MAX,mx = INT_MIN;
        for(ll i=0;i<path.size();i++){
            ll sum  = 0;
            ll D = INT_MAX;
            for(int j=1;j<path[i].size();j++){
             pair<ll,ll> curr =  mymap[make_pair(path[i][j-1],path[i][j])];
                sum+=curr.first;
                D=min(D,curr.second);
            }
            mn = min(mn,sum);
            mx = max(mx,sum);
            info[i]=make_pair(sum,D);
        }

        ll ans = (1LL<<62);
        ll val = mn;
        for(ll i =mn;i<=mx;i++){
            ll curr = getTime(info,i);
            if(curr<ans){
                ans=curr;
                val = i;
            }
        }
        cout<<ans<<endl;
        for(ll i=0;i<path.size();i++){
            pair<ll,ll> swp;
            ll D = INT_MAX;
            ll sum  = 0;
            for(int j=1;j<path[i].size();j++){
                pair<ll,ll> curr =  mymap[make_pair(path[i][j-1],path[i][j])];
                sum+=curr.first;
                if(D>curr.second){
                    swp = make_pair(path[i][j-1],path[i][j]);
                    D=curr.second;
                }
            }
            mymap[swp] = make_pair(ans-sum,mymap[swp].second);
        }
        for(int i=0;i<n-1;i++)
            cout<<mymap[arr[i]].first<<endl;
    }
    return 0;
}
