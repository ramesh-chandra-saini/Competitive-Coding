#include<bits/stdc++.h>
using namespace std;
bool __cmp(const pair<int,int> &A, const pair<int,int> &B){
    if(A.first!=B.second) return A.first<B.first;
    return A.second>B.second;
}
bool qualified4Merging(pair<int,int> &A,pair<int,int> &B){

    if(A.second+1<B.first) return false;
    if(B.second+1<A.first) return false;
    if(A.first<=B.first && B.second<=A.second) return false;
    if(B.first<=A.first && A.second<=B.second) return false;
    return true;
}
int main(){

    int n,x,y;
    scanf("%d",&n);
    int __ans=n;
    vector<pair<int,int> > __arr(n);
    vector<pair<int,int> > __range(n);
    vector<vector<pair<int,int> > > __interval(n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&__arr[i].first,&__arr[i].second);
    sort(__arr.begin(),__arr.end(),__cmp);
    for(int i=0;i<n;i++)
           __range[i]=__arr[i],__interval[i].push_back(__arr[i]);
    for(int i=0;i<__range.size();i++){
        for(int j=i+1;j<__range.size();j++){
            if(__range[i].second+1 == __range[j].first){
                __range[i].second=__range[j].second;
                __interval[i].push_back(__interval[j]);
                __range.erase(__range.begin()+j);
                __interval.erase(__interval.begin()+j);
            }
        }
    }
    for(int i=0;i<__range.size();i++){
        for(int j=i+1;j<__range.size();j++){
            if(qualified4Merging(__range[i],__range[j])){
                __range[i].second=__range[j].second;
                __interval[i].push_back(__interval[j]);
                __range.erase(__range.begin()+j);
                __interval.erase(__interval.begin()+j);
            }
        }
    }
    for(int i=0;i<n;i++){
        x=__arr[i].first; y=__arr[i].second;
        for(int j=0;j<__range.size();j++){
            if(__range[j].first<=x && y<=__range[j].second){
                bool found=false;
                for(int k=0;k<__interval[j].size();k++){
                    if(__interval[j][k] == __arr[i]) found=true;
                }
                if(found == false){

                }
            }
        }
    }
    return 0;
}
