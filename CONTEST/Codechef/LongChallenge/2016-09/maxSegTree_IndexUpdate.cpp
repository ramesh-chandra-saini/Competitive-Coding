#include<bits/stdc++.h>
#define ll long long int
#define INT_MIN -1
using namespace std;
ll updateIdx,mxIndex;
ll getMax(ll ss,ll se,ll qs,ll qe,ll index,ll segTree[]){
    if(qe<ss||se<qs||ss>se) return INT_MIN;
    if(qs<=ss && se<=qe) return segTree[index];
    return max(getMax(ss,(ss+se)/2,qs,qe,2*index+1,segTree),getMax((ss+se)/2+1,se,qs,se,2*index+2,segTree));
}
void update(ll ss, ll se, ll position,ll value,ll index,ll segTree[]){
    if(ss>se) return;
    if(ss==position && se==position) {
        segTree[index]=value; mxIndex = max(mxIndex,index);
        updateIdx=index;
        cout<<"update at position["<<position<<"] Index "<<index<<endl;
        return;
    }
    ll mid=(ss+se)/2;
    if(ss<=position && position<=mid){
        update(ss,mid,position,value,2*index+1,segTree); //left segment
    }else{
        update(mid+1,se,position,value,2*index+2,segTree); //right segment
    }
}
void updateUpward(ll child,ll segTree[]){
    if(child==0) return;
    if(child%2==0){//right child
        ll parent=(child-2)/2; segTree[parent]=max(segTree[2*parent+1],segTree[2*parent+2]);
        cout<<parent<<", ";
        updateUpward(parent,segTree);
    }else{//left child
        ll parent=(child-1)/2;   segTree[parent]=max(segTree[2*parent+1],segTree[2*parent+2]);
        cout<<parent<<", ";
        updateUpward(parent,segTree);
    }
}
void updateHandler(ll N,ll position,ll value,ll segTree[],ll values[]){
        updateIdx=0; ll temp= values[position];
        update(1,N,position,value,0,segTree);
        cout<<"UpdateUpward ";
        updateUpward(updateIdx,segTree); cout<<endl;
        values[position]=value;
        cout<<"updated["<<position<<"] { "<<temp<<" -> ";
        values[position]=value;   cout<<values[position]<<" }"<<endl;
        cout<<"VALUES {";for(int i=1;i<=N;i++) cout<<values[i]<<","; cout<<"}"<<endl;
        cout<<"VALUES {";for(int i=0;i<=mxIndex;i++) cout<<segTree[i]<<" "; cout<<"}"<<endl;
}
int main(){
    ll N; cin >> N;
    ll arr[N+1]; for(ll i=1;i<=N;i++) cin >> arr[i];
    ll segSize=N*(1+ceil(log2(N)))*10;
    ll segTree[segSize]; for(ll i=0;i<segSize;i++) segTree[i]=INT_MIN;
    ll values[  1+N]; for(ll i=1;i<=N;i++) values[i]=INT_MIN;
    mxIndex=0;
    for(ll i=1;i<=N;i++){
        updateHandler(N,i,arr[i],segTree,values);
    }
    ll Q; cin >> Q;
    while(Q--){
        ll choice; cin >> choice ;
        if(choice==0){  //update
            ll position,value;cin >> position >> value;
            updateHandler(N,position,value,segTree,values);
        }else{   //getMax
            ll L,R;cin >> L >> R;
            ll mx=INT_MIN;
            for(ll i=L;i<=R;i++)
                mx=max(mx,values[i]);
            cout<<getMax(1,N,L,R,0,segTree)<<" <==> "<<mx<<endl;
        }
    } return 0;
}
