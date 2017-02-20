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
    ll n,m,k; cin >> n >> m >> k;
    map<ll,set<pair<ll,ll> > > myMap; myMap.clear();
    while(k--){
        ll r,c1,c2; myMap[r].insert(make_pair(c1,c2));
    }
    for(map<ll,set<pair<ll,ll> > >::iterator it = myMap.begin();it!=myMap.end();++it)
        myMap[it->first]=mergeInterval(it->second);
    ll ans=n*m;
    for(map<ll,set<pair<ll,ll> > >::iterator it = myMap.begin();it!=myMap.end();++it){
        cout<<it->first<<" --> ";
        for(set<pair<ll,ll> >::iterator sit = it->second.begin();sit!=it->second.end();++sit){
            ans-=((sit->second)-(sit->first)+1);
            cout<<"["<<sit->first<<" "<<sit->second<<"] ";
        } cout<<endl;
    }
    (ans>0)? cout<<ans<<endl:cout<<endl;
    return 0;
}
