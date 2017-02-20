#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string a,b,aCopy; cin >> a >> b;aCopy=b;
        int n=a.length();a.push_back('0'); a.push_back('1');
        //XOR Operation
        int ans=0,nextZero=1,nextOne=1;
        for(int i=0;i<n;i++){
            if(a[i]=='0' && b[i]=='1'){
                for(;;){
                    if(a[nextOne]=='1' && a[nextOne]!=b[nextOne]) break;
                    else nextOne++;
                }
                if(nextOne>=n) break;
                a[i]='1'; a[nextOne]='0'; ans++;
            }else if(a[i]=='1' && b[i]=='0'){
                for(;;){
                    if(a[nextZero]=='0' && a[nextZero]!=b[nextZero]) break;
                    else nextZero++;
                }
                if(nextZero>=n) break;
                a[i]='0'; a[nextZero]='1'; ans++;
            }
        } //cout<<"XOR : ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        //OR operation
        int static_one=-1;
        for(int i=0;i<n;i++)
            if(a[i]=='1' && b[i]=='1') {static_one=i; break;}
        if(static_one!=-1)
            for(int i=0;i<n;i++)
                if(a[i]=='0' && b[i]=='1') a[i]='1', ans++;
        //cout<<"OR : ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        //AND operation
        int static_zero=-1;
        for(int i=0;i<n;i++)
            if(a[i]=='0' && b[i]=='0') {static_zero=i; break;}
        if(static_zero!=-1)
            for(int i=0;i<n;i++)
                if(a[i]=='1' && b[i]=='0') a[i]='0', ans++;
        //cout<<"AND : ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        //cout<<ans<<" ";for(int i=0;i<n;i++) cout<<a[i]; cout<<endl;
        a.erase(a.begin()+n,a.end());
        if(a==b) cout<<"Lucky Chef"<<endl<<ans<<endl;
        else cout<<"Unlucky Chef"<<endl;
    }
    return 0;
}
