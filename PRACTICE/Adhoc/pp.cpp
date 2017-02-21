#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool validMove(ll i, ll j,ll N,ll M,vector<vector<int> >&visit,vector<vector<ll> >&mat,ll K){
    return (i>=1 && i<=N && j>=1 && j<=M && visit[i][j]<=1 && mat[i][j]>=K);
}
void drive(ll i,ll j,ll n,ll m,vector<vector<bool> >&visit,vector<vector<ll> >&mat,ll K){
                    //right direction
                    if(validMove(i,j+1,n,m,visit,mat,K)==true){
                        visit[i][j+1]++;
                        drive(i,j+1,n,m,visit,mat,K);//
                    }else
                    //left direction
                    if(validMove(i,j-1,n,m,visit,mat,K)==true){
                         visit[i][j-1]++;
                        drive(i,j-1,n,m,visit,mat,K);//
                    } else
                     //up direction
                      if( validMove(i-1,j,n,m,visit,mat,K)==true){
                         visit[i-1][j]++;
                        drive(i,j-1,n,m,visit,mat,K);//
                    } else
                    //down direction
                    if(validMove(i+1,j,n,m,visit,mat,K)==true){
                         visit[i+1][j]++;
                        drive(i+1,j,n,m,visit,mat,K);//
                    }
}
int main() {
    ll t; cin >> t; while(t--){
        ll n,m,q,K; cin >> n >> m >> q >> K;
        vector<vector<ll> > mat(n+1,vector<ll>(m+1,0));
        while(q--){
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            ++x1,++y1,++x2,++y2;//1-based indexing
            //cout << x1 << " "<< y1 <<" "<< x2 <<" "<< y2<<endl;
            for(ll i=x1;i<=x2;i++){
                    for(ll j=y1;j<=y2;j++){
                    mat[i][j]++;//,cout<<"("<<i<<","<<j<<") ";
                }
            } //for(ll i=1;i<=n;i++,cout<<endl) for(ll j=1;j<=m;j++) cout<<mat[i][j]<<" "; cout<<endl;
        } //for(ll i=1;i<=n;i++,cout<<endl) for(ll j=1;j<=m;j++) cout<<mat[i][j]<<" "; cout<<endl;

        ll ans = 0;
        ll H=0;
        ll V=0;
        for(ll i=1;i<=n;i++){

            for(ll j=1;j<=m;j++){

                if(mat[i][j]>=m){
                    H++;
                    while(mat[i][j]>=m)
                        j++;
                        j--;
                }

            }
        }

        for(ll j=1;j<=m;j++){

            for(ll i=1;i<=n;i++){

                if(mat[i][j]>=m){
                    V++;
                    while(mat[i][j]>=m)
                        i++;
                        i--;
                }

            }
        }
        cout<<min(H,V)<<endl;
    }
    return 0;
}

