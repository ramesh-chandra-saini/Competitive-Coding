#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        for(int i=0;i<a.length();i++)
            a[i]=tolower(a[i]),b[i]=tolower(b[i]);
        if(a==b) cout<<"equal"<<endl;
        else if(a<b) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }
        return 0;
}
