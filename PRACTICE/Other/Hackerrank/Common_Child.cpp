#include<bits/stdc++.h>
using namespace std;
int LCS(int a,int b,string &A, string &B,vector<vector<int> >&dp){
    if(a<0 || b<0) //atleast one of string is process
        return 0;
    if(dp[a][b]!=-1)
        return dp[a][b];
    int ans = 0;
    if(A[a]==B[b]) //both character matched
        ans =  max(ans,1+LCS(a-1,b-1,A,B,dp));
    ans = max(ans,LCS(a-1,b,A,B,dp));//skip String A a'th char
    ans = max(ans,LCS(a,b-1,A,B,dp));//skip String B b'th char
    return dp[a][b]=ans;
}
int main() {
    string A,B;
    cin >> A >> B;
    int a=A.length(),b=B.length();
    vector<vector<int> > dp(a,vector<int>(b,-1));
    cout<<LCS(a-1,b-1,A,B,dp)<<endl;
    return 0;
}
