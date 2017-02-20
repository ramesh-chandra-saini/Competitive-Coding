#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int start=0,size=0;
int mult[9000000];
ll __remainder(ll N,ll D){
    return (N<D)?N:N%D;ŝ
}
void multiply(ll N){

    ll temp=0LL;
    int carry=0;
      start=  max(0,size-9);
    for(ll i=start;i<size;i++){
        temp=carry+N*mult[i];
        mult[i]=temp%10;
        carry=temp/10;
    }
    while(carry) mult[size++]=(carry%10), carry/=10;

}
int main(){

    int N;  scanf("%d",&N);
    int  arr[N]; for(int i=0;i<N;i++) scanf("%d",&arr[i]); //cin >> arr[i] ;
    int Q,q,p,f,r; scanf("%d",&Q);
    map<int,pair<int,ll> > stored;
    while(Q--){

        scanf("%d",&q);
        if(q==1){
           scanf("%d%d",&p,&f);
           arr[p-1]=f;
        } else if(q==2){
            scanf("%d",&r);
            mult[0]=1;size=1;
            ll ans=1LL;
            for(int i=0;i<N;i+=r){
                ans=(ans*arr[i]);
                if(ans>=MOD)ans%=MOD;
                multiply(arr[i]);
            }
            printf("%d %d\n",mult[size-1],ans);
        }
    }
    return 0;
}
