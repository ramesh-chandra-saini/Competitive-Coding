#include<bits/stdc++.h>
using namespace std;
#define M 1000000
set<int>  dp[M+1];
int amazingness[M+1];
void SOLVE(){
    set<int> ::iterator it; int prev,newPart,i;
     amazingness[0]=0;for(i=1;i<=9;++i) dp[i].insert(i),amazingness[i]=amazingness[i-1]+i;
     for(i=10;i<=M;++i){
        prev=i/10,newPart=i%10;
        dp[i]=dp[prev];dp[i].insert(newPart);
        for(it=dp[prev].begin();it!=dp[prev].end();++it)
            dp[i].insert((*it)^newPart);
        amazingness[i]=amazingness[i-1];
        for(it=dp[i].begin();it!=dp[i].end();++it)
          amazingness[i]+=*it;
     }
}
int main(){
    clock_t s=clock(),e;
   SOLVE();   e=clock(); double duration=(double)(e-s)/CLOCKS_PER_SEC; cout<<"RunTime : "<<duration<<endl; //cout<<mx<<endl;
   int t,l,r; scanf("%d",&t);
   while(t--){
       scanf("%d%d",&l,&r);
       printf("%d\n",(amazingness[r]-amazingness[l-1]));
   }
   return 0;
}
