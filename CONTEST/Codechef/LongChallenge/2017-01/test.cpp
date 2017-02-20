#include<bits/stdc++.h>
using namespace std;
#define N 3
int main(){
    srand(time(NULL));
    int n = 2+rand()%N;
    int e = 1+rand()%(n*(n-1));
    set<pair<int,int> > edges;
    cout<<n<<" "<<e<<endl;
    int ct = 0;
    while(ct<e){

        int u = 1+rand()%n;
        int v = 1+rand()%n;
        //printf("%d %d\n",u,v);
        if(u!=v && edges.find(make_pair(u,v))==edges.end()){
            ct++;
            edges.insert(make_pair(u,v));
            printf("%d %d\n",u,v);
        }
    }
    return 0;
}
