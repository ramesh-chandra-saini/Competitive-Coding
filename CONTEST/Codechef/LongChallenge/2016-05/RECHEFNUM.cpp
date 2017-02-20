#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int dp[M];
int amazingness(int a[],int n)
{
    set<int> s;
    int ans = 0;
    for ( int i = 0; i < n; i++ ) {
         int val = 0;
         for ( int j = i; j < n; j++ ) {
            val ^= a[j];
            s.insert(val);
         }
   }
   for(set<int> :: iterator it=s.begin();it!=s.end();++it)
        ans+=*it;
   return ans;
}
void SOLVE(){
     dp[0]=0;
    for(int i=1;i<M;i++){
       int temp=i;int a[50]; int n=0;
       while(temp)
          a[n++]=(temp%10),temp/=10;
       dp[i]=dp[i-1]+amazingness(a,n);
    }
}
int main(){
   SOLVE();
   int t; scanf("%d",&t);
   while(t--){
       int l,r; scanf("%d%d",&l,&r);
       printf("%d\n",(dp[r]-dp[l-1]));
   }
   return 0;
}
