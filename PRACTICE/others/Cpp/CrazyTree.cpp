#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    string s;
    while(t--){
        s.clear();
        cin >> s;
        stack<char> S;
        bool flag = true;
        for(int i=0;flag && i<s.length();i++){
            if(s[i]=='['|| s[i]=='{' || s[i]=='(' || s[i]=='<')
                S.push(s[i]);
            else{
                if(S.empty()) flag=false;
                else{
                    char c=S.top(); S.pop();
                    if( (s[i]=='}' && c == '{' )||(s[i]==']' && c == '[' )||(s[i]==')' && c == '(' )||(s[i]=='>' && c == '<' ));
                    else flag=false;
                }
            }
        }
        if(flag && S.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
