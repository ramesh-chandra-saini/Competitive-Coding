#include<bits/stdc++.h>
using namespace std;

int main(){

  freopen("in.txt","r",stdin);

    int N;
    scanf("%d",&N);

    vector<int> arr(N);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);

    int Q;
    scanf("%d",&Q);

    for(int q=0;q<Q;q++){
        int L,R;
        scanf("%d%d",&L,&R);
        long long ans = 0;
        for(int i=L-1;i<=R-1;i++)
            for(int j=i+1;j<=R-1;j++)
                ans+=(arr[i]>arr[j]);
        printf("%lld\n",ans);
    }
    return 0;
}
