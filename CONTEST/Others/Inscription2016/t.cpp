#include<bits/stdc++.h>
using namespace std;
#define N 18
#define M 17
int main(){

    freopen("t.txt","w",stdout);
    srand(time(NULL));
    int n = 1+rand()%N,m = 1+rand()%M;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char u = '0'+rand()%2;
            cout<<u;
        }cout<<endl;
    }   return 0;
}
