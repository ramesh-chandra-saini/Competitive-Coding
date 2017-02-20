#include<bits/stdc++.h>
using  namespace std;

#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)

int arr[50000];
int tree[50000*2+1];
void build_tree(int node,int st,int end){

    if(st>end) return;

    if(st==end){

        tree[st]=arr[st];
        return;
    }

    build_tree(2*node,st,(st+end)/2);
    build_tree(2*node+1,1+(st+end)/2,end);

    tree[node]=max(tree[2*node],tree[2*node+1]);
}
int query_tree(int node,int st,int end,int b,int e){

    if(st>end || end<b || st>e) return INT_MIN;

    if(st>=b && e<=end) return tree[node];

    int left=query_tree(2*node,st,(st+end)/2,b,e);
    int right=query_tree(2*node+1,1+(st+end)/2,end,b,e);
    return max(left,right);
}
int main(){

    int n;
    read(n);


    for(int i=0;i<n;i++) read(arr[i]);

    build_tree(1,0,n-1);
     int m;

     read(m);

     while(m--){

        int L,R;

        read(L); read(R);

        write(query_tree(1,0,n-1,L-1,R-1));
     }

    return 0;
}
