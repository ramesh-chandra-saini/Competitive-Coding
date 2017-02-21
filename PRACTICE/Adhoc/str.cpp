#include<bits/stdc++.h>
using namespace std;
int ins(string &s,string &t){
    if(s==null || s.empty())
        return t.length();
    for(int i=0;i<min(s.length(),t.length());i++)
        if(s[i]!=t[i])
            break;
        else ct++;
    return t.length()-ct;
}
int main(){
    int k; string s,t; cin >> s >> t >> k;
    while(k>ins(s,t)){
        if(!s.empty()){
            s.pop_back();
            k--;
        }
    }
    (k==ins(s,t))?cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}
