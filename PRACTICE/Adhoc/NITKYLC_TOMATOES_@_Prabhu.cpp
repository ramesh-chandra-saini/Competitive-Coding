/*
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;
void knapSack(vector <int> & Time,int K){

    if(Time.empty()) return;
    int dp[Time.size()+1][K+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=Time.size();i++){
        for(int j=1;j<=K;j++){
            if(j<Time.at(i-1)) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-Time.at(i-1)]+Time.at(i-1));
        }
    }
    for(int i=Time.size(),j=K;i>0;--i)
        if(dp[i][j]-dp[i-1][j-Time.at(i-1)] == Time.at(i-1))
            j-=Time.at(i-1),Time.erase(Time.begin()+(i-1));
    return;
}
int main(){

    int T,N,K;
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<int> Time(N);
        for(int i=0;i<N;i++)
            cin >> Time.at(i);
        knapSack(Time,K),knapSack(Time,K),knapSack(Time,K);
        if(Time.empty()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
