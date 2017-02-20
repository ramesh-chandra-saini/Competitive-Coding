#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main(){
    long long int n; cin >> n;
    vector<pair<long long int,long long int> > C(n);
    for(long long int i=0;i<n;i++){
        cin >> C[i].x >> C[i].y;
    }
    vector<pair<double,double> > P;
    for(long long int i=0;i<n;i++){
        for(long long int j=i+1;j<n;j++){
        pair<double,double> p;
        p.x = (C[i].x+C[j].x+1)/2.0;
        p.y = (C[i].y+C[j].y+1)/2.0;
        P.push_back(p);
        }
    }
    sort(P.begin(),P.end());
    long long int ans=0LL,ct=0LL;
    for(long long int i=0;i<P.size();){
        pair<double,double> c = P[i]; ct=0;
        while(i<P.size() && c == P[i]){ ct++; i++; }
        ans+=(ct*(ct-1))/2LL;
    }
    cout<<ans<<endl;
    return 0;
}
