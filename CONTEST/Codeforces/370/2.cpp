#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    int N=s.length();
    if(N%2){
        cout<<"-1"<<endl;
    }else{
        int L=0,D=0,R=0,U=0;
        for(int i=0;i<N;i++){
            if(s[i]=='R') R++;
            else if(s[i]=='L') L++;
            else if(s[i]=='U') U++;
            else D++;
        }
        cout<<( abs(R-L)+abs(U-D)  )/2<<endl;
    } return 0;
}
