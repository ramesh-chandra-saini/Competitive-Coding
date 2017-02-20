#include<bits/stdc++.h>
using namespace std;
#define INT_MIN -1
int query(int segTree[],int L,int R,int l,int r, int index){
    if(L>R || l>r || R<l || r<L) return INT_MIN;
    if(L<=l && r<=R) return segTree[index];
    return max(query(segTree,L,R,l,(l+r)/2,2*index+1),query(segTree,L,R,1+(l+r)/2,r,2*index+2));
}
int build(int segTree[],int index,int L,int R,int arr[]){
    if(L>R) return INT_MIN;
    if(L==R)return segTree[index]=arr[L];
    return segTree[index]=max(build(segTree,2*index+1,L,(L+R)/2,arr),build(segTree,2*index+2,(L+R)/2+1,R,arr));
}
int main(){
    int n; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    int segSize=n*ceil(log2(n));
    int segTree[segSize+1];
    build(segTree,0,0,n-1,arr); //build(segTree,index,L,R,arr);for(int i=0;i<segSize;i++) cout<<segTree[i]<<" "; cout<<endl;
    int Q; cin >> Q;
    while(Q--){
        int L,R; cin >> L >> R;
        cout<<query(segTree,0,)
    }
    return 0;

}
