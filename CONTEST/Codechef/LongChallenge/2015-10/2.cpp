/*
    RAMESH CHANDRA 2 OCT 2015
    NATIONAL INSTITUTE OF TECHNOLOGY
    KARNATAKA SURATHKAL
    https://www.facebook.com/rameshc10695

    Approach : Greedy
*/
#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        string A,B;

        cin >>A>>B;

        int right=0;
        int wrong=0;
        int cost[n+1];

        for(int i=0;i<=n;i++){

            cin>>cost[i];
        }

        for(int i=0;i<n;i++){

            if(A.at(i)==B.at(i)) right++;
            else wrong++;
        }

        int ans=cost[0];
        if(!wrong) ans=cost[n];
        else{

            for(int i=0;i<=right;i++){

                ans=max(ans,cost[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
