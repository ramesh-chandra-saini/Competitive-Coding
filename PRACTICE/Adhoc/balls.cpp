#include<bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;

    while(T--){
        int N,M,K;
        cin >> N >> M >> K;

        int P[N];
        for(int i=0;i<N;i++)
            cin >> P[i];
        int D;
        for(int i=0;i<N;i++)
            cin >> D,P[i]-=D;
        int total=K+M;
        int C[total];
        for(int i=0;i<total;i++)
            cin >> C[i];

        sort(P,P+N);
        sort(C,C+total);

        int check=total-1;
        int match=N-1;

        while(check >= 0 && match >= 0){

            if(P[match]>=C[check]){

                P[match--]-=C[check--];
            }
            else check--;
        }
        int ans=0;
        for(int i=0;i<N;i++)
            ans+=P[i];

        cout<<ans<<endl;
    }
    return 0;
}
