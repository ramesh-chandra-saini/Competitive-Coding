#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;
    cin >> t;

    vector<pair<int,int> > V(t);

    for(int i=0;i<t;i++)
        cin >> V[i].first >> V[i].second;

    int ans=-1;
    for(int i=0;i<t;i++){

        for(int j=i+1;j<t;j++){

            if(V[i].first!=V[j].first && V[i].second !=V[j].second){

                ans=abs(  (V[i].first-V[j].first)*(V[i].second-V[j].second)  );
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
