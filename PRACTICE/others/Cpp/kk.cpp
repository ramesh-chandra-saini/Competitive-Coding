#include<bitts/stdc
vector<string> Solution::prefix(vector<string> &A){
    vector<string> ans; ans.clear();
    int hash[26]; memset(hash,0,sizeof(hash));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].length();j++){
           hash[ (A[i][j]-'a') ]++;
        }
    }
    for(int i=0;i<A.size();i++){
        string pr; pr.clear();int j=0;
        for(;j<A[i].length()-1;){
            if(hash[A[i][j]]==1) break;
            else {pr.push_back(A[i][j]); j++;}
        }
        pr.push_back(A[i][j]);
        ans.push_back(pr);
    }
}
