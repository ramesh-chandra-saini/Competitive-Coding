#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;
        if(s.length()==1){
            cout<<"NO"<<endl; continue;
        }
        string A=s.substr(0,s.length()/2),B=s.substr(s.length()/2,s.length()-1);
       // cout<<A<<" "<<B<<endl;
        if(s.length()%2==0){

                if(A==B) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                continue;
        }
        string C=s.substr(0,1+s.length()/2),D=s.substr(1+s.length()/2,s.length()-1);
        //cout<<C<<" "<<D<<endl;

        int i=0,j=0;
        int mismatch=0;
        bool flag=false;
        for(;i<A.length() && j<B.length();){
            if(A[i]!=B[j]) j++, mismatch++;
            else i++,j++;
        }
        if(mismatch<=1 && i==A.length()) flag=true;
        i=0,j=0,mismatch=0;
        for(;i<C.length() && j<D.length();){
            if(C[i]!=D[j]) i++, mismatch++;
            else i++,j++;
        }
         if(mismatch<=1 && j==D.length()) flag=true;

         (flag)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}
