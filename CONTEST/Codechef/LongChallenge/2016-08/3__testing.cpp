#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll getWeight(ll weight[],ll u,ll v,ll n){
    if( (u==1&&v==n) || (u==n&&v==1)) return weight[n];
    return weight[min(u,v)];
}
ll getNext(ll curr,ll n) {  return (curr==n)?1:(curr+1);}
ll getPrev(ll curr,ll n) {  return (curr==1)?n:(curr-1);}
ll MAX=pow(10LL,18);
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll weight[n+1];
        for(ll i=1;i<=n;i++)
            cin >> weight[i];
        ll start,end;
        cin >> start >> end;

        ll ans=MAX;

        ll FC=0;
        for(ll curr=start,next;curr!=end;curr=next){
            next=getNext(curr,n);
            FC=FC+getWeight(weight,curr,next,n);
        }
        ans=min(ans,FC);
        ll BC=0;
        for(ll curr=start,prev;curr!=end;curr=prev){
            prev=getPrev(curr,n);
            BC=BC+getWeight(weight,curr,prev,n);
        }
        ans=min(ans,BC);

        for(ll curr=start,next,fc=0;curr!=end;curr=next){
            next=getNext(curr,n);
            fc=fc+getWeight(weight,curr,next,n);
            ans=min(ans,2*fc+BC);
        }

        for(ll curr=start,prev,bc=0;curr!=end;curr=prev){
            prev=getPrev(curr,n);
            bc=bc+getWeight(weight,curr,prev,n);
            ans=min(ans,2*bc+FC);
        }

        for(ll curr=end,next,fc=0;curr!=start;curr=next){
            next=getNext(curr,n);
            fc=fc+getWeight(weight,curr,next,n);
            ans=min(ans,2*fc+FC);
        }

        for(ll curr=end,prev,bc=0;curr!=start;curr=prev){
            prev=getPrev(curr,n);
            bc=bc+getWeight(weight,curr,prev,n);
            ans=min(ans,2*bc+BC);
        }



        ans=min(ans,FC+BC+FC);
        ans=min(ans,BC+FC+BC);
        for(ll curr=start,next;curr!=end;curr=next){


        }


        cout<<ans<<endl;



    } return 0;
}
