/*
	RAMESH CHANDRA
	PRE-FINAL YEAR B.TECH
	NITK SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ans=0;
vector<string> V;
void permuteString(string & A,int s,int e){

    if(s==e) {V.push_back(A); return; }
    else{

        for(int i=s;i<=e;i++){
            swap( A[s],A[i]);
            permuteString(A,s+1,e);
            swap(A[i],A[s]);
        }
    }
}
int main(){

    ll T;
    scanf("%lld",&T);
    while(T--){

        string s; cin>>s;
        ans=0;
        V.clear();
        permuteString(s,0,s.length()-1);
        ll ans=0;
        for(ll i=0;i<V.size();i++){

            for(ll j=0;j<V.size();j++){

                    string A=V[i];
                    string B=V[j];

                    //first swap
                    int I=0,J=0,i=0;
                    for(;i<A.size();i++){
                        if(A[i]!=B[i]){I=i;J=i; break;}
                    }
                    for(;i<A.size();i++){
                        if(A[i]!=B[i] && A[i]==B[I]){J=i; break;}
                    }
                    swap(A[I],A[J]);
                    //second swap
                     I=0,J=0,i=0;
                    for(;i<A.size();i++){
                        if(A[i]!=B[i]){I=i;J=i; break;}
                    }
                    for(;i<A.size();i++){
                        if(A[i]!=B[i] && A[I]==B[i]){J=i; break;}
                    }
                    swap(B[I],B[J]);
                    if(A!=B) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
