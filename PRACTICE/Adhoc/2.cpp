#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    set<pair<int,int > > s;
    s.insert(make_pair(1,5));
    s.insert(make_pair(1,2));
    for(set<pair<int,int> >  :: iterator it =s.begin();it!=s.end();++it)
        cout<<it->first<<" "<<it->second<<endl;
/*
    vector<int> A(5,0);
    A.insert(A.begin()+0,-15);
    A.insert(A.begin()+2,58);
    A.push_back(15);
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" "; cout<<endl;*/
    ll n,w;
scanf("%lld%lld",&n,&w);
    ll arr[(2*n)];
    for(int i=0;i<2*n;i++)
        scanf("%lld",&arr[i]);
    sort(arr,arr+2*n);
    double g = double(arr[0])/(double)1.0, b=(double)(arr[n])/(double)1.0;
    g=min(g,b/2.0);
    g=min(g,( (double)w/(3.0* (double) n))); b=2.0*g;
    double ans=3.0*(double)n*g;
    printf("%.9f\n",ans);
    return 0;
}
