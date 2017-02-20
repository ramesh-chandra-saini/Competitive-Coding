#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin >> s[i];
     bool flag=false;
     for(int i=0;i<n && !flag;i++){
        if(s[i][0]==s[i][1] && s[i][1]=='O'){
            s[i][0]=s[i][1]='+';
            flag=true;
        }else if(s[i][3]==s[i][4] && s[i][4]=='O'){
            s[i][3]=s[i][4]='+';
            flag=true;
        }
     }
    if(!flag) {
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<s[i]<<endl;
        }
    }

}
