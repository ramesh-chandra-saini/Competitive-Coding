#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool validMove(ll i, ll j,ll N,ll M,vector<vector<bool> >&visit,vector<vector<ll> >&mat,ll K){
    return (i>=1 && i<=N && j>=1 && j<=M && visit[i][j]==false && mat[i][j]>=K);
}
void drive(ll i,ll j,ll n,ll m,vector<vector<bool> >&visit,vector<vector<ll> >&mat,ll K){
                    //right direction
                    if(validMove(i,j+1,n,m,visit,mat,K)==true){
                        drive(i,j+1,n,m,visit,mat,K);//
                    }else
                    //left direction
                    if(validMove(i,j-1,n,m,visit,mat,K)==true){
                        drive(i,j-1,n,m,visit,mat,K);//
                    } else
                     //up direction
                      if( validMove(i-1,j,n,m,visit,mat,K)==true){
                        drive(i,j-1,n,m,visit,mat,K);//
                    } else
                    //down direction
                    if(validMove(i+1,j,n,m,visit,mat,K)==true){
                        drive(i+1,j,n,m,visit,mat,K);//
                    }
}
int main() {
    ll t; cin >> t; while(t--){
        ll n,m,q,K; cin >> n >> m >> q >> K;
        vector<vector<ll> > mat(n+1,vector<ll>(m+1,0));
        while(q--){
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            for(ll i=x1;i<=x2;i++)
                for(ll j=y1;j<=y2;j++)
                    mat[i][j]++;
        }
        vector<vector<bool> > visit(n+1,vector<bool>(m+1,false));
        ll ans = 0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(mat[i][j]>=K && visit[i][j]==false){
                    ll dir = 0;
                    visit[i][j]=true;
                    ans++;
                    //right direction
                    if(dir<2 && validMove(i,j+1,n,m,visit,mat,K)==true){
                        dir++;
                        drive(i,j+1,n,m,visit,mat,K);//
                    }
                    //left direction
                    if(dir<2 && validMove(i,j-1,n,m,visit,mat,K)==true){
                        dir++;
                        drive(i,j-1,n,m,visit,mat,K);//
                    }
                     //up direction
                      if(dir<2 && validMove(i-1,j,n,m,visit,mat,K)==true){
                        dir++;
                        drive(i,j-1,n,m,visit,mat,K);//
                    }
                    //down direction
                    if(dir<2 && validMove(i+1,j,n,m,visit,mat,K)==true){
                        dir++;
                        drive(i+1,j,n,m,visit,mat,K);//
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

