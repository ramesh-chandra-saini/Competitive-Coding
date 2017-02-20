#include<bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define ll long long int
ll _getSumFromBIT(ll BIT[],ll index){

    ll sum=0;
    index=index+1;
    while(index>0){
        sum+=BIT[index];
        index=index-( index & (-index));

    }
    return sum;
}
void _updateBIt(ll BIT[],ll size,ll index,ll value){

    index=index+1;
    if(index<=0) return ;
    while(index<=size){

        BIT[index]+=value;
         index=index+( index & (-index));
    }
    return;
}
void construct(ll arr[],ll size,ll BIT[]){

     for(ll i=0;i<=size;i++) BIT[i]=0;

     for(ll i=0;i<size;i++){

        _updateBIt(BIT,size,i,arr[i]);
     }
     return ;
}
 int main(){


    ll T,N,H,L,R,D;
    ll ans=0,check=0;
    ll spy=-1;
    cin>>T;

    while(T--){

        cin>>N; cin>>H;
        //read(N);read(H);

        //ll *arr=(ll*)malloc(N*sizeof(ll));
        ll arr[N],BIT[N+1];
        for(ll i=0;i<N;i++) arr[i]=0;

       // ll *BIT=
       construct(arr,N,BIT);

        for(ll i=0;i<N;i++){

            cin>>L>>R; //read(L);read(R);
            _updateBIt(BIT,N,L,1);
            _updateBIt(BIT,N,R+1,-1);
        }

        for(ll i=0;i<N;i++){

            arr[i]=_getSumFromBIT(BIT,i)-_getSumFromBIT(BIT,i-1);
        }

      }
    return 0;
}
