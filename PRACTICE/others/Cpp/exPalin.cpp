#include<bits/stdc++.h>
using namespace std;
bool isPalin(string &A){

    for(int i=0;i<A.length();i++)
        if(A.at(i)!=A.at(A.length()-1-i))
            return false;
    return true;
}
int main(){

    int t;
    cin >> t;

    string s,store;
    vector<int> palin;
    while(t--){

        s.clear();
        cin >> s;
        int l=s.length();
        long long int ans=0;
        for(long long int i=1;i<=l;i++){
            store.clear();
            store.push_back(s.at(i-1));
            ans++;
            for(long long int fact=2;fact<=l;fact++){

                for(long long int st=i*fact;st<=l;st*=fact){

                    store.push_back(s.at(st-1));
                    if(isPalin(store))ans++;

                }
                store.clear();
                store.push_back(s.at(i-1));
            }

        }
        cout<<ans<<endl;
    }

    return 0;
}
