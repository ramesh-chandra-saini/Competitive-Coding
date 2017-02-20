#include<bits/stdc++.h>
using namespace std;

int ct=0 , __min=INT_MAX,  __max=INT_MIN;

void permutation( vector<int> & D,int l,int r){

    if(l==r){
        int Num=0;

        for(int i=0;i<D.size();Num=Num*10+D[i++]);
        /*    cout<<D[i]<<" ";
        cout<<endl;
        */
        if(Num%8==0) {
            __min=min(__min,Num);
            __max=max(__max,Num);
            ct++;
        }
    }
    else
        for(int i=l;i<=r;i++){

            swap(D[l],D[i]);
            permutation(D,l+1,r);
            swap(D[l],D[i]);
        }
}

int main(){

    int T,N;
    cout<<strcmp("123","1234")<<endl;
    cout<<strcmp("1234","1234")<<endl;
    cin >> T;

    vector<int> D;

    while(T--){

            cin >> N ;
            ct=0, __min=INT_MAX,  __max=INT_MIN;
            D.clear();
            for(;N>0; N/=10)
                D.push_back(N%10);
            permutation(D,0,D.size()-1);
            //cout<<ct<<endl;
            if(ct==0) cout << "-1" <<endl;
            else cout<< __min << " " << __max << endl;
    }

    return 0;
}
