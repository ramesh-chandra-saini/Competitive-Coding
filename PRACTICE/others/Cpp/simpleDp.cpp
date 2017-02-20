#include<bits/stdc++.h>
using namespace std;

int dp[100001][2];
int alpha=0;
int beta=0;

void fun(int T){


    if(T<=0) alpha=alpha+1;
    else if(T==1) beta=beta+1;
    else{
        fun(T-1);
        fun(T-2);
        fun(T-3);

    }
}
int main(){

    int t;
    cin >> t;
    while(t--){



    alpha=0;
    beta=0;
        int n;
        cin >> n;
        fun(n);
        cout<<alpha<<" "<<beta<<endl;
    }
    for(int i=0;i<=100000;i++)
        dp[i][0]=dp[i][1]=-1;

    return 0;
}
