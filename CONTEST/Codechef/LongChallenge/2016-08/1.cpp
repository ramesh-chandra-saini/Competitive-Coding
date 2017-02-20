/*
==============================================================
                Author : Ramesh Chandra
        National Institute of Technology Karnataka
=============================================================
*/
#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> DP;
int numberOfCuts(int n, int m){
    if(n==1&&m==1) return 0;//base case
    return DP[make_pair(n,m)]!=0?DP[make_pair(n,m)]:DP[make_pair(n,m)]=1+((n==1)?numberOfCuts(n,m/2)+numberOfCuts(n,m-(m/2)):numberOfCuts(n/2,m)+numberOfCuts(n-(n/2),m));
}
int main(){
    int t; cin >> t; while(t--){
        int n,m; cin >> n >> m ;
        int ans = numberOfCuts(n,m);
        (ans%2)?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }  return 0;
}
