#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long int arr[1000];

long long int fun(long long int N) {

    long long int ans = 0;

    if (N == 1)
        return 1;

    for (long long int i=1;i<=N;i++){

        if (i == 1 || i == N){
            ans = ans + 3;
            ans%=mod;
        }
        else{
            ans = ans + fun(i - 1) + fun(N - i);
            ans%=mod;
        }
    }
    return ans;
}
int main(){


    int t;

    cin >> t;

    while(t--){


        int N;

        cin >> N;

        cout<<fun(N)<<endl;
    }
}
