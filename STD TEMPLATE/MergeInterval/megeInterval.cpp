#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void printSet(set<pair<ll,ll> >&ans){
    for(set<pair<ll,ll> >::iterator it = ans.begin();it!=ans.end();++it){
        cout<<(*it).first<<" "<<(*it).second<<" ";
    } cout<<endl;
}
set<pair<ll,ll> > mergeInterval(set<pair<ll,ll> >&mySet){
    set<pair<ll,ll> > ans; ans.clear();
    set<pair<ll,ll> >::iterator it=mySet.begin();
    ans.insert(*it);
    pair<ll,ll> prev=make_pair((*it).first,(*it).second);
    for(++it;it!=mySet.end();++it){
        if((*it).first<=prev.second){
            pair<ll,ll> newPair=make_pair(prev.first,max(prev.second,(*it).second ));
            ans.erase(prev),ans.insert(newPair),prev=newPair;
        }else{
            ans.insert(*it),prev=*it;
        }
    }   // printSet(ans);
    return ans;
}
int main(){
    int t; cin >> t; while(t--){
        ll n; cin >> n;
        set<pair<ll,ll> > mySet;mySet.clear();
        for(ll i=0,x,y;i<n;i++){
            cin >> x >> y;
            mySet.insert(make_pair(x,y));
        } //printSet(mySet);
        mySet=mergeInterval(mySet);
        printSet(mySet);
    } return 0;
}
