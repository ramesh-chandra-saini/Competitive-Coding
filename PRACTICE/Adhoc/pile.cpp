#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[11],n,m;
bool ans[11];
bool solve(ll curr,bool turn){
    if(curr>n)
        return turn;
    turn=(true ^ turn); //successful turn change
    if(curr==n) //target achieved
        return turn;
    for(int i=1;i<=m;i++)
        if(turn==solve(curr*arr[i],turn))
            return turn;
    return (true ^ turn);
}

int main(){
    cin >> n >> m;
    for(ll i=1;i<=m;i++)
        cin >> arr[i];
    (solve(1LL,true)==true)?cout<<"First"<<endl:cout<<"Second"<<endl;
    return 0;
}
