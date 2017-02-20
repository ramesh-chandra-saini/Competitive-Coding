#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void print(vector<vector<ll> > &factor,vector<ll>&arr,vector<ll>&leastPrimeDivisorIdx){
        for(ll i=1LL;i<factor.size();i++){
            cout<<arr[i]<<"{";
            for(ll j=max(0LL,leastPrimeDivisorIdx[i]);j<factor[i].size();j++)
                cout<<factor[i][j]<<",";
            if(leastPrimeDivisorIdx[i]>=factor[i].size()) cout<<"1LL,";
                cout<<"}  ";
        }
        cout<<endl;
}
vector<ll> getPrimeFactor(ll N){
    vector<ll> ans; ans.clear(); //cout<<N<<" {";
    if(N==1LL){
        ans.push_back(1LL);
    }else{
        for(ll i=2LL;i*i<=N;i++){
            while(N%i==0LL){
                ans.push_back(i);
                N/=i;
            }
        }
        if(N>1LL){
            ans.push_back(N);
        }
    } //for(ll i=0LL;i<ans.size();i++) cout<<ans[i]<<","; cout<<"}"<<endl;
    return ans;
}
ll getLeastPrimeDivisor(vector<ll>&factorList,ll leastPrimeDivisorId){
    return leastPrimeDivisorId<factorList.size()?factorList[leastPrimeDivisorId]:1LL;
}
ll getMax(ll qs,ll qe,ll ss,ll se,ll index,vector<ll>&segTree){
    if(qs>qe || ss>se || qe<ss || se<qs){
        return INT_MIN;
    }
    if(qs<=ss && se<=qe) {
        return segTree[index];
    }else{
        ll mid = (ss+se)/2LL;
        return max(     getMax(qs,qe,ss,mid,2LL*index+1LL,segTree),
                    getMax(qs,qe,1LL+mid,se,2LL*index+2LL,segTree) );
    }
}
void updateUpward(ll child,vector<ll>&segTree){
    if(child==0LL){
        return; //base case
    }
    if(child%2LL==0LL){
        ll parent = (child-2LL)/2LL;
        segTree[parent]=max(segTree[2LL*parent+1LL],segTree[2LL*parent+2LL]);
        return updateUpward(parent,segTree);
    }else{
        ll parent = (child-1LL)/2LL;
        segTree[parent]=max(segTree[2LL*parent+1LL],segTree[2LL*parent+2LL]);
        return updateUpward(parent,segTree);
    }
}
void update(ll ss,ll se,ll position,ll index,ll value,vector<ll>&segTree,ll &updateIdx){
    if(ss>se){
        return; //base case
    }
    if(ss==position && se==position){
        segTree[index]=value;
        updateIdx=index;
        return;
    }else{
        ll mid=(ss+se)/2LL;
        if(ss<=position && position<=mid){
            return update(ss,(ss+se)/2LL,position,2LL*index+1LL,value,segTree,updateIdx);
        }else{
            return update(mid+1LL,se,position,2LL*index+2LL,value,segTree,updateIdx);
        }
    }
}
void updateHandler(ll N,ll position,ll value,vector<ll>&segTree,vector<ll>&values){
    ll updateIdx=0LL;
    update(1LL,N,position,0LL,value,segTree,updateIdx);
    updateUpward(updateIdx,segTree);
    values[position]=value;
}
void leastUpperBound(vector<ll>&arr,ll low,ll high,ll key,ll &idx){
    if(low>high) return; //base case
    ll mid = (low+high)/2LL;
    if(arr[mid]>=key){
        idx=mid;
        leastUpperBound(arr,low,mid-1LL,key,idx);
    }else{
        leastUpperBound(arr,mid+1LL,high,key,idx);
    }
}
void updateUtil(ll L,ll R,vector<ll>&currNonUnitNode,vector<ll>&leastPrimeDivisorIdx,vector<vector<ll> >&factor,ll N,vector<ll>&segTree,vector<ll>&values){
    ll idx = currNonUnitNode.size();
    leastUpperBound(currNonUnitNode,0LL,currNonUnitNode.size()-1LL,L,idx);
    for(ll i=idx;i<currNonUnitNode.size()&&currNonUnitNode[i]<=R;){
        ll node = currNonUnitNode[i];
        ++leastPrimeDivisorIdx[node];
        ll leastPrimeDivisor=getLeastPrimeDivisor(factor[node],leastPrimeDivisorIdx[node]);
        updateHandler(N,node,leastPrimeDivisor,segTree,values);
        if(leastPrimeDivisor==1LL){
            currNonUnitNode.erase(currNonUnitNode.begin()+i);
        }else{
            i++;
        }
    }
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll N,Q;
        cin >> N >> Q;
        vector<ll> arr(N+1LL);
        for(ll i=1LL;i<=N;i++){
            cin >> arr[i];
        }
        vector<vector<ll> > factor(N+1LL,vector<ll>());
        vector<ll> leastPrimeDivisorIdx(N+1LL,0LL);
        for(ll i=1LL;i<=N;i++){
            factor[i]=getPrimeFactor(arr[i]);
        }
        ll treeSize=20LL*N;//*(1LL+ceil(log2(N)));
        vector<ll> segTree(treeSize,INT_MIN);
        vector<ll> values(N+1LL,INT_MIN);
        vector<ll> currNonUnitNode(N);
        for(int i=0LL;i<N;i++){
            currNonUnitNode[i]=i+1LL;
        }
        for(ll i=1LL;i<=N;i++){
            values[i]=getLeastPrimeDivisor(factor[i],leastPrimeDivisorIdx[i]);
            updateHandler(N,i,values[i],segTree,values);
        }
        //print(factor,arr,leastPrimeDivisorIdx);
        while(Q--){
            ll choice,L,R; cin >> choice >> L >> R;
            if(choice==0LL){
                updateUtil(L,R,currNonUnitNode,leastPrimeDivisorIdx,factor,N,segTree,values);
            }else{
                cout<<getMax(L,R,1LL,N,0LL,segTree)<<endl;
            }
        }
    }  return 0LL;
}
