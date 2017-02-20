#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t; while(t--){
        string s; cin >> s;
        bool flag=true;
        for(int i=0,j=s.length()-1;i<=j;i++,j--){
            if(s[i]=='.' && s[j]=='.'){
                s[i]='a';s[j]='a';
            }else if(s[i]=='.' && s[j]!='.'){
                s[i]=s[j];
            } else if(s[i]!='.' && s[j]=='.'){
                s[j]=s[i];
            }else{
                if(s[i]!=s[j]){
                    flag=false; break;
                }else{
                    //nothing need to do
                }
            }
        }
        (flag)? cout<<s<<endl:cout<<"-1"<<endl;
    }return 0;
}
