#include<bits/stdc++.h>
using namespace std;

long long int main(){


    long long int T;

    scanf("%lld",&T);

    while(T--){


        long long int A,B;

        scanf("%lld%lld",&A,&B);

        long long int Ans_MASK=-1+(1<<32);
        long long int Diff=B-A;

        long long int Diff_Ans_MASK=1;
        while(Diff){

            Diff_Ans_MASK<<=1;
            Diff>>=1;
        }
        Diff_Ans_MASK-=1;
        Ans_MASK=Ans_MASK & ( Ans_MASK - Diff_Ans_MASK );
        Ans_MASK=Ans_MASK & A;
        Ans_MASK=Ans_MASK & B;

        prlong long intf("%lld\n",Ans_MASK);
    }
    return 0;
}
