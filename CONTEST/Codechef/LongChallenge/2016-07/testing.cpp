#include<bits/stdc++.h>
using namespace std;
vector<bool> getBits(int N,int bits){
    vector<bool> ans(3);
    for(int i=0;i<=2;i++)
        ans[3-1-i]=N%2,N/=2;
    return ans;
}
int main(){

    int n; cin >> n;int ct=0;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){ cout<<"["<<i<<","<<j<<"] : ";
            for(int k=j+1;k<n;k++){
                for(int l=k;l<n;l++){
                        cout<<" ["<<k<<","<<l<<"]"<<endl; ct++;
                }
            }
        }
    }  cout<<ct++;

/*
    set<int> i;
    i.insert(4);
    i.insert(5);
    i.insert(6);

    for(set<int>::iterator it=i.begin();it!=i.end();++it){
        cout<<*it<<" ";
        i.erase(it);
    }*/
    /*

    while(1){
    int n; cin >> n;
    vector<bool> ans=getBits(n,3);
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" "; cout<<endl;
    }*/
   return 0;
}
