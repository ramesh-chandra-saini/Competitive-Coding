#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int>&f){
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            if(f[i] && f[j] && f[i]!=f[j])
                return false;
    return true;
}
int main() {
    string str; cin >> str;
    vector<int> f(26,0);
    for(int i=0;i<str.length();i++){
        ++f[str[i]-'a'];
    }

    bool ans = false;
    ///Trying to make them, as frequent as least frequent character
    int min_f=str.length();
    for(int i=0;i<26;i++)
        if(f[i])
            min_f = min(min_f,f[i]);
    int removal = 0;
    for(int i=0;i<26;i++)
        if(f[i])
        removal+=f[i]-min_f;
    ans |= (removal<=1);

    ///just removing one char
    for(int i=0;i<26;i++){
        if(f[i]==1){
            f[i]=0;//removed one char,with
            break;
        }
    }
    min_f=str.length();
    for(int i=0;i<26;i++)
        if(f[i])
            min_f = min(min_f,f[i]);
    removal = 0;
    for(int i=0;i<26;i++)
        if(f[i])
        removal+=f[i]-min_f;
    ans |= (removal==0);

    if (ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
