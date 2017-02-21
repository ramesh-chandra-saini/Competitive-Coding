/*
    Author : Ramesh Chandra
    http://ramesh-chandra.strikingly.com/
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >segTree(4*100000+5,vector<int>(2,0));
       vector<int> lazyTree(4*100000+5,0);

void updateParent(int node,int n=2){
    for(int i=0;i<n;i++)//send sum of child values to parent
        segTree[node][i]=(segTree[2*node+1][i]+segTree[2*node+2][i]);
}
void build(int ss, int se,int node){
    if(ss>se)
        return;
    if(ss==se){//intially all leaf node have tail
        segTree[node][0]=1;
        return ;
    }
    int mid = (ss+se)/2;
    build(ss,mid,2*node+1);
    build(mid+1,se,2*node+2);
    updateParent(node);
}
void flipNode(int node){
    if(lazyTree[node]%2){ //flip node
        swap(segTree[node][0],segTree[node][1]);
    }
}
void updateLazyNode(int ss,int se,int node){
    if(lazyTree[node]!=0){//update current lazy node
        flipNode(node);
        if(ss!=se){//transfer lazyness to child
            lazyTree[2*node+1]+=lazyTree[node];
            lazyTree[2*node+2]+=lazyTree[node];
        }
        lazyTree[node]=0;//make this node as active(free from lazyness)..: D
    }
}
void update(int ss,int se,int qs,int qe,int node){

    updateLazyNode(ss,se,node);//update this node if it is lazy

    if(ss>se || qs>qe || se<qs ||qe<ss)//out of range
        return;
    if(qs<=ss && se<=qe){ //inside the query segment
        lazyTree[node]++;//make this lazy node
        updateLazyNode(ss,se,node); //transfer laziness to child;
        return;
    }
    int mid = (ss+se)/2;
    update(ss,mid,qs,qe,2*node+1);
    update(mid+1,se,qs,qe,2*node+2);
    updateParent(node);
}
int query(int ss,int se,int qs,int qe,int node){

    updateLazyNode(ss,se,node);//update this node if it is lazy

    if(ss>se || qs>qe || se<qs ||qe<ss)
        return 0;
    if(qs<=ss && se<=qe)
        return segTree[node][1];//return number of heads
    int mid = (ss+se)/2;
    return query(ss,mid,qs,qe,2*node+1)+query(mid+1,se,qs,qe,2*node+2);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    build(1,n,0);
    while(q--){
        int type,l,r; cin >> type >> l >> r;l++,r++;
        if(type==0)
            update(1,n,l,r,0);
        else
            cout<<query(1,n,l,r,0)<<endl;
    } return 0;
}
