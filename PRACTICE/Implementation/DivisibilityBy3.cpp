#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll> > segTree(4*100000+5,vector<ll>(10,0LL));
        vector<ll> lazyTree(4*100000+5,0LL);
void build(ll ss,ll se,ll node,vector<ll>&arr){
    if(ss>se) return ;
    if(ss==se){
        segTree[node][0] = 1LL ;
        return ;
    }
    int mid = (ss+se)/2;
    build(ss,mid,2*node+1,arr);
    build(mid+1,se,2*node+2,arr);
    for(ll i=0;i<10;i++)
        segTree[node][i]=(segTree[2*node+1][i]+segTree[2*node+2][i]);
}
void removeLazyNess(ll ss,ll se,ll node){
    if(lazyTree[node]!=0){
        vector<ll> temp(10);
        for(int i=0;i<n;i++){
            temp[i] = segTree[node][(i+lazyTree[node])%10];
        }
        segTree[node]=temp;
        if(ss!=se){
            lazyTree[2*node+1]+=lazyTree[node];
            lazyTree[2*node+2]+=lazyTree[node];
        }
        lazyTree[node]=0;
    }
}
void update(ll ss,ll se,ll qs,ll qe, ll node){
    removeLazyNess(ss,se,node);
    if(ss>se||qs>qe||se<qs || qe<ss)
        return;
    if(qs<=ss && se<=qe){
        lazyTree[node]++;
        removeLazyNess(ss,se,node);
        return;
    }
    int mid = (ss+se)/2;
    update(ss,mid,qs,qe,2*node+1,value);
    update(mid+1,se,qs,qe,2*node+2,value);
    for(ll i=0;i<10;i++)
        segTree[node][i]=(segTree[2*node+1][i]+segTree[2*node+2][i]);
}
ll query(ll ss,ll se,ll qs, ll qe,ll node){
    removeLazyNess(ss,se,node);
    if(ss>se||qs>qe||se<qs || qe<ss)
        return 0LL;
    if(qs<=ss && se<=qe){
        ll sum =0;
        for(int i=0;i<10;i++)
            sum+=i*segTree[node][i];
        return sum;
    }
    ll mid = (ss+se)/2;
    return query(ss,mid,qs,qe,2*node+1)+query(mid+1,se,qs,qe,2*node+2);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> arr(n+1,0);
    build(1LL,n,0LL,arr);// printTree();
    ll q; cin >> q;while(q--){
        ll type,l,r; cin >> type >> l >> r ;
        if(type==1){
            update(1LL,n,l,r,0LL,1);
        }else{
            cout<<query(1LL,n,l,r,0LL)<<endl;
        }
    } return 0;
}
