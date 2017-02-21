/*

Author : Ramesh Chandra
National Institute of Technology Karnataka Surathkal

f(n)=f(n-1)+f(n-2)+2g(n-2)
g(n)=g(n-1)+f(n-1)
f(1)=f(0)=g(1)=1 and g(0)=0

Matrix method solution

|f(n+1)|   |1 1 2| |f(n)  |
|f(n)  | = |1 0 0| |f(n-1)|
|g(n)  |   |0 1 1| |g(n-1)|

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Mod 1000000007
ll Fn=0,Gn=0;
ll f1=1,f0=1,g1=1,g0=0;
void matMult(ll a[3][3],ll b[3][3]){
    ll c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=0;
            for(int k=0;k<3;k++){
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%Mod)%Mod;
            }
        }
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j]=c[i][j];
}
void Solve(ll n){

    ll  matrix[3][3]={{1,1,2},{1,0,0},{0,1,1}};
    ll Ans[3][3]={{1,1,2},{1,0,0},{0,1,1}};
    n--;
    while(n){
        if(n%2)
            matMult(Ans,matrix);
        matMult(matrix,matrix);
        n/=2LL;
    }
    Fn=(Ans[1][0]*f1+Ans[1][1]*f0+Ans[1][2]*g0)%Mod;
    Gn=(Ans[2][0]*f1+Ans[2][1]*f0+Ans[2][2]*g0)%Mod;
}
int main(){
/*

   //Naive approach--tester solution
    ll __f[1000];
    ll __g[1000];
    __f[1]=__f[0]=__g[1]=1;__g[0]=0;
    for(int i=2;i<1000;i++){
        __f[i]=(__f[i-1]+__f[i-2]+2*__g[i-2])%Mod;
        __g[i]=(__g[i-1]+__f[i-1])%Mod;
    }
*/
    ll n,Q; char c;
    cin >> Q;
    while(Q--){

        cin >> n >> c;
        Solve(n);
        if(c=='f') cout<<Fn<<endl;
        else cout<<Gn<<endl;
       // cout<<Fn<<" == " << __f[n]<<endl<<Gn<<" == " << __g[n]<<endl;
    }
    return 0;
}
