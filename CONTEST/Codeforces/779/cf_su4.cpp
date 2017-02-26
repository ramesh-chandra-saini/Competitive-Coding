#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
bool __cmp(pair<pair<int,int> ,int >A,pair< pair<int,int>,int  > B){
    if(A.first.first-A.first.second != B.first.first-B.first.second)
        return A.first.first-A.first.second < B.first.first-B.first.second;
    return A.first.first<B.first.first;
}
int main(){
    freopen("in.txt","r",stdin);
    string a,b;
    cin >> a >> b;
    int n = a.length();
    int idx[n];
    for(int i=0;i<n;i++)
        cin >>idx[i];
    map<string,bool> mp;
    mp[b]=true;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(mp.find(a)!=mp.end())
            break;
        ans++;
        a.erase(a.begin()+idx[i]);
        cout<<a<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

