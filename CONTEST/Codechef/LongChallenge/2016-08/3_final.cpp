#include<bits/stdc++.h>
using namespace std;
int getWeight(int weight[],int u,int v,int n){
    if(min(u,v)==1 && max(u,v)==n) return weight[n];
    return weight[min(u,v)];
}
int getNext(int curr,int n) {  return (curr==n)?1:(curr+1);}
int getPrev(int curr,int n) {  return (curr==1)?n:(curr-1);}
int getForwardCost(int weight[],int start,int end,int n){
    int forwardCost=0;
    for(int curr=start,next;curr!=end;curr=next){
        next=getNext(curr,n);
        forwardCost+=getWeight(weight,curr,next,n);
    }
    return forwardCost;
}
int getBackwardCost(int weight[],int start,int end,int n){
    int backwardCost=0;
    for(int curr=start,prev;curr!=end;curr=prev){
        prev=getPrev(curr,n);
        backwardCost+=getWeight(weight,curr,prev,n);
    }
    return backwardCost;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int weight[n+1];
        for(int i=1;i<=n;i++)
            cin >> weight[i];
        int start,end;
        cin >> start >> end;

        int ans=INT_MAX;
        /*ans=min(ans,getForwardCost(weight,start,end,n));
        ans=min(ans,getBackwardCost(weight,start,end,n));
        for(int curr=start,next;curr!=end;curr=next){
            next=getNext(curr,n);
            ans=min(ans,getForwardCost(weight,start,next,n)+getBackwardCost(weight,next,start,n)+getBackwardCost(weight,start,end,n));
        }
        for(int curr=start,prev;curr!=end;curr=prev){
            prev=getPrev(curr,n);
            ans=min(ans,getBackwardCost(weight,start,prev,n)+getForwardCost(weight,prev,start,n)+getForwardCost(weight,start,end,n));
        }
        for(int curr=end,next;curr!=start;curr=next){
            next=getNext(curr,n);
            ans=min(ans,getForwardCost(weight,start,end,n)+getForwardCost(weight,end,next,n)+getBackwardCost(weight,next,end,n));
        }
        for(int curr=end,prev;curr!=start;curr=prev){
            prev=getPrev(curr,n);
            ans=min(ans,getBackwardCost(weight,start,end,n)+getBackwardCost(weight,end,prev,n)+getForwardCost(weight,prev,end,n));
        }
        ans=min(ans,getForwardCost(weight,start,end,n)+getForwardCost(weight,end,start,n)+getForwardCost(weight,start,end,n));
        ans=min(ans,getBackwardCost(weight,start,end,n)+getBackwardCost(weight,end,start,n)+getBackwardCost(weight,start,end,n));

        cout<<ans<<endl;

        */
        int FC=0;
        for(int curr=start,next;curr!=end;curr=next){
            next=getNext(curr,n);
            FC=FC+getWeight(weight,curr,next,n);
        }
        ans=getForwardCost(weight,start,end,n);
        int BC=0;
        for(int curr=start,prev;curr!=end;curr=prev){
            prev=getPrev(curr,n);
            BC=BC+getWeight(weight,curr,prev,n);
        }
        ans=min(ans,BC);

        for(int curr=start,next,fc=0;curr!=end;curr=next){
            next=getNext(curr,n);
            fc=fc+getWeight(weight,curr,next,n);
            ans=min(ans,2*fc+BC);
        }

        for(int curr=start,prev,bc=0;curr!=end;curr=prev){
            prev=getPrev(curr,n);
            bc=bc+getWeight(weight,curr,prev,n);
            ans=min(ans,2*bc+FC);
        }

        for(int curr=end,next,fc=0;curr!=start;curr=next){
            next=getNext(curr,n);
            fc=fc+getWeight(weight,curr,next,n);
            ans=min(ans,2*fc+FC);
        }

        for(int curr=end,prev,bc=0;curr!=start;curr=prev){
            prev=getPrev(curr,n);
            bc=bc+getWeight(weight,curr,prev,n);
            ans=min(ans,2*bc+BC);
        }

        ans=min(ans,FC+BC+FC);
        ans=min(ans,BC+FC+BC);

        cout<<ans<<endl;



    } return 0;
}
