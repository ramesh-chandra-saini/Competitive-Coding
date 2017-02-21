#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;while(t--){
        string s; cin >> s;
        vector<int> fr(26,0);
        for(int i=0;i<s.length();i++){
            fr[s[i]-'A']++;
        }
        long double ans=0.0;
        for(int i=0;i<26;i++){
            long double N = (long double) s.length();
            long double F = (long double) fr[i];
            ans+=(F/N)*F;
        }
        printf("%Lf\n",ans);
    } return 0;
}
