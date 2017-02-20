#include<bits/stdc++.h>
using namespace std;
vector<int> getPrimeFactor(int N){
    vector<int> factors; factors.clear();
    if(N==1) factors.push_back(1);
    else{
        for(int i=2;i*i<=N;i++){
            if(N%i==0)
                while(N%i==0)
                    factors.push_back(i), N/=i;
        }
        if(N>1){
            factors.push_back(N);
        }
    }
    return factors;
}
int getLeastPrimeDivisor(vector<int> &N,int leastPrimeDivisorId){
    int ans=1;
    if(leastPrimeDivisorId<N.size())
        ans=N[leastPrimeDivisorId];
    return ans;
}
void Update(int L, int R,vector<int>&leastPrimeDivisorId){
    leastPrimeDivisorId[L]+=1;
    leastPrimeDivisorId[R+1]-=1;
}
int Get(int L, int R, vector<vector<int> >&factor,vector<int>&leastPrimeDivisorId){
    int result=1;
    vector<int> currLeastPrimeDivisorId=leastPrimeDivisorId;
    for(int i=1;i<=R;i++)
        currLeastPrimeDivisorId[i]+=currLeastPrimeDivisorId[i-1];
    for(int i=L;i<=R;i++)
        result=max(result,getLeastPrimeDivisor(factor[i],currLeastPrimeDivisorId[i]));
    return result;
}
void print(vector<vector<int> > &factor,int arr[],vector<int>&leastPrimeDivisorId){
        /*for(int i=1;i<factor.size();i++){
            cout<<arr[i]<<"{";
            for(int j=max(0,leastPrimeDivisorId[i]);j<factor[i].size();j++)
                cout<<factor[i][j]<<",";
            if(leastPrimeDivisorId[i]>=factor[i].size()) cout<<"1,";
                cout<<"}  ";
        }
        cout<<endl;*/
}
int main(){
    int t; cin >> t; while(t--){
        int N,Q; cin >> N >> Q;
        int arr[N+1]; for(int i=1;i<=N;i++) cin >> arr[i];
        vector<vector<int> >factor(N+1,vector<int>());
        vector<int> leastPrimeDivisorId(N+2,0);
        for(int i=1;i<=N;i++)
            factor[i]=getPrimeFactor(arr[i]);
        print(factor,arr,leastPrimeDivisorId);
        while(Q--){
            int choice,L,R; cin >> choice >> L >> R;
            if(choice==0){
                Update(L,R,leastPrimeDivisorId);
                print(factor,arr,leastPrimeDivisorId);
            }else{
                cout<<Get(L,R,factor,leastPrimeDivisorId)<<endl;
            }
        }
    }return 0;
}
