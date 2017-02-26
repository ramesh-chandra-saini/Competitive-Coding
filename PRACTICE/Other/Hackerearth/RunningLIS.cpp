/*
  RAMESH CHANDRA
*/
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked

char buffer[35];
int update( int *seg_tree,int idx,int value,int ss,int se,int node){
    if(ss>se)
        return 0;
    if(ss == se)
        return seg_tree[node]=value;
    int mid = (ss+se)>>1,next_node=(node<<1);
    if(ss<=idx and idx<=mid)
        update(seg_tree,idx,value,ss,mid,next_node);
    else
        update(seg_tree,idx,value,mid+1,se,next_node+1);
    return seg_tree[node] = max(seg_tree[next_node],seg_tree[next_node+1]);
}
int query(int *seg_tree,int qs,int qe,int ss,int se,int node){
    if(ss>se || qs>qe || se<qs || qe<ss)
        return 0;
    if(qs<=ss &&  se<=qe)
        return seg_tree[node];
    int mid = (ss+se)>>1,next_node = (node<<1);
    return max( query(seg_tree,qs,qe,ss,mid,next_node), query(seg_tree,qs,qe,mid+1,se,next_node+1));
}
void read(int &x){

    register int c= gc();
    for(;c<48 || c>57;c=gc());
    for(x=0;c>=48 && c<=57;c=gc())
        x = (x<<1)+(x<<3)+(c-48);
}
void write(int x,register int i=0){
    do buffer[i++]=x%10+48,x/=10;
    while(x);
    while(--i>=0)
        pc(buffer[i]); pc('\n');
}
int main(){
    //freopen("in.txt","r",stdin);
    int N,Q,maxN,x,lis_len;
    read(N),read(Q);
    int vec[N];
    for(int i=0;i<N;i++)
        read(vec[i]),maxN=max(maxN,vec[i]);
    pair<int,int> q[Q];
    for(int i=0;i<Q;i++){
        read(q[i].first);
        if(q[i].first==1)
            read(q[i].second),maxN=max(maxN,q[i].second);
    }
    vector<int>arr,lis;
    map<int,int>  dp[maxN+1];
    int *seg_arr=(int*)malloc(sizeof(int)*(maxN+1));
    int *seg_tree=(int*)malloc(sizeof(int)*(4*maxN+1));
    for(int i=0;i<N;i++){
        x=vec[i];arr.push_back(x); //insert x
        lis_len = query(seg_tree,1,x-1,1,maxN,1)+1;//get lis len
        lis.push_back(lis_len); //store length due to x
        ++dp[x][-lis_len]; //insert new length
        (lis_len=seg_arr[x]),seg_arr[x]= -dp[x].begin()->first; //max len
        if(lis_len!=seg_arr[x])update(seg_tree,x,seg_arr[x],1,maxN,1);//update seg tree
    }
    for(int i=0;i<Q;i++){
        if(q[i].first==1){
            x=q[i].second;arr.push_back(x);//insert x
            lis_len = query(seg_tree,1,x-1,1,maxN,1)+1; //get lis len
            lis.push_back(lis_len);//store length due to x
            ++dp[x][-lis_len]; //insert new length
            (lis_len=seg_arr[x]),seg_arr[x]= -dp[x].begin()->first; //max len
            if(lis_len!=seg_arr[x])update(seg_tree,x,seg_arr[x],1,maxN,1);//update seg tree
        }else{
            x = arr.back();arr.pop_back();//get last element
            lis_len = lis.back();lis.pop_back();//get length due to this element
            (dp[x][-lis_len]==1)?dp[x].erase(-lis_len):--dp[x][-lis_len]; //erase that length from dp[x]
            (lis_len=seg_arr[x]),seg_arr[x]= -dp[x].begin()->first; //max len
            if(lis_len!=seg_arr[x])update(seg_tree,x,seg_arr[x],1,maxN,1);//update seg tree
        }
        printf("%d\n",seg_tree[1]);
        //write(seg_tree[1]);//final ans to judge
    }
    return 0;
}
