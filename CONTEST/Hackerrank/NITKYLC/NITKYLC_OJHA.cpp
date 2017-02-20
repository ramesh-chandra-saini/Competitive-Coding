/*
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x);
int main(){

    int K,W,choose;
    read(K);
    vector< set <int> > Data(K);
    vector<int> N(K);
    for(int i=0;i<K;i++){
        read(N.at(i));
        for(int j=0;j<N.at(i);j++){
            read(W);
            Data.at(i).insert(W);
        }
    }
    //Choose one element from every group
    set< pair< int,int> > Heap; Heap.clear();
    for(int i=0;i<K;i++)
        choose= *(Data.at(i).begin()),Data.at(i).erase(Data.at(i).begin()),Heap.insert(make_pair(choose,i));
    int ans=((*Heap.rbegin()).first - (*Heap.begin()).first ), key;
    bool Loop=true;
    while(Loop){

        key= (*(Heap.begin()) ).second,Heap.erase(Heap.begin());
        if(Data.at(key).empty() == true) Loop = false;
        else{
              choose= *(Data.at(key).begin()),Data.at(key).erase(Data.at(key).begin()),Heap.insert(make_pair(choose,key));
              ans=min(ans,((*Heap.rbegin()).first - (*Heap.begin()).first ) );
        }
    }
    printf("%d\n",ans);
    return 0;
}
