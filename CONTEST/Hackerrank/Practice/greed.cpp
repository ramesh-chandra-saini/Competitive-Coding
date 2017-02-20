#include<bits/stdc++.h>
using namespace std;

int  main(){

    long long int  n;
    cin >> n;

    long long int  arr[n+2];
    for(long long int  i=1;i<=n;i++)
        cin >> arr[i];
    arr[0]=INT_MIN ;arr[n+1]=INT_MAX;
    sort(arr,arr+n+2);
    long long int  P,Q;
    cin >> P >> Q;

    long long int  ans=INT_MAX,diff=INT_MIN;
    long long int __check,__diff;
    for(long long int  i=1;i<=n+1;i++){

        __check=(arr[i]-arr[i-1])/2;
        cout<<__check<<" ";
        __check=max(__check,P);
        cout<<__check<<" ";
        __check=min(__check,Q);
        cout<<__check<<" ";

        if(__check>=arr[i-1] && __check<=arr[i]){

            __diff=min(abs(__check-arr[i-1]),abs(__check-arr[i]));

            if(__diff>diff){

                    ans=__check; diff=__diff;
            }
            else if(__diff==diff){

                if(ans>__check)
                    ans=__check;
            }
        }
        else cout<<"NO"<<endl;
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
