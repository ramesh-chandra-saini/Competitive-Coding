#include<bits/stdc++.h>
using namespace std;
int getRoot(int arr[],int i){
    if(arr[i]==i) // base case
        return i;
    return getRoot(arr,arr[i]);
}
int main(){
    int N,Q; cin >>  N >> Q;
    int arr[N+1];
    int size[N+1];
    for(int i=1;i<=N;i++)
        arr[i]=i, size[i]=1;
     while(Q--){
        char type; cin >> type;
        if(type == 'Q'){
            int id; cin >> id;
            cout<<size[getRoot(arr,id)]<<endl;
        }else{
            int A,B;  cin >> A >> B ;
            int rootA = getRoot(arr,A);
            int rootB = getRoot(arr,B);
            if(rootA == rootB)
                continue;
            if(size[rootA]<size[rootB]){
                arr[rootA] = arr[rootB];
                size[rootB]+=size[rootA];
            }else{
                arr[rootB] = arr[rootA];
                size[rootA]+=size[rootB];
            }
        }
     }
     return 0;
}
