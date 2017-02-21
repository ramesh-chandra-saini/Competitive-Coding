#include<bits/stdc++.h>
using namespace std;
set<pair<int,string> >globalAns;
bool isPalindrome(string&A){
    int N=A.size();
    for(int i=0;i<N;i++){
        if(A[i]!=A[N-1-i]){
            return false;
         }
    }  return true;
}
void solve(int curr,int target,string currPath,int n,vector<vector<char> >&graph){
    if(curr==target){
        if(isPalindrome(currPath)){
            globalAns.insert(make_pair(-currPath.length(),currPath));
        }
        return;
    }
    for(int i=curr+1;i<n;i++){
        if(graph[curr][i]!='*'){
            currPath.push_back(graph[curr][i]);
            solve(i,target,currPath,n,graph);
            currPath.erase(currPath.begin()+currPath.size()-1);
        }
    }
}
int main(){

    int t; scanf("%d",&t); while(t--){
        int n; scanf("%d",&n);
        vector<vector<char> > graph(n,vector<char>(n,'*'));
        for(int i=0;i<n;i++){
            string str;      cin >> str;
            for(int j=i+1;j<n;j++){
                graph[i][j]=str[j];
            }
        }
        globalAns.clear();
        string currAns; currAns.clear();
        solve(0,n-1,currAns,n,graph);
        if(globalAns.size()){
            set<string> ans; ans.clear();
            int length = globalAns.begin()->first;
            for(set<pair<int,string> >::iterator it=globalAns.begin();it!=globalAns.end();++it){
                if(it->first==length){
                    ans.insert(it->second);
                }else {
                    break;
                }
            }
            cout<<(*ans.begin())<<endl;
        }else{
            printf("NO PALINDROMIC PATH\n");
        }
    }
}
