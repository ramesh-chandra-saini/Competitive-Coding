
#include<bits/stdc++.h>
using namespace std;
bool __cmp(const pair<int,int> &A,const pair<int,int> &B){
    if (A.first!=B.first) return A.first<B.first ;
    return A.second<B.second;
}
int main(){

    int n,m; cin >> n >> m;
    vector<pair<int,int> > G;
    while(m--){
        int u,v; cin >> u >> v;
        if(u>v) swap(u,v);
        G.push_back(make_pair(u,v));
    }
    sort(G.begin(),G.end(),__cmp);
    vector<set<int> > vecA,vecB;
    set<int> A,B;
    bool possible=true;

    for(int i=0;i<G.size();i++){

        int u=G[i].first, v=G[i].second; cout<<u<<" "<<v<<endl;
        if( (A.find(u)!=A.end() && A.find(v)!=A.end()) ||
                (B.find(u)!=B.end() && B.find(v)!=B.end()) ){
            possible=false; break;
        }else{
            if(A.find(u)!=A.end()) B.insert(v);
            else if(A.find(v)!=A.end()) B.insert(u);
            else if(B.find(u)!=B.end()) A.insert(v);
            else if(B.find(v)!=B.end()) A.insert(u);
            else{
                vecA.push_back(A);vecB.push_back(B);
                A.clear();B.clear();
                A.insert(u),B.insert(v);//if no edges just take it
            }
        }
    }
    vecA.push_back(A);vecB.push_back(B);A.clear();B.clear();
    set<int> result;
    if(possible==false) cout<<"-1"<<endl;
    else{
          set<int> finalA,finalB;
         for(int i=0;i<vecA.size();i++){

            result.clear();set_difference(vecA[i].begin(), vecA[i].end(), finalA.begin(), finalA.end(),inserter(result, result.end()));
            if(result.size()<vecA[i].size()+finalA.size()){
                finalA.insert(vecA[i].begin(),vecA[i].end());
                finalB.insert(vecB[i].begin(),vecB[i].end());
            }else{
            result.clear();set_difference(vecB[i].begin(), vecB[i].end(), finalA.begin(), finalA.end(),inserter(result, result.end()));
            if(result.size()<vecB[i].size()+finalA.size()){
                finalA.insert(vecB[i].begin(),vecB[i].end());
                finalB.insert(vecA[i].begin(),vecA[i].end());
            }
            else{
                result.clear();set_difference(vecA[i].begin(), vecA[i].end(), finalB.begin(), finalB.end(),inserter(result, result.end()));
                if(result.size()<vecA[i].size()+finalB.size()){
                finalA.insert(vecB[i].begin(),vecB[i].end());
                finalB.insert(vecA[i].begin(),vecA[i].end());
                }
                else{
                result.clear();set_difference(vecB[i].begin(), vecB[i].end(), finalB.begin(), finalB.end(),inserter(result, result.end()));
                if(result.size()<vecA[i].size()+finalA.size()){
                    finalA.insert(vecA[i].begin(),vecA[i].end());
                    finalB.insert(vecB[i].begin(),vecB[i].end());
                }
                else{
                    finalA.insert(vecA[i].begin(),vecA[i].end());
                    finalB.insert(vecB[i].begin(),vecB[i].end());
                }

                }
            }
            }
r



            }



        cout<<finalA.size()<<endl;
        for(set<int>::iterator it=finalA.begin();it!=finalA.end();++it)
            cout<<(*it)<<" "; cout<<endl;
        cout<<B.size()<<endl;
        for(set<int>::iterator it=finalB.begin();it!=finalB.end();++it)
            cout<<(*it)<<" "; cout<<endl;
    }

return 0;
}
