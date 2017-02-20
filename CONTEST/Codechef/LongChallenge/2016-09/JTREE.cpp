#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef struct Ticket{
    ll city, times, cost;
} ticket;
ll solve(ll numOfTimesUsedTicket,ll times,ll currCity,vector<ticket> &tickets,vector<ll>&tree){
    if(numOfTimesUsedTicket>times) return INT_MAX;
    if(currCity==1) return 0LL;
    ll ans=INT_MAX;
    for(ll i=0;i<tickets.size();i++){
        if(currCity==tickets[i].city){
            //cout<<currCity<<" --> "<<tree[currCity]<<endl;
            ans=min(ans,tickets[i].cost+solve(1,tickets[i].times,tree[currCity],tickets,tree));
        }
    }
    //cout<<currCity<<" --> "<<tree[currCity]<<endl;
    //without buying any ticket
    ans=min(ans,solve(numOfTimesUsedTicket+1,times,tree[currCity],tickets,tree));
    return ans;
}
int main(){
    ll N, M; cin >> N >> M;
    vector<ll> tree(N+1);
    for(ll i=1;i<N;i++){
        ll a,b; cin >> a >> b;
        tree[a]=b;
    }
    vector<ticket> tickets(M);
    for(ll i=0;i<M;i++){
        cin >> tickets[i].city >> tickets[i].times >> tickets[i].cost;
    }
    ll Q; cin >> Q; while(Q--){
        int h; cin >> h;
        cout<<solve(0,0,h,tickets,tree)<<endl;
    } return 0;
}
