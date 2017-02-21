#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x;scanf("%d%d%d",&n,&k,&x);
    vector<int> mp(1025,0);
    for(int i=0,x;i<n;i++)
        scanf("%d",&x),mp[x]++;
    vector<int> curr(1025,0);
    while(k--){
        int total = 0,num,freq;
        for(int i=0;i<1025;i++){
            num = i,freq=mp[i];
            if(total%2==0)
                curr[(num^x)]+=(freq+1)/2,  curr[num]+=freq/2;
            else
                curr[(num^x)]+=freq/2, curr[num]+=(freq+1)/2;
            total+=mp[i];
        }
        for(int i=0;i<1025;i++)
            mp[i]=curr[i],curr[i]=0;
    }
    int mn = INT_MAX,mx = INT_MIN;
    for(int i=0;i<1025;i++)
        if(mp[i])
            mn = min(mn,i),mx = max(mx,i);
    printf("%d %d\n",mx,mn);
}
