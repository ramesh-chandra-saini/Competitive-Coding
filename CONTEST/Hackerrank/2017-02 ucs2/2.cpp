#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool solve(ll p,ll st,string &s,ll ct){
    if(st>=s.length()) //divided completely
        return ct>=2;
    if(s[st]=='0')//first element is zero
        return false;
    ll temp = 0;
    while(temp<=p && st<s.length())//segment
        temp = temp*10LL+(s[st]-'0'),st++;
    if(temp==p+1)//consecutive
        return solve(temp,st,s,ct+1);
    return false;
}
int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;  cin >> s;
        ll p=0;
        bool flag = false;
        if(s[0]==0){
            p = 0;
            flag = solve(p,1,s,1);
        }else{
            for(ll i=0;i<s.length()/2 && !flag;i++){
                p = p*10LL+(s[i]-'0'); //cout<<p<<" ";
                flag |= solve(p,i+1,s,1);
            } 
        }
        (flag==false)?cout<<"NO"<<endl:cout<<"YES "<<p<<endl;
    }
    return 0;
}

