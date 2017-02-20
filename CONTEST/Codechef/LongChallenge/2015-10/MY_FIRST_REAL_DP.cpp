/*
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY
    KARNATAKA SURATHKAL

    MY FIRST DP...HELLO DP WORLD
    LET SEE WHAT WILL HAPPEN
    facebook.com/rameshc10695
*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[100005][1005];

int main(){


    long long int n,m,c;

    cin >> n >> m >> c;

    long long int N[n];

    for(int i=0;i<n;i++){

        cin >> N[i];
    }

    long long int M[m];

    for(int i=0;i<m;i++){

        cin >> M[i];
    }

    sort(N,N+n);
    sort(M,M+m);

    vector<long long int> fit; fit.clear();

    for(int i=0,j=0;i<n && j<m;){

        int curr=N[i];
        long long int _n=0;
        long long int _m=0;

        for(;i<n && curr==N[i];++i){

            _n++;
        }

        //Very Tricky One......Think ):D
        while(j<m && M[j]<curr)j++;

        for(;j<m && curr==M[j];++j){

            _m++;
        }

        if( _n && _m) fit.push_back( (_n*_m) %MOD);
    }

    memset(dp,0,sizeof(dp));

    int size=fit.size();

    for(int i=0;i<=c;i++){

        dp[i][0]=0;
    }

    for(int j=0;j<=size;j++){

        dp[0][j]=0;
    }
    long long int pre;
    for(int i=1;i<=size;i++){

        pre=(dp[i-1][1]+fit[i-1])%MOD;
        dp[i][1]=(int)pre;
    }

    for(int j=2;j<=c+1;j++){

        for(int i=1;i<=size;i++){

            if(i<j) dp[i][j]=0;
            else{

                pre=dp[i-1][j-1];
                pre=(fit[i-1]*pre+dp[i-1][j])%MOD;
                dp[i][j]=(int)pre;
            }
        }
    }

/*
    for(int i=0;i<size;i++){

        cout<<fit[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=size;i++){

        for(int j=0;j<=c+1;j++){

            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    for(int i=2;i<=c+1;i++){

        cout<<dp[size][i]<<" ";
    }
    cout<<endl;

    return 0;
}
