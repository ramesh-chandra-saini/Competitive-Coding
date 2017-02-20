#include<bits/stdc++.h>
using namespace std;

int solve(int n,string s,string A){
    int r=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]!=A[i]){
            if(s[i]=='r'){
                r++;
            }else{
                b++;
            }
        }
    }
    int mn = min(r,b);
    r-=mn;
    b-=mn;
    return mn+r+b;
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string A,B; A.clear(),B.clear();
    for(int i=0;i<n;i++){
        if(i%2==0){
            A.push_back('r');
        }else{
            A.push_back('b');
        }
    }
    for(int i=0;i<n;i++){
        if(i%2){
            B.push_back('r');
        }else{
            B.push_back('b');
        }
    }
    cout<<min(solve(n,s,A),solve(n,s,B))<<endl;
}
