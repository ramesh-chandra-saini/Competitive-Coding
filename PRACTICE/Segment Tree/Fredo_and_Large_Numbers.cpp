/*
    RAMESH CHANDRA, FEB 6,2017
    NITK SURATHKAL
    DS : Segment Tree, STL MAP, STL VECTOR
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> tree(10000007,INT_MAX);
ll build(ll ss,ll se,ll idx,vector<ll>&freq){
    if(ss>se) //invalid segment
        return INT_MAX;
    if(ss==se) //correct place to store frequency
        return tree[idx] = freq[ss];
    ll mid = (ss+se)/2;//split into two parts
    return tree[idx] = min(  build(ss,mid,2*idx+1,freq), build(mid+1,se,2*idx+2,freq));
}
ll query(ll ss,ll se,ll qs,ll qe,ll idx){
    if(ss>se || qs>qe || ss>qe || qs>se) //invalid segment
        return INT_MAX;
    if(qs<=ss && se<=qe) //valid sub-segment
        return tree[idx];
    ll mid = (ss+se)/2;//split into two parts
    return min(query(ss,mid,qs,qe,2*idx+1),query(mid+1,se,qs,qe,2*idx+2));
}
int main(){
    ll N,maxFreq=0; scanf("%lld",&N);
    vector<ll> arr(N);// read arr
    map<ll,ll> mp;//store number's frequency
    map<ll,ll> idx; //first occurence of each number
    for(ll i=0;i<N;i++){
        scanf("%lld",&arr[i]);
        if(mp.find(arr[i])==mp.end()) // to check if this first time occure or repeated
            idx[arr[i]]=i;
        ++mp[arr[i]],maxFreq=max(maxFreq,mp[arr[i]]);//update freq and max frequency
    }
    map<ll,ll> rev_mp;//map ==> frequency vs first occurence index
    for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();++it){
        if(rev_mp.find(it->second)==rev_mp.end())
            rev_mp[it->second] = idx[it->first];
        else
            rev_mp[it->second] = min(rev_mp[it->second],idx[it->first]);
     }
    ll Q; scanf("%lld",&Q);
    vector<ll> freq(maxFreq+1,INT_MAX); //reflect map into vector
    for(map<ll,ll>::iterator it=rev_mp.begin();it!=rev_mp.end();++it)
        freq[it->first] = it->second;
    build(0,maxFreq,0,freq); //build segment tree
    while(Q--){
        ll type,f,ans=0; scanf("%lld",&type,&f);
        if(type==0){
            if(f<=maxFreq)//find min index  for freq>=f
                ans = query(0,maxFreq,f,maxFreq,0), ans = (ans!=INT_MAX)? arr[ans]:0;
        }else{
            if(f<=maxFreq && freq[f]!=INT_MAX) //return ans for freq=f directly from freq[]
                ans = arr[freq[f]];
        }
        printf("%lld\n",ans);//print ans to judge
    }
    return(0);
}
