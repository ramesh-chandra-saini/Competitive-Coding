#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll> >dp(100005,vector<ll>(3,-1));
#define MOD 1000000007
ll solve(ll n , ll k, string&str){
    if(n<0 ){
        if(k==1) return 1;
        else return 0;
    }
    if(dp[n][k]!=-1) return dp[n][k];
    long long int ans=0;
    if(k==0){
        ans=solve(n-1,0,str)+solve(n-1,1,str)*('Z'-str[n]);
    }else if(k==1){
        ans=solve(n-1,1,str)*('Z'-str[n]+1)  + solve(n-1,2,str)*(str[n]-'A');
    }else if(k==2){
        ans=solve(n-1,1,str)*('Z'-str[n]) + solve(n-1,2,str)*(str[n]-'A'+1);
    }
    return dp[n][k]=ans%MOD;

}
int main(){

        string str; cin >> str;
        cout<<solve(str.length()-1,0,str)<<endl;

}
