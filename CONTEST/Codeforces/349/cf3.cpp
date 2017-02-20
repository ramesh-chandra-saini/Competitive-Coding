#include<bits/stdc++.h>
using namespace std;

bool __cmp(const pair<int,int> &A,const pair<int,int> &B){

    if(A.second!=B.second) return A.second<B.second;
    return A.first<B.first;
}
int main(){

    int n;
    cin >> n;

    vector<pair<int,int> > P(n);
    vector<int> W(n);
    for(int i=0;i<n;i++)
        cin >> P[i].first >> P[i].second;
    for(int i=0;i<n;i++)
        cin >> W[i];
    sort(P.begin(),P.end(),__cmp);

    bool Yes=true;
    for(int i=0;i<n;i++)
        if(P[i].second-P[i].first!=W[i])Yes=false;
    if(Yes==false) {

        bool Yes=true;
        sort(P.begin(),P.end());
            for(int i=0;i<n;i++)
                if(P[i].second-P[i].first!=W[i])Yes=false;
        if(Yes==false) cout<<"NO"<<endl;
        else{
                cout << "YES" <<endl;
                for(int i=0;i<n;i++)
                    cout << P[i].first<<" "<<P[i].second<<endl;
        }
    }
    else{

        cout << "YES" <<endl;
        for(int i=0;i<n;i++)
            cout << P[i].first<<" "<<P[i].second<<endl;
    }
    return 0;
}
