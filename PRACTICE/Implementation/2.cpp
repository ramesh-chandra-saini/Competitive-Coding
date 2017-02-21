#include<bits/stdc++.h>
using namespace std;
int solve(string & str){
    for(int i=0,j=str.length()-1;i<=j;i++,j--){
        if(str[i]!=str[j])
            return 1;
    }
    return 0;
}
int main(){
    int t; cin >> t; while(t--){
        int n; cin >> n;
        string str; cin >> str;
        cout<<solve(str)<<endl;
    }
}
