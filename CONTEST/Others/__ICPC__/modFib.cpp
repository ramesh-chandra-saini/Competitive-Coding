#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[3][3]={{1,1,1},{1,0,0},{0,0,1}};
ll I[3][3]={{1,0,0},{0,1,0},{0,0,1}};
ll inv[3][3]={{0,1,0},{1,-1,-1},{0,0,1}};
void print(vector<vector<ll> > arr){
    for(int i=0;i<3;i++,cout<<endl)
        for(int j=0;j<3;j++)
            cout<<arr[i][j]<<" ";
}
void print(ll arr[3][3]){
    for(int i=0;i<3;i++,cout<<endl)
        for(int j=0;j<3;j++)
            cout<<arr[i][j]<<" ";
}
vector<vector<ll> > copy(ll A[3][3]){
    vector<vector<ll> > ans(3,vector<ll>(3,0));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ans[i][j]=A[i][j];
    return ans;
}
vector<vector<ll> > mult(vector<vector<ll> >A,vector<vector<ll> > B,ll m){
    vector<vector<ll> >C(3,vector<ll>(3,0));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]+m)%m;
    return C;
}
vector<vector<ll> > add(vector<vector<ll> >A,vector<vector<ll> > B,ll m){
    vector<vector<ll> >C(3,vector<ll>(3,0));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            C[i][j]=(A[i][j]+B[i][j]+m)%m;
    return C;
}
vector<vector<ll> > _minus_(vector<vector<ll> >A,vector<vector<ll> > B,ll m){
    vector<vector<ll> >C(3,vector<ll>(3,0));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            C[i][j]=(A[i][j]-B[i][j]+m)%m;
    return C;
}
vector<vector<ll> > fib( ll expo ,ll m){
    vector<vector<ll> > N=copy(a);
    vector<vector<ll> > ans=copy(I);
    for(;expo;expo/=2,N=mult(N,N,m))
        if(expo%2)
            ans = mult(ans,N,m);
    return ans;
}
int main(){

    ll n,m; cin >> n >> m;
    ll arr[n];  for(ll i=0;i<n;i++) cin >> arr[i];

    vector<vector<ll> > unit=copy(I);
    vector<vector<vector<ll> > > store(n);
    for(ll i=0;i<n;i++){
       store[i]=fib(arr[i],m);//print(store[i]);
       store[i]=add(unit,store[i],m);//print(store[i]);
    }
    vector<vector<ll> > ans=copy(I);
    for(int i=0;i<n;i++)
        ans = mult(ans,store[i],m);
    ans = _minus_(ans,unit,m);
    vector<vector<ll> > INV = copy(inv);
    ans = mult(ans,INV,m);
    ll final_ans = (ans[0][0]+ans[0][1]+ans[0][2]);//+ans[0][1]+ans[0][2])%m;
    cout<<final_ans<<endl;
    return 0;
}
