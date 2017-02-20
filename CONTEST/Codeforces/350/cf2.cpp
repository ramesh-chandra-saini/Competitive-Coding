#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> A(n),B(n);
    int zero=0;
    for(int i=0;i<n;i++)
        cin >> A[i],zero+=(A[i]==0);
    for(int i=0;i<n;i++)
        cin >> B[i];
    if(zero==n){
        if(A==B) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{

        vector<int> AA, BB; AA.clear(); BB.clear();
        for(int i=0;i<n;i++){
            if(A[i]) AA.push_back(A[i]);
        }
        for(int i=0;i<n;i++){
            if(B[i]) BB.push_back(B[i]);
        }
        if(B.empty() || AA.size()!=BB.size() ) cout<<"NO"<<endl;
        else{

            int idx=BB.size();
            for(int i=0;i<AA.size();i++){

                if(AA[0]==BB[i]){
                    idx=i; break;
                }
            }
            if(idx==BB.size()) cout<<"NO"<<endl;
            else{

                vector<int> CC; CC.clear();
                for(int i=idx;i<BB.size();i++)
                    CC.push_back(BB[i]);
                for(int i=0;i<idx;i++)
                    CC.push_back(BB[i]);
                    if(AA==CC) cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
