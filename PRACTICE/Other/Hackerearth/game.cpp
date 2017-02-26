#include<bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int N,Q,x,y,ans=0; scanf("%d%d",&N,&Q);
        map<int,vector<int> > __mp;
        map<int,vector<int> > ::iterator it;
        while(Q--){
            scanf("%d%d",&x,&y); --x,--y;
            if(__mp.find(x)==__mp.end())
                __mp[x]=vector<int>(3,0);
            __mp[x][y]=1;
        }
        map<int,vector<int> > mp=__mp;
        for(it=__mp.begin();it!=__mp.end();++it){
            int curr = it->first;
            //two step info...
            if(mp.find(curr+1)==mp.end() && curr+1<N)
                mp[curr+1]=vector<int>(3,0);
            if(mp.find(curr+2)==mp.end() && curr+2<N)
                mp[curr+2]=vector<int>(3,0);
        }
        if(mp.find(N-1)==mp.end()) //corner case
            mp[N-1]=vector<int>(3,0);
        vector<int> prev(3,0),curr(3,0);
        for(it=mp.begin();it!=mp.end();++it){
            ans=max(it->first-1,ans);
            curr[0] = (it->second[0]==0 &&(prev[0]==0 || prev[0+1]==0) )?0:1; //first cell
            curr[1] = (it->second[1]==0 &&(prev[1-1]==0 || prev[1]==0 || prev[1+1]==0))?0:1; //internal cell
            curr[2] = (it->second[2]==0 &&(prev[2-1]==0 || prev[2]==0 ) )?0:1;//last cell
            if(curr[0]==0|| curr[1]==0 || curr[2]==0)
                prev = curr,ans=(it->first);
            else
                break;
        }
        cout<<ans+1<<endl;
    }
}
