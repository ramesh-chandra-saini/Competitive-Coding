#include<bits/stdc++.h>
using namespace std;

int arr[1000006];


int main(){

    int t,n,temp;

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);

        bool swp=false,ans=true;

        for(int i=1;i<n;i++)
            if(arr[i]<arr[i-1]){

                if(swp==false)  temp=arr[i-1],arr[i-1]=arr[i],arr[i]=temp;
                swp=true ^ swp;
            }
            else swp=false;

        for(int i=0,prev=INT_MIN;i<n;prev=arr[i],i++)
            if(prev>arr[i]) ans=false;

        if(ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
