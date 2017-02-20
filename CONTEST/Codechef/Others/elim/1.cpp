
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool ans=false;
pair<ll,ll> newDim(ll r, ll c, ll  R, ll C){
    if(r==R && c ==C) R=C=0;
    else if(r!=R)  R-=r;
    else C-=c;
    return make_pair(R,C);
}
void Solve(ll R, ll C,vector<ll> &cake){
    //cout<< R<<" "<<C<<" "<<cake.size()<<endl;
    if(ans) return;
    if(R==0 && C==0 && cake.size()==0) ans=true;
    if(R==0 || C == 0 || cake.size()==0 ) return ;
    for(int i=0;i<cake.size() && ans == false;i++){
        ll area= cake[i];
        vector<ll> newCake; newCake.clear();
        for(int j=0;j<cake.size() && ans == false;j++)
            if(i!=j) newCake.push_back(cake[j]);
        if(area%R==0){
            pair<ll,ll> dim = newDim(R,area/R,R,C);
            Solve(dim.first,dim.second,newCake);
            Solve(dim.second,dim.first,newCake);
        }
        if(area%C==0){
            pair<ll,ll> dim = newDim(area/C,C,R,C);
            Solve(dim.first,dim.second,newCake);
            Solve(dim.second,dim.first,newCake);
        }
    }
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll R,C,M,K,J; cin >> R >> C >> M >> K >> J;
        ans=false;vector<ll> cake; cake.clear();cake.push_back(M);cake.push_back(K);cake.push_back(J);
        Solve(R,C,cake);Solve(C,R,cake);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
