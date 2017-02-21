#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int N = 1+rand()%10; cout<<N<<endl;
    for(int i=1;i<=N;i++)
        cout<<rand()%100<<" ";
    cout<<endl;
    set<int> vertices;
    vertices.clear();
    for(ll edges = 0; edges<N;){
        if(vertices.size()==N) // all vertices has connected as forest
            break;
        ll u = 1+rand()%N;
        ll v = 1+rand()%N;
        if(u==v) //self loof
            continue;
        if(vertices.find(u)!=vertices.end() && vertices.find(v)!=vertices.end()) //cycle
            continue;
        cout<<u<<" "<<v<<endl;
        vertices.insert(u);
        vertices.insert(v);
        ++edges;
    }
    vector<bool> visited
    for()


}
