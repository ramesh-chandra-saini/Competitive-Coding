#include<bits/stdc++.h>
using namespace std;

int main(){

    int  t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ct0=0,ct1=0;
        for(int i=0;i<s.length();i++)
            (s[i]=='0')?ct0++:ct1++;

        if(ct0==1 || ct1==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    } return 0;
}

