#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<pair<ll,ll> > > Path;
vector<pair<ll,ll> > currPath;
void Tracing(vector<pair<ll,ll> >&currPath,ll I,ll J,ll N,ll M){

    if(I==N&&J==M) { currPath.push_back(make_pair(I,J));
        Path.push_back(currPath); return;
    }else{
        if(currPath.size()!=0){
            ll s=currPath.size()-1;
            while(s>=0){
                ll i=currPath[s].first,j=currPath[s].second;
                if((I-i==1 && J-j==0)||(I-i==0 && J-j==1)) break;
                else currPath.erase(currPath.begin()+s); s--;
            }
        }
        currPath.push_back(make_pair(I,J));
        if(I+1<=N && J<=M) Tracing(currPath,I+1,J,N,M);
        if(I<=N && J+1<=M) Tracing(currPath,I,J+1,N,M);
    } return;
}
bool checkPath(vector<pair<ll,ll> > &I, vector<pair<ll,ll> >&J,vector<vector<bool> >&Mat,ll D){
    for(ll i=1;i<I.size()-1;i++)
        if(I[i]==J[i]) return false;
    ll carrot=0;
    for(ll i=0;i<I.size();i++)
        carrot+=Mat[I[i].first][I[i].second];
    for(ll i=0;i<J.size();i++)
        carrot+=Mat[J[i].first][J[i].second];
    if(carrot<=D) return true;
    return false;
}
int main(){

    ll t,N, M, C, D ,MOD,x,y; cin >> t;
    while(t--){
        cin>>N>>M>>C>>D>>MOD;
        vector<vector<bool> > Mat(N+5,vector<bool>(M+5,false));
        while(C--){
            cin >> x >> y; Mat[x][y]= true;
        }
        vector<vector<pair<ll,ll> > >().swap(Path);
        vector<pair<ll,ll> >().swap(currPath);
        Tracing(currPath,1,1,N,M);
        //for(ll i=0;i<Path.size();cout<<"||"<<endl,i++)for(ll j=0;j<Path[i].size();j++)cout<<"("<<Path[i][j].first<<","<<Path[i][j].second<<") --> ";
        ll ans=0;
        for(ll i=0;i<Path.size();i++)
            for(ll j=i+1;j<Path.size();j++)
                ans=(ans+checkPath(Path[i],Path[j],Mat,D) ) %MOD;
        cout<<ans<<endl;
        vector<vector<bool> > ().swap(Mat);
    }
    return 0;
}
