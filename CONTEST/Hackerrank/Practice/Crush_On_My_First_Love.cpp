#include<bits/stdc++.h>
using namespace std;

vector<long long int> Bit(10000007,0LL);
long long int N;
void update(long long int idx,long long int value){

    for(;idx<=N;idx+=idx & -idx)
        Bit[idx]+=value;
}
long long int query(int idx){

    long long int sum=0;
    for(;idx>0; idx-=idx&-idx)
        sum+=Bit[idx];
    return sum;
}
int main(){


    long long int Q,a,b,K;
    cin >> N >> Q;

    while(Q--){
        cin >> a >> b >> K;
        update(a,K);
        update(b,-K);
    }
    long long int ans=INT_MIN;
    for(long long int i=1;i<=N;i++)
        ans=max(ans,query(i));
    cout<<ans<<endl;
    return 0;
}
