#include<bits/stdc++.h>
using namespace std;
#define milk first
#define apple second
int solve(int idx,int N,int E,pair<int,int> arr[]){

    if(idx==N+1)
        return 0;
    if(E<0)
        return 0;
    return max(
        arr[idx].apple+solve(idx+1,N,E-1,arr), //pick apple
        0+solve(idx+1,N,E-1+arr[idx].milk,arr)); //pick milk
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,e; cin >> n >> e;
        pair<int,int> arr[n+1];
        for(int i=1;i<=n;i++)
            cin >> arr[i].milk;
        for(int i=1;i<=n;i++)
            cin >> arr[i].apple;
        cout<<solve(1,n,e-1,arr)<<endl;
    }
    return 0;
}
