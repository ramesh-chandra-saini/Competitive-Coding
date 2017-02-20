/*

    Ramesh Chandra
    BTech CSE Pre Final Year
    NITK
*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int N=s.length();

    bool flag=false;
    int A=0,B=0,C=0;
    for(int i=0;i<N && !flag;i++){

        A=s.at(i)-'0';
        if(A%8==0 && A) {flag=true;cout<<"YES"<<endl<<A<<endl;}

        for(int j=i;j<N && !flag;j++){

            B=A*10+s.at(j)-'0';
            if(B%8==0 && B) {flag=true;cout<<"YES"<<endl<<B<<endl;}


            for(int k=j;k<N && !flag;k++){

                C=B*10+s.at(k)-'0';
                if(C%8==0 && C){flag=true;cout<<"YES"<<endl<<C<<endl;}
            }
        }
    }
    if(!flag) cout<<"NO"<<endl;
    return 0;
}
