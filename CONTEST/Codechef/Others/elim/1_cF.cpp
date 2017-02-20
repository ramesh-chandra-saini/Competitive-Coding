#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void printSet(set<ll> &A){
    for(set<ll>::iterator it=A.begin();it!=A.end();++it)
        cout<<*it<<",";
}
ll countNumOfDigit(ll N){
    ll digit=0;
    do{
        N/=7LL,digit++;
    } while(N);
    return digit;
}
bool disJointSet(set<ll> A, set<ll> B){
    if(A.size()+B.size()>7LL) return false;
    set<ll> C(A);
    C.insert(A.begin(),A.end());
    C.insert(B.begin(),B.end());
    //printSet(A);cout<<" + ";printSet(B); cout<<" = "; printSet(C);
    //(C.size() == A.size()+B.size())?cout<<"\tYes"<<" " : cout<<"\tNo"; cout<<endl;
    return C.size() == A.size()+B.size();
}
void checkForThisValue(ll N,vector<set<ll> > & arr,ll bits){
    set<ll> newSet; newSet.clear();
    vector<ll> rep7bas;
    for(ll i=0;i<bits;i++){
        ll digit=N%7LL; rep7bas.insert(rep7bas.begin(),digit);
        if(newSet.find(digit)!=newSet.end()) return;
        else newSet.insert(digit);
        N/=7LL;
    }
    //for(int i=0;i<rep7bas.size();i++) cout<<rep7bas[i]; cout<<" ";
    arr.push_back(newSet);
}

int main(){
    ll N,M ; cin >> N >> M;
    ll numOfDig_N=countNumOfDigit(N-1);
    ll numOfDig_M=countNumOfDigit(M-1);
    ll ans=0;
    if(numOfDig_M>7 || numOfDig_N>7) cout<<ans<<endl;
    else{
        vector<set<ll> > possibleHours;
        for(ll i=0;i<N;i++)checkForThisValue(i,possibleHours,numOfDig_N); //cout<<endl;
        vector<set<ll> > possibleMinuts;
        for(ll i=0;i<M;i++) checkForThisValue(i,possibleMinuts,numOfDig_M); //cout<<endl;
        map<set<ll> ,ll> mapOfPossibleHours;
        for(ll i=0;i<possibleHours.size();i++) mapOfPossibleHours[possibleHours[i]]++;
        map<set<ll>,ll> mapOfPossibleMinuts;
        for(ll i=0;i<possibleMinuts.size();i++) mapOfPossibleMinuts[possibleMinuts[i]]++;
        for(map<set<ll> ,ll>:: iterator it = mapOfPossibleHours.begin();it!=mapOfPossibleHours.end();++it){
            for(map<set<ll> ,ll>::iterator it2=mapOfPossibleMinuts.begin();it2!=mapOfPossibleMinuts.end();++it2){
                if(disJointSet(it->first,it2->first)) ans+=(it->second)*(it2->second);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
