#include<bits/stdc++.h>
using namespace std;
 int main(){


    long long int n,k,fir;
    scanf("%lld%lld",&n,&k);

    long long int A[n],B[n];
    set<pair<long long int,long long int> > T; T.clear();
    pair<long long int,long long int> P;
    for(long long int i=0;i<n;i++) scanf("%lld",&A[i]);

    for(long long int i=0;i<n;i++)
        scanf("%lld",&B[i]),T.insert( make_pair(-A[i]*B[i],i) );


    for(long long int i=0;i<k;i++){

        if(!T.empty()){
              P=*T.begin();
              T.erase(T.begin());
              A[P.second]--;
             fir=P.first+B[P.second];
             if(fir) T.insert(make_pair(fir,P.second));
        }
        else break;
    }
    for(long long int i=0;i<n;i++)
      printf("%lld ",A[i]); printf("\n");
}
