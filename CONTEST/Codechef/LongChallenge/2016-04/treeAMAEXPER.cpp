/*
    Author : Ramesh Chandra
    National Institute Of Technology Karnataka Surathkal
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n; // number of nodes
        ll hash[n+1],tree[n+1][2];memset(tree,0,sizeof(tree)); memset(hash,0,sizeof(hash));//storing frequency of all nodes, which will help to know which is leaf node
        tree[1][0] = 1; tree[1][1] = 0;
        for(ll i=0,x,y,w,temp;i<n-1;i++){
            cin >> x >> y >> w; if(x>y) swap(x,y); //child always has higher id to parent
            tree[y][0] = x;tree[y][1] = w;//storing tree into array
            hash[x]++,hash[y]++; //storing frequency into hash
        }
        vector<ll> Leaf,Releaf;//store current leaf nodes
        for(ll i = 2;i<=n;i++){ //skip root node
            if(hash[i] == 1 ) Leaf.push_back(i);//freq == 1 means Leaf node..as simple as u think
        }
        ll DS[n+1][3];memset(DS,0,sizeof(DS));//final Data Structure
        while(1){
                Releaf.clear();
                for(ll i=0,x,y,z,w;i<Leaf.size();i++){
                    y=Leaf[i];x = tree[y][0];z = DS[x][2];
                    if(DS[x][0] == 0){
                        DS[x][0]=1;DS[x][1]=DS[y][1]+tree[y][1]; DS[x][2]=y;
                    }
                    else {
                        if((tree[z][1]+DS[z][1])>(tree[y][1]+DS[y][1])){
                            DS[x][2]=z; DS[x][1]= tree[z][1]+DS[z][1] ;
                        } else{
                            DS[x][2]=y; DS[x][1]=tree[y][1]+DS[y][1] ;
                        }
                    }
                    hash[x]--; hash[y]--;
                    if(hash[x] == 1 && x != 1) Releaf.push_back(x);//consider as leeaf node but don't mess with root
                }
                if(Releaf.size() == 0) break;
                else Leaf=Releaf;
        }
        for(ll i = 1 ; i <= n ; i++)
            cout << DS[i][1]<<endl;
    }
    return 0;
}
