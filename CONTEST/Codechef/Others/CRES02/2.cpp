#include<bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    while(N--){
        string s; cin >> s;
        vector<int> f(26,0);
        for(int i=0;i<s.length();i++)
            ++f[tolower(s[i])-'a'];
        int Odd = 0;
        for(int i=0;i<26;i++)
            Odd+=f[i]%2;
        (Odd<=1)?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }
    return 0;
}
