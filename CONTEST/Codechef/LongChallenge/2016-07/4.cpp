#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void print(ll N,int digit){if(N==INT_MAX) while(digit--) cout<<"-";else {if(N<100) cout<<"0";if(N<10) cout<<"0";cout<<N; }cout<<" ";}
void moveRobotSecond( ll i, ll j,ll n, ll m, vector<vector<ll> >&visit,ll I,ll J,vector<vector<ll> >&robotDis,vector<vector<bool> >visitCell){
    //if(moove<0) return; moove--; cout<<" --> ["<<i<<","<<j<<"] ";
    if(i>=0LL && i<n && j>=0LL && j<m ){
        if(!visit[i][j]){ visitCell[i][j]=true;
            int preA=(i-1>=0)?robotDis[i-1][j]:INT_MAX,
                preB=(j-1>=0)?robotDis[i][j-1]:INT_MAX,
                preC=(i+1<n)?robotDis[i+1][j]:INT_MAX,
                preD=(j+1<m)?robotDis[i][j+1]:INT_MAX;
            if( (i+1)<n && !visit[i+1][j]) robotDis[i+1][j]=min(robotDis[i+1][j],robotDis[i][j]+1);
            if( (j+1)<m && !visit[i][j+1]) robotDis[i][j+1]=min(robotDis[i][j+1],robotDis[i][j]+1);
            if( i-1>=0 && !visit[i-1][j]) robotDis[i-1][j]=min(robotDis[i-1][j],robotDis[i][j]+1);
            if( j-1>=0 && !visit[i][j-1]) robotDis[i][j-1]=min(robotDis[i][j-1],robotDis[i][j]+1);
            if((i+1)<n && preC>robotDis[i+1][j])moveRobotSecond(i+1,j,n,m,visit,I,J,robotDis,visitCell);
            if((j+1)<m && preD>robotDis[i][j+1])moveRobotSecond(i,j+1,n,m,visit,I,J,robotDis,visitCell);
            if((i-1)>=0 && preA>robotDis[i-1][j])moveRobotSecond(i-1,j,n,m,visit,I,J,robotDis,visitCell);
            if((j-1)>=0 && preB>robotDis[i][j-1])moveRobotSecond(i,j-1,n,m,visit,I,J,robotDis,visitCell);
        } //else cout<<" NOT Reachable"<<endl;
    } //else cout<<" INvalid "<<endl;
}
int moove=50;
void moveRobotFirst( ll i, ll j,ll n, ll m, vector<vector<ll> >&visit,ll I,ll J,vector<vector<ll> >&robotDis,vector<vector<bool> >visitCell){
    //if(moove<0) return; moove--;cout<<" --> ["<<i<<","<<j<<"] ";
    if(i>=0LL && i<n && j>=0LL && j<m ){
        if(!visit[i][j] ){ visitCell[i][j]=true;
            int preA=(i-1>=0)?robotDis[i-1][j]:INT_MAX,
                preB=(j-1>=0)?robotDis[i][j-1]:INT_MAX,
                preC=(i+1<n)?robotDis[i+1][j]:INT_MAX,
                preD=(j+1<m)?robotDis[i][j+1]:INT_MAX;
            if( i-1>=0 && !visit[i-1][j]) robotDis[i-1][j]=min(robotDis[i-1][j],robotDis[i][j]+1);
            if( j-1>=0 && !visit[i][j-1]) robotDis[i][j-1]=min(robotDis[i][j-1],robotDis[i][j]+1);
            if( (i+1)<n && !visit[i+1][j]) robotDis[i+1][j]=min(robotDis[i+1][j],robotDis[i][j]+1);
            if( (j+1)<m && !visit[i][j+1]) robotDis[i][j+1]=min(robotDis[i][j+1],robotDis[i][j]+1);
            if((i-1)>=0 && preA>robotDis[i-1][j])moveRobotFirst(i-1,j,n,m,visit,I,J,robotDis,visitCell);
            if((j-1)>=0 && preB>robotDis[i][j-1])moveRobotFirst(i,j-1,n,m,visit,I,J,robotDis,visitCell);
            if((i+1)<n && preC>robotDis[i+1][j])moveRobotFirst(i+1,j,n,m,visit,I,J,robotDis,visitCell);
            if((j+1)<m && preD>robotDis[i][j+1])moveRobotFirst(i,j+1,n,m,visit,I,J,robotDis,visitCell);
        } //else cout<<" NOT Reachable"<<endl;
    } //else cout<<" INvalid "<<endl;
}
int main(){
    ll t; cin >> t;
    while(t--){
        ll n,m,k1,k2; cin >> n >> m >> k1 >> k2 ;
        vector<vector<ll> >visit(n,vector<ll>(m)); for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) cin >> visit[i][j];
        vector<vector<ll> >firstRobotDis(n,vector<ll>(m,INT_MAX)), secondRobotDis(n,vector<ll>(m,INT_MAX)) ;
        firstRobotDis[0][0]=secondRobotDis[0][m-1]=0LL;
        vector<vector<bool> >visitA(n,vector<bool>(m,false)),visitB(n,vector<bool>(m,false));
        moveRobotFirst(0,0,n,m,visit,0,0,firstRobotDis,visitA);
        moveRobotSecond(0,m-1,n,m,visit,0,m-1,secondRobotDis,visitB);
        //cout<<"FIRST ROBOT "<<endl;for(int i=0;i<n;i++,cout<<endl)for(int j=0;j<m;j++) print(firstRobotDis[i][j],3);cout<<endl;
        //cout<<"SECOND ROBOT "<<endl;for(int i=0;i<n;i++,cout<<endl)for(int j=0;j<m;j++) print(secondRobotDis[i][j],3);cout<<endl;
        bool possible=false;
        ll ans=INT_MAX;
        if(m==1LL) ans=0LL,possible=true;//same cell
        else if(!k1&&!k2) possible=false;//impossible to meet, as they can not move
        else if(!k1){ // first cannot move, possible meet at cell(0,0) ~ (1,1)
            if(secondRobotDis[0][0]!=INT_MAX)
                possible=true,ans=(secondRobotDis[0][0]+k2-1)/k2;
        } else if(!k2){ // second cannot move, possible meet at cell(0,m-1) ~ (1,m)
            if(firstRobotDis[0][m-1]!=INT_MAX)
                possible=true,ans=( firstRobotDis[0][m-1]+k1-1)/k1;
        }else{
            for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                    if(!visit[i][j] && firstRobotDis[i][j]!=INT_MAX && secondRobotDis[i][j]!=INT_MAX){
                        possible=true;
                        ans=min(ans,max( ( firstRobotDis[i][j]+k1-1)/k1, (secondRobotDis[i][j]+k2-1)/k2 ));
                    }
                }
            }
        }
        if(possible) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
