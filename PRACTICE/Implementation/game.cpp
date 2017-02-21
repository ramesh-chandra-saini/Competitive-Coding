#include <bits/stdc++.h>
using namespace std;
vector<int> cumm(200005,0);
vector<int>    a(200005,0);
int sum(int l,int r){
    return cumm[r]-cumm[l-1];
}
int inc(int l,int r){
    vector<int> sum(r+1,0);
    int ans = 0,__sum=0;
    map<int,int> mp; mp.clear();
    for(int i=l;i<=r;i++){
        for(map<int,int>::iterator it = mp.begin();it!=mp.end();++it)
            if(it->first<a[i])
                __sum = max(__sum,it->second);
        if(mp.find(a[i])==mp.end()) mp[a[i]]=__sum+a[i];
        else mp[a[i]] = max(mp[a[i]],__sum+a[i]);
        ans = max(ans,mp[a[i]]),__sum=0;
    }
    return ans;
}
int f(int l,int r){

    int value =sum(l,r)-inc(l,r);
    cout<<sum(l,r)<<" "<<inc(l,r)<<"  --> "<<value<<" "<<(r-l+1)<<endl;
    return value;
}
int main(){

    int n,k; k=scanf("%d",&n);
    for(int i=0;i<n;i++)
        k=scanf("%d",&a[i]),cumm[i]=cumm[i-1]+a[i];
    int g = INT_MIN;
    int m = INT_MAX;
    map<pair<int,int>,int> mp; mp.clear();
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            int F = f(l,r);
            mp[make_pair(r-l+1,F)]++;
            if(g<F)
                g=F,m=r-l+1;
            else if(g==F)
                m=min(m,r-l+1);
        }
    }
    k=printf("%d %d\n",g,mp[make_pair(m,g)]);
    return 0;
}
