/*

    RAMESH CHANDRA & DHARMENDRA SINGH
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL

    TAGLINE : FINDING LOOP HOLE

*/

#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

vector<vector<long long int> > mult(long long int x , vector<vector<long long int> > &A,vector<vector<long long int> > &B){
    vector<vector<long long int> > C(x,vector<long long int> (x,0));
    for(long long int i=0;i<x;i++)
        for(long long int j=0;j<x;j++)
            for(long long int k=0;k<x;k++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
    return C;
}
vector<vector<long long int> > POWER(long long int x,vector< vector<long long int> > &T,long long int b){
    vector<vector<long long int> > ans(x,vector<long long int> (x));
    ans=T,b--;
    while(b){
        if(b%2)
            ans=mult(x,ans,T);
        T=mult(x,T,T), b/=2;
    }
    return ans;
}
#define PI 3.14196
int main(){
 cout<<__gcd(5033464705,3137640337)<<endl;
    cout<<sin(90*(PI/180.0))<<endl;

    long long int n,b,k,x;
    cin >> n >> b >> k >> x;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
        cin >> arr[i];
    vector < vector<long long int> > T(x,vector<long long int> (x,0));
        for(long long int t=0;t<x;t++)
                for(long long int i=0;i<n;i++)
                    T[(t*10+arr[i])%x][t]++;
    T=POWER(x,T,b);
    printf("%lld\n",T[k][0]);
    return 0;
}
