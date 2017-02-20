#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void print(ll N,int digit){if(N==INT_MAX) while(digit--) cout<<"-";else {if(N<100) cout<<"0";if(N<10) cout<<"0";cout<<N; }cout<<" ";}
bool outOfTable(ll i,ll j,ll n, ll m){  if(i<=0 || i>n || j<=0 || j>m) return true; return false;} int ct=0;
void moveRobotFirst(ll i,ll j,ll n, ll m,vector<vector<ll> >&visit,vector<vector<bool> >& visitCell,vector<vector<ll> >& robotDis){ ct++;//cout<<" --> "<<++ct<<").["<<i<<","<<j<<"] ";

    if(outOfTable(i,j,n,m)) return;
    if(visit[i][j] || visitCell[i][j]) return;
    visitCell[i][j]=true;
    if(!visit[i+1][j] && robotDis[i+1][j]>robotDis[i][j]+1){robotDis[i+1][j]=robotDis[i][j]+1;}
    if(!visit[i][j+1] && robotDis[i][j+1]>robotDis[i][j]+1){robotDis[i][j+1]=robotDis[i][j]+1;}
    if(!visit[i-1][j] && robotDis[i-1][j]>robotDis[i][j]+1){robotDis[i-1][j]=robotDis[i][j]+1;}
    if(!visit[i][j-1] && robotDis[i][j-1]>robotDis[i][j]+1){robotDis[i][j-1]=robotDis[i][j]+1;}
    moveRobotFirst(i,j+1,n,m,visit,visitCell,robotDis);
    moveRobotFirst(i+1,j,n,m,visit,visitCell,robotDis);
    moveRobotFirst(i-1,j,n,m,visit,visitCell,robotDis);
    moveRobotFirst(i,j-1,n,m,visit,visitCell,robotDis);
    /*

    if(!visit[i+1][j] && robotDis[i+1][j]>robotDis[i][j]+1){robotDis[i+1][j]=robotDis[i][j]+1;moveRobotFirst(visit,robotDis,n,m,i+1,j);}
    if(!visit[i][j+1] && robotDis[i][j+1]>robotDis[i][j]+1){robotDis[i][j+1]=robotDis[i][j]+1;moveRobotFirst(visit,robotDis,n,m,i,j+1);}
    if(!visit[i-1][j] && robotDis[i-1][j]>robotDis[i][j]+1){robotDis[i-1][j]=robotDis[i][j]+1;moveRobotFirst(visit,robotDis,n,m,i-1,j);}
    if(!visit[i][j-1] && robotDis[i][j-1]>robotDis[i][j]+1){robotDis[i][j-1]=robotDis[i][j]+1;moveRobotFirst(visit,robotDis,n,m,i,j-1);}
    */
}
void moveRobotSecond(ll i,ll j,ll n, ll m,vector<vector<ll> >&visit,vector<vector<bool> >& visitCell,vector<vector<ll> >& robotDis){ ct++;//cout<<" --> "<<++ct<<").["<<i<<","<<j<<"] ";

    if(outOfTable(i,j,n,m)) return;
    if(visit[i][j] || visitCell[i][j]) return;
    visitCell[i][j]=true;
    if(!visit[i+1][j] && robotDis[i+1][j]>robotDis[i][j]+1){robotDis[i+1][j]=robotDis[i][j]+1;}
    if(!visit[i][j+1] && robotDis[i][j+1]>robotDis[i][j]+1){robotDis[i][j+1]=robotDis[i][j]+1;}
    if(!visit[i-1][j] && robotDis[i-1][j]>robotDis[i][j]+1){robotDis[i-1][j]=robotDis[i][j]+1;}
    if(!visit[i][j-1] && robotDis[i][j-1]>robotDis[i][j]+1){robotDis[i][j-1]=robotDis[i][j]+1;}
    moveRobotSecond(i,j-1,n,m,visit,visitCell,robotDis);
    moveRobotSecond(i+1,j,n,m,visit,visitCell,robotDis);
    moveRobotSecond(i-1,j,n,m,visit,visitCell,robotDis);
    moveRobotSecond(i,j+1,n,m,visit,visitCell,robotDis);
    /*if(!visit[i+1][j] && robotDis[i+1][j]>robotDis[i][j]+1){robotDis[i+1][j]=robotDis[i][j]+1;moveRobotSecond(visit,robotDis,n,m,i+1,j);}
    if(!visit[i][j+1] && robotDis[i][j+1]>robotDis[i][j]+1){robotDis[i][j+1]=robotDis[i][j]+1;moveRobotSecond(visit,robotDis,n,m,i,j+1);}
    if(!visit[i-1][j] && robotDis[i-1][j]>robotDis[i][j]+1){robotDis[i-1][j]=robotDis[i][j]+1;moveRobotSecond(visit,robotDis,n,m,i-1,j);}
    if(!visit[i][j-1] && robotDis[i][j-1]>robotDis[i][j]+1){robotDis[i][j-1]=robotDis[i][j]+1;moveRobotSecond(visit,robotDis,n,m,i,j-1);}
    */
}
int main(){
    ll t; cin >> t;while(t--){
        ll n,m,k1,k2; cin >> n >> m >> k1 >> k2 ;
        vector<vector<ll> >visit(n+2,vector<ll>(m+2,1)); for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin >> visit[i][j];
        vector<vector<ll> >firstRobotDis(n+2,vector<ll>(m+2,INT_MAX)), secondRobotDis(n+2,vector<ll>(m+2,INT_MAX)) ;
        firstRobotDis[1][1]=secondRobotDis[1][m]=0LL;
        vector<vector<bool> > visitA(n+2,vector<bool>(m+2,false)), visitB(n+2,vector<bool>(m+2,false));
        moveRobotFirst (1,1,n,m,visit,visitA,firstRobotDis);
        moveRobotSecond(1,m,n,m,visit,visitB,secondRobotDis);
        //cout<<"FIRST ROBOT "<<endl;for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=m;j++) print(firstRobotDis[i][j],3);cout<<endl;
        //cout<<"SECOND ROBOT "<<endl;for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=m;j++) print(secondRobotDis[i][j],3);cout<<endl;
        ll ans=INT_MAX;
        if(m==1LL) ans=0LL;//same cell
        else if(!k1&&!k2);//impossible to meet, as they can not move
        else if(!k1){ // first cannot move, possible meet at cell(0,0) ~ (1,1)
            if(secondRobotDis[1][1]!=INT_MAX) ans=(secondRobotDis[1][1]+k2-1)/k2;
        } else if(!k2){ // second cannot move, possible meet at cell(0,m-1) ~ (1,m)
            if(firstRobotDis[1][m]!=INT_MAX) ans=( firstRobotDis[1][m]+k1-1)/k1;
        }else{
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=m;j++){
                    if(!visit[i][j] && firstRobotDis[i][j]!=INT_MAX && secondRobotDis[i][j]!=INT_MAX){
                        ans=min(ans,max( ( firstRobotDis[i][j]+k1-1)/k1, (secondRobotDis[i][j]+k2-1)/k2 ));
                    }
                }
            }
        }
        if(ans!=INT_MAX) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }return 0;
}
