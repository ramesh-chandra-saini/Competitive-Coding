#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,d; cin >> n >> d;
    string str;
    int ans=0;
    int currAns=0;
    while(d--){

        cin >> str;
        bool flag=true;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0') flag=false;
        }
        if(flag) currAns=0;
        else currAns++;
        ans=max(ans,currAns);
    }
    cout<<ans<<endl;
    return 0;
}
