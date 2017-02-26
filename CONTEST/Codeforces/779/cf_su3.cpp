#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
bool __cmp(pair<pair<int,int> ,int >A,pair< pair<int,int>,int  > B){
    if(A.first.first-A.first.second != B.first.first-B.first.second)
        return A.first.first-A.first.second < B.first.first-B.first.second;
    return A.first.first<B.first.first;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n,k; cin >> n >> k;
    int A[n],B[n];
    for(int i=0;i<n;i++)
        cin >> A[i];
    for(int i=0;i<n;i++)
        cin >> B[i];
    vector<pair< pair<int,int>,int > >dp(n);
    for(int i=0;i<n;i++)
        dp[i] = mp(mp(A[i],B[i]),i);
    sort(dp.begin(),dp.end(),__cmp);
    long ans = 0;
    for(int i=0;i<k;i++)
        ans+=A[dp[i].second];
    for(int i=k;i<n;i++)
        ans+=(A[dp[i].second]<B[dp[i].second])?A[dp[i].second]:B[dp[i].second];
    cout<<ans<<endl;
    return 0;
}

