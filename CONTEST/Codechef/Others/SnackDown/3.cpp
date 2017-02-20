#include<bits/stdc++.h>
using namespace std;
int dp[26][26];
int solve(vector<pair<int,int> > & arr,int i,int j,int K){
    if(arr[j].first-arr[i].first<=K) return 0;
    return (dp[i][j]!=-1)? dp[i][j]: dp[i][j]=
        min(
                (arr[i].first*arr[i].second) //remove lesser frequency terms.
                +solve(arr,i+1,j,K)//solve for further recursion.
                ,
                (arr[j].first-(arr[i].first+K))*arr[j].second//remove only extra part of frequency.
                +solve(arr,i,j-1,K) //solve for futher recursion.
        );
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                dp[i][j]=-1;
        string str; int K,__min=INT_MAX;
        cin >> str >> K;
        vector<int> freq(26,0);
        for(int i=0;i<str.length();i++)
            freq[str[i]-'a']++;
        //for(int i=0;i<26;i++) if(freq[i])cout<<(char)(i+'a')<<" : "<<freq[i]<<endl;
        vector<int> arr; arr.clear();
        for(int i=0;i<26;i++)
            if(freq[i]) arr.push_back(freq[i]);
        sort(arr.begin(),arr.end());
        vector<pair<int,int> > pairVector;pairVector.clear();
        for(int i=0;i<arr.size();){
            int value=arr[i],ct=0;
            while(i<arr.size() && value==arr[i]) i++,ct++;
            //cout<<value<<" , "<<ct<<endl;
            pairVector.push_back(make_pair(value,ct));
        }
        cout<<solve(pairVector,0,pairVector.size()-1,K)<<endl;
    }
    return 0;
}
