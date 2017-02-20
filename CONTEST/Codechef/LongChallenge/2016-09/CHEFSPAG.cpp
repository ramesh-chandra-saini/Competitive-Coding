#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define ll long long int
#define x first
#define y second
#define start first
#define end second
int main(){
    ll t; cin >> t;
    while(t--){
        ll N,a,b,c,d,F0,F1,F2,F3;
        cin >> N >> a >> b >> c >> d >> F0 >> F1 >> F2 >> F3;
        vector< pair <ll,ll> > points(N);
        for(ll i=0;i<N;i++){
            cin >> points[i].x >> points[i].y;
        }
        map<ll,vector<double> > Map;
        for(ll i=0;i<N;i++){
            pair <ll,ll> A = points[i];
            pair <ll,ll> B = points[(i+1)%N];
            if(A.x>B.x) swap(A,B);
            if(A.y>B.y){

            }else if(A.y<B.y){
            }else{
            }

        }
    } return 0;
}
