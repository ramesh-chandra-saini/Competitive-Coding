#include<bits/stdc++.h>
using namespace std;
#define spend first
#define get second

int main(){

    int n; cin >> n;
    vector< pair< int, pair<int,int> > > P(n);
    for(int i=0,a,b;i<n;i++){
          cin >> a >> b ;
        pair< int, pair<int,int> > c = make_pair( a-b, make_pair( a , b ) );
        P[i]=c;
    }
    sort(P.begin(),P.end());
    int curr=0,ans=0;
    for(int i=0;i<n;i++){
        if(P[i].second.first>curr){
            ans+=(P[i].second.first-curr);
            curr+=(P[i].second.first-curr);
        }
        curr-=P[i].second.first;
        curr+=P[i].second.second;
    }
    cout<<ans<<endl;

    return 0;
}
