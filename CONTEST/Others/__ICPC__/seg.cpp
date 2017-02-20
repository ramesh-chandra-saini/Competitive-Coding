#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int tree[3*MAX]; //a segment tree is nearly twice as large as the array.
int arr[MAX];

void build(int n, int b, int e){

    if (b>e) return;
    else if (b==e){
    tree[n] = arr[b];
    return;
    }

    build ( n*2 , b , (b+e)/2 ); //go to children...child nodes of node n are 2n and 2n+1.

    build (n*2+1, (b+e)/2 + 1 , e );

 //now both child nodes 2n and 2n+1 are built (ie they have done their responsibility of storing the correct information)
 tree[n] = max( tree[n*2] , tree[n*2 + 1] );

}

void update(int n, int b, int e, int idx, int val)
{
 if (b>e || b>idx || e<idx ) return;
 if (b==e) //at leaf node
 {
  tree[n] = val;
  return;
 }

 update( n*2 , b , (b+e)/2 , idx, val );
 update( n*2 + 1 , (b+e)/2 + 1 , e , idx, val );

 //now some change might have been made in either of the child nodes.

 tree[n] = max( tree[n*2] , tree[n*2 + 1] );

}
int query(){


}
int main(){

    int n;cin >> n;
        for(int i=0;i<n;i++) cin >> arr[i];
        update(1,)
}
