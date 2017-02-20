/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
==============================================================
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Point pair<ll,ll>
void moveController(ll n, ll m, ll k,vector<vector<ll> > &visit,ll X ,ll Y ,vector<vector<ll> > & RobotMoves){
    vector<vector<bool> > RobotVisit(n+2,vector<bool>(m+2,false));
    vector<pair<Point,ll > > mySet;mySet.clear();
    vector<pair<Point,ll > > yourSet;yourSet.clear();
    mySet.push_back(make_pair(make_pair(X,Y),0)); RobotVisit[X][Y] =true; RobotMoves[X][Y]=0LL; int ct=0;
    while(mySet.size()){
        for(ll it = 0;it<mySet.size();it++){
            ll I=mySet[it].first.first,J=mySet[it].first.second,moves=mySet[it].second;
            ///1st Quardrant
            for(ll i=I ;i>=max(1LL,I-k);i--){
                for(ll j=min(m,J+k-(I-i));j>=J;j--){
                  if(RobotVisit[i][j]) break;
                    else if(visit[i][j]==0)RobotMoves[i][j]=moves+1LL,yourSet.push_back(make_pair(make_pair(i,j),RobotMoves[i][j]));
                    RobotVisit[i][j]=true;
                }
            }
            ///2nd Quardrant
            for(ll i=I ;i>=max(1LL,I-k);i--){
                for(ll j=max(1LL,J-k+(I-i) );j<=J;j++){
                   if(RobotVisit[i][j]) break;
                    else if(visit[i][j]==0)RobotMoves[i][j]=moves+1LL,yourSet.push_back(make_pair(make_pair(i,j),RobotMoves[i][j]));
                    RobotVisit[i][j]=true;
                }
            }
            ///3rd Quardrant
            for(ll i=I ;i<=min(n,I+k);i++){
                for(ll j=max(1LL,J-k+(i-I));j<=J;j++){
                  if(RobotVisit[i][j]) break;
                    else if(visit[i][j]==0)RobotMoves[i][j]=moves+1LL,yourSet.push_back(make_pair(make_pair(i,j),RobotMoves[i][j]));
                    RobotVisit[i][j]=true;
                }
            }
            ///4th Quardrant
            for(ll i=I ;i<=min(n,I+k);i++){
                for(ll j=min(m,J+k-(i-I));j>=J;j--){
                   if(RobotVisit[i][j]) break;
                    else if(visit[i][j]==0)RobotMoves[i][j]=moves+1LL,yourSet.push_back(make_pair(make_pair(i,j),RobotMoves[i][j]));
                    RobotVisit[i][j]=true;
                }
            }
        }
        mySet.clear(); mySet=yourSet; yourSet.clear();
    }
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n,m,k1,k2; cin >> n >> m >> k1 >> k2;
        vector<vector<ll> > visit(n+2,vector<ll>(m+2,1LL));
        for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++) cin >> visit[i][j]; //cout<<"DONE INPUT"<<endl;
        vector<vector<ll> > firstRobotMoves(n+2,vector<ll>(m+2,INT_MAX));
        moveController(n,m,k1,visit,1LL,1LL,firstRobotMoves);
        vector<vector<ll> > secondRobotMoves(n+2,vector<ll>(m+2,INT_MAX));
        moveController(n,m,k2,visit,1LL,m,secondRobotMoves);
        ll ans=INT_MAX;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(visit[i][j]==0LL && firstRobotMoves[i][j]!=INT_MAX && secondRobotMoves[i][j]!=INT_MAX){
                    ans=min(ans,max(firstRobotMoves[i][j],secondRobotMoves[i][j]));
                }
            }
        }
        (ans==INT_MAX)?cout<<"-1"<<endl :cout<<ans<<endl;
    }  return 0;
}


