#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > &factor,int arr[],vector<int>&leastPrimeDivisorId){
        for(int i=1;i<factor.size();i++){
            cout<<arr[i]<<"{";
            for(int j=max(0,leastPrimeDivisorId[i]);j<factor[i].size();j++)
                cout<<factor[i][j]<<",";
            if(leastPrimeDivisorId[i]>=factor[i].size()) cout<<"1,";
                cout<<"}  ";
        }
        cout<<endl;
}
void printSeg(int N,int mxIndex,int LPD[],int tree[]){
        for(int i=1;i<=N;i++) cout<<LPD[i]<<" ";cout<<endl;
        for(int i=0;i<=mxIndex;i++) cout<<tree[i]<<" "; cout<<endl;
}
int tree[1000000];
int LPD [1000000];
int startPointId;
int mxIndex=0;
int updateIdx=0;
vector<int> getPrimeFactor(int N);
void getLowestUpperBound(vector<int>&currentNonUnit,int low,int high,int key);
void update(int l,int r, int position,int index,int value,int tree[],int N);
int getMax(int l,int r,int L,int R,int index,int tree[]);
void Update(int L, int R,int N, vector<int>&leastPrimeDivisorId,vector<int> &currentNonUnit,vector<vector<int> >&factor,int tree[]);
void print(vector<vector<int> > &factor,int arr[],vector<int>&leastPrimeDivisorId);
void updateUpward(int child,int segTree[]);
vector<int> getPrimeFactor(int N){
    vector<int> factors; factors.clear();
    if(N==1) factors.push_back(1);
    else{
        for(int i=2;i*i<=N;i++){
            if(N%i==0){
                while(N%i==0){
                    factors.push_back(i);
                    N/=i;
                }
            }
        }
        if(N>1) factors.push_back(N);
    }
    return factors;
}
int getMax(int l,int r,int L,int R,int index,int tree[]){
    //cout<<"["<<l<<","<<r<<"] :: ["<<L<<" "<<R<<"]"<<endl;
    if(R<l || r<L || l>r) return INT_MIN;
    if(L<=l && r<=R) return tree[index];
    int mid=(l+r)/2;
    return max(getMax(l,mid,L,R,2*index+1,tree),getMax(mid+1,r,L,R,2*index+2,tree));
}
void getLowestUpperBound(vector<int>&currentNonUnit,int low,int high,int key){
    if(low>high) return;
    int mid=(low+high)/2;
    if(currentNonUnit[mid]>=key){
        startPointId=mid;
        getLowestUpperBound(currentNonUnit,low,mid-1,key);
    } else{
        getLowestUpperBound(currentNonUnit,mid+1,high,key);
    }
}
void Update(int L, int R,int N, vector<int>&leastPrimeDivisorId,vector<int> &currentNonUnit,vector<vector<int> >&factor,int tree[],int LPD[],int arr[]){
    startPointId = currentNonUnit.size();
    getLowestUpperBound(currentNonUnit,0,currentNonUnit.size()-1,L);
    for(int i=0;i<currentNonUnit.size();i++) cout<<currentNonUnit[i]<<" "; cout<<endl;
    cout<<"startPointId["<<L<<"]:"<<startPointId<<endl;
    for(int i=startPointId;i<currentNonUnit.size() && currentNonUnit[i]<=R;){
        int nodeId=currentNonUnit[i];
        ++leastPrimeDivisorId[nodeId];
        if(leastPrimeDivisorId[nodeId]>=factor[nodeId].size()){
            LPD[nodeId]=1; updateIdx=0;
            update(1,N,nodeId,0,LPD[nodeId],tree,N);
            updateUpward(updateIdx,tree);
            currentNonUnit.erase(currentNonUnit.begin()+i);
        }else{
            LPD[nodeId]=factor[nodeId][leastPrimeDivisorId[nodeId]];
            updateIdx=0;
            update(1,N,nodeId,0,LPD[nodeId],tree,N);
            updateUpward(updateIdx,tree);
            i++;
        }
        printSeg(N,mxIndex,LPD,tree);
        print(factor,arr,leastPrimeDivisorId);
    }
}
void updateUpward(int child,int segTree[]){
    if(child==0) return;
    if(child%2==0){//right child
        int parent=(child-2)/2; segTree[parent]=max(segTree[2*parent+1],segTree[2*parent+2]);
        cout<<parent<<", ";
        updateUpward(parent,segTree);
    }else{//left child
        int parent=(child-1)/2;   segTree[parent]=max(segTree[2*parent+1],segTree[2*parent+2]);
        cout<<parent<<", ";
        updateUpward(parent,segTree);
    }
}
void update(int l,int r, int position,int index,int value,int tree[],int N){
    mxIndex=max(mxIndex,index);
    if(l>r) return ;
    if(l==position && r==position){
        tree[index]=value;
        updateIdx=index;
        return ;
    }
    int mid=(l+r)/2;
    if(l<=position && position<=mid){
        update(l,mid,position,2*index+1,value,tree,N);
    }else{
        update(mid+1,r,position,index,value,tree,N);
    }
    return;
}
int main(){
    int t; cin >> t; while(t--){
        int N,Q; cin >> N >> Q ;
        int arr[N+1]; for(int i=1;i<=N;i++) cin >> arr[i];
        vector<vector<int> >factor(N+1,vector<int>());
        vector<int> leastPrimeDivisorId(N+1,0);
        vector<int> currentNonUnit(N); for(int i=0;i<N;i++) currentNonUnit[i]=i+1;
        for(int i=1;i<=N;i++)
            factor[i]=getPrimeFactor(arr[i]);
        print(factor,arr,leastPrimeDivisorId);
        for(int i=1;i<=N;i++){
            LPD[i]=factor[i][0];
            updateIdx=0;
            update(1,N,i,0,LPD[i],tree,N);
            updateUpward(updateIdx,tree);
            printSeg(N,mxIndex,LPD,tree);
        }
        printSeg(N,mxIndex,LPD,tree);
        while(Q--){
            int choice,L,R; cin >> choice >> L >> R;
            if(choice==0){
                Update(L,R,N,leastPrimeDivisorId,currentNonUnit,factor,tree,LPD,arr);

            }else{
                cout<<"{";for(int i=L;i<=R;i++) cout<<LPD[i]<<","; cout<<"}"<<endl;
                cout<<getMax(1,N,L,R,0,tree)<<endl;
            }
        }
    } return 0;
}
