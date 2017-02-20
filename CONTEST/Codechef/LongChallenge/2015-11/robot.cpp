/*
    AUTHOR : RAMESH CHANDRA
*/

#include<bits/stdc++.h>
using namespace std;
/*
int  R[1000000001];
bool V[1000000001];
*/
int main(){

    int T,N,M,i,j,g,gotCake=0,start;
    cin >> T;
    while(T--){

        cin >> N >> M;
        if(N==1 )cout<<"Yes"<<endl;
        else {

                if(M==0)cout<<"No "<<N-1<<endl;
                else{
                g=__gcd(N,M);
                gotCake=N/g;

                if(gotCake==N)cout<<"Yes"<<endl;
                else cout<<"No "<<gotCake<<endl;
                }
        }
    }
    return 0;
}
