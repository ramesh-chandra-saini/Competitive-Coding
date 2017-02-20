#include<bits/stdc++.h>
using namespace std;

int fun(int N){
    int ans = 0;

    if (N == 1)
        return 1;

    for(int i=1;i<=N;i++)
        if (i == 1 || i == N){
            ans = ans + 3; cout<<"3 ";
        }
        else{
            cout<<(i-1)<<"+"<<(N-i)<<"  ";
            ans = ans + fun(i - 1) + fun(N - i);
        }
    return ans;
}
int main(){

    int t;
    cin >> t;
    for(int i=1;i<=10;i++){
        cout<<i<<" --> ";
        cout<<endl<<fun(i)<<endl;
    }
}
