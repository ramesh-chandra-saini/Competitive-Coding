#include<bits/stdc++.h>
using namespace std;
#define ll int

#define pc putchar_unlocked
#define gc getchar_unlocked
 /*
#define read(x) scanf("%d",&x)

#define write(x) printf("%d\n",x)
*/
void read(ll &x){
    x=0;
    register char c=gc();
    for(;c<'0' || c>'9';c=gc());
    for(;c>='0' && c<='9';c=gc()){
        x=(x<<3)+(x<<1)+(c-'0');
    }
}
void write(ll x){
    char buffer[35];
    register int i=-1;
    do{
        buffer[++i]='0'+x%10;x/=10;
    } while(x);
    while(i>=0){
        pc(buffer[i]);
        i--;
    }
    pc(' ');
}
void print(vector<vector<ll> > &factor,vector<ll>&arr,vector<ll>&leastPDIdx){
        for(ll i=1;i<factor.size();i++){
            cout<<arr[i]<<"{";
            for(ll j=max(0,leastPDIdx[i]);j<factor[i].size();j++)
                cout<<factor[i][j]<<",";
            if(leastPDIdx[i]>=factor[i].size()) cout<<"1,";
                cout<<"}  ";
        }
        cout<<endl;
}
vector<ll> getPrimeFactor(ll N){
    vector<ll> ans; ans.clear(); //cout<<N<<" {";
    if(N<2){
        ans.push_back(1);
    }else{
        for(ll i=2;i*i<=N;i++){
            if(N%i==0){
                while(N%i==0){
                    ans.push_back(i);
                    N/=i;
                }
            }
        }
        if(N>1){
            ans.push_back(N);
        }
    } //for(ll i=0;i<ans.size();i++) cout<<ans[i]<<","; cout<<"}"<<endl;
    return ans;
}
ll getLPD(vector<ll>&factorList,ll leastPDId){
    return leastPDId<factorList.size()?factorList[leastPDId]:1;
}
ll getMax(ll qs,ll qe,ll ss,ll se,ll index,vector<ll>&segTree){
    if(qs>qe || ss>se || qe<ss || se<qs){
        return INT_MIN;
    }
    if(qs<=ss && se<=qe) {
        return segTree[index];
    }else{
        ll mid = (ss+se)/2;
        return max(     getMax(qs,qe,ss,mid,2*index+1,segTree),
                        getMax(qs,qe,1+mid,se,2*index+2,segTree) );
    }
}
void updateUpward(ll child,vector<ll>&segTree){
    if(child<1){
        return; //base case
    }
    if(child%2==0){
        ll parent = (child-2)/2;
        segTree[parent]=max(segTree[2*parent+1],segTree[2*parent+2]);
        return updateUpward(parent,segTree);
    }else{
        ll parent = (child-1)/2;
        segTree[parent]=max(segTree[2*parent+1],segTree[2*parent+2]);
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
        ll mid=(ss+se)/2;
        if(ss<=position && position<=mid){
            return update(ss,(ss+se)/2,position,2*index+1,value,segTree,updateIdx);
        }else{
            return update(mid+1,se,position,2*index+2,value,segTree,updateIdx);
        }
    }
}
void updateHandler(ll N,ll position,ll value,vector<ll>&segTree,vector<ll>&values){
    ll updateIdx=0;
    update(1,N,position,0,value,segTree,updateIdx);
    updateUpward(updateIdx,segTree);
    values[position]=value;
}
void leastUpperBound(vector<ll>&arr,ll low,ll high,ll key,ll &idx){
    if(low>high) return; //base case
    ll mid = (low+high)/2;
    if(arr[mid]>=key){
        idx=mid;
        leastUpperBound(arr,low,mid-1,key,idx);
    }else{
        leastUpperBound(arr,mid+1,high,key,idx);
    }
}
void updateUtil(ll L,ll R,map<ll,bool>&currNonUnitNode,vector<ll>&leastPDIdx,vector<vector<ll> >&factor,
                ll N,vector<ll>&segTree,vector<ll>&values){
    map<ll,bool>::iterator itBegin = currNonUnitNode.lower_bound(L);
    map<ll,bool>::iterator itEnd = currNonUnitNode.end();
    while(itBegin!=itEnd && itBegin->first<=R){
            ll node = itBegin->first;
            ++leastPDIdx[node];
            ll leastPD = getLPD(factor[node],leastPDIdx[node]);
            updateHandler(N,node,leastPD,segTree,values);
            if(leastPD==1){
                currNonUnitNode.erase(itBegin++);
            }else{
                ++itBegin;
            }
    }
}
int main(){

    clock_t startTime = clock();
    ll t;
    read(t);//scanf("%d",&t);//cin >> t;
    while(t--){
        ll N,Q;
        read(N);read(Q);//scanf("%d%d",&N,&Q);//cin >> N >> Q;
        vector<ll> arr(N+1);
        for(ll i=1;i<=N;i++){
            read(arr[i]);//scanf("%d",&arr[i]);//cin >> arr[i];
        }
        vector<vector<ll> > factor(N+1,vector<ll>());
        vector<ll> leastPDIdx(N+1,-1);
        for(ll i=1;i<=N;i++){
            factor[i]=getPrimeFactor(arr[i]);
        }
        ll treeSize=N*(1+ceil(log2(N)));
        //ll treeSize=10*N;//*(1+ceil(log2(N)));
        vector<ll> segTree(treeSize,INT_MIN);
        vector<ll> values(N+1,INT_MIN);
        map<ll,bool> currNonUnitNode;
        for(int i=0;i<N;i++){
            currNonUnitNode.insert(make_pair(i+1,true));
        }
        updateUtil(1,N,currNonUnitNode,leastPDIdx,factor,N,segTree,values);
        while(Q--){
            ll choice,L,R; read(choice); read(L); read(R);
            if(choice==0){
                updateUtil(L,R,currNonUnitNode,leastPDIdx,factor,N,segTree,values);
            }else{
                write(max(1,getMax(L,R,1,N,0,segTree)));
            }

        }    pc('\n');
    }
    clock_t endTime = clock();
    double duration = (double)(endTime-startTime)/CLOCKS_PER_SEC;
    printf("RUN TIME : %f\n",duration);
    return 0;
}
