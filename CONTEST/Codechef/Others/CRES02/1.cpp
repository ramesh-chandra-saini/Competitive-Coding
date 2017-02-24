#include<bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    string s; cin >> s;
    int K ; cin >> K;
    for(int i=0;i<N;i++){
        if(s[i]>='a' && s[i]<='z')
            s[i]=(s[i]-'a'+K)%26+'a';
        else if(s[i]>='A' && s[i]<='Z')
            s[i]=(s[i]-'A'+K)%26+'A';
    }
        cout<<s<<endl;
    return 0;
}
