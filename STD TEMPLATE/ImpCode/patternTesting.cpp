#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool allVisited(vector<bool>&visit){
    for(ll i=0;i<visit.size();i++)
        if(visit[i]==false)
            return false;
    return true;
}
bool isGood(ll curr,string&A,vector<bool>visit,ll n){
    if(curr<0 || curr>=n || visit[curr]==true)
        return false;
    visit[curr]=true;
    if(curr==n-1)
        return allVisited(visit);
    return isGood(curr-(A[curr]-'0'),A,visit,n) + isGood(curr+(A[curr]-'0'),A,visit,n);
}
bool isGoodStrings(string&A){
    ll n = A.length();
    vector<bool> visitA(n,false);
    return isGood(0LL,A,visitA,n);
}
int main(){
    int t; cin >> t; while(t--){
        int n;cin >> n;
        long long N = (1LL<<n);
        for(long long i=0;i<N;i++){
            long long temp=i;
            string str;
            for(int j=0;j<n;j++,temp/=2)
                str.push_back(1+temp%2+'0');
            (isGoodStrings(str))?cout<<str<<" YES "<<endl:cout<<"";
        }
    }
}
