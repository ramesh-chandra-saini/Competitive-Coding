#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("c.txt","r",stdin);
    int n,m; cin >>  n >> m ;
    vector<vector<int> > group(m+1,vector<int>());
    vector<int> arr(n+1);
    vector<int> unLiked;
    for(int i=1,grp;i<=n;i++){
        cin >> grp; arr[i]=grp;
        if(grp<=m){
            group[grp].push_back(i);
        }else{
            unLiked.push_back(i);
        }
    }
    for(int i=1;i<)


    int mn = ( n+m-1 )/m;
    vector<int> extra;
    for(int i=1;i<=m;i++){
        while(mn<group[i].size()){
            extra.push_back(group[i].back());
            group[i].pop_back();
        }
    }
    int estr = 0 ;
    while(extra.size()){
        int idx = 1,sz = group[1].size();
        for(int j=1;j<=m;j++){
            if(sz>group[j].size()){
                sz = group[j].size();
                idx=j;
            }
        }
        estr++;
        group[idx].push_back(extra.back());
        extra.pop_back();
    }

    while(true && unLiked.size()){
        bool flag = false;
        for(int j=1;j<=m;j++){
            if(group[j].size()<n/m){
                group[j].push_back(unLiked.back());
                unLiked.pop_back();
                flag=true;
                estr++;
            }
        }
        if(flag==false)
            break;
    }

    int mnx = INT_MAX;
    for(int i=1;i<=m;i++){
        mnx = min(mnx,(int)group[i].size());
        for(int j=0;j<group[i].size();j++){
            arr[group[i][j]] = i;
        }
    }
    cout<<mnx<<" "<<estr<<endl;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" "; cout<<endl;
    return 0;
}
