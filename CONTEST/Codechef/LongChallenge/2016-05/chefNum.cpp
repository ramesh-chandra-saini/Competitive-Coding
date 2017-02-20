#include<bits/stdc++.h>
using namespace std;
#define M 1000
int dp[M];
int amazingness(int a[],int n){
    int ans = 0,val,i,j;set<int> s;
    for (i = 0; i < n; i++ ) {
         for ( j = i,val=0; j < n; j++ ) {
            val ^= a[j];
            s.insert(val);
         }
   }
   for(int i=n-1;i>=0;i--) cout<<a[i]; cout<<" --> ";
   for(set<int> :: iterator it=s.begin();it!=s.end();++it)
        ans+=*it,cout<<*it<<" "; cout<<endl;
   return ans;
}
void SOLVE(){
     dp[0]=0;int a[11],j,temp,n=0;for(int i=0;i<11;i++) a[i]=0;
    for(int i=1;i<=M;i++){
       j=0,a[0]++;//increase number..to get next number
       while(a[j]>=10) a[j]%=10,j++,a[j]+=1;//propagate carry..
       if(a[n]!=0) n++;//increase number of decimal bits
       //for(int i=n-1;i>=0;i--) cout<<a[i]; cout<<endl;
       dp[i]=dp[i-1]+amazingness(a,n);
    }
}
int main(){
    clock_t s=clock(),e;
   SOLVE();   e=clock(); double duration=(double)(e-s)/CLOCKS_PER_SEC; cout<<"RunTime : "<<duration<<endl; //cout<<mx<<endl;
   int t,l,r; scanf("%d",&t);
   while(t--){
       scanf("%d%d",&l,&r);
       printf("%d\n",(dp[r]-dp[l-1]));
   }

   return 0;
}
