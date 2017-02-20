/*
    RAMESH CHANDRA
    NITK SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;
int hash[100000001];
int main(){

    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

   int ans=0;
    for(int i=0;i<n;i++){

        int dominant=0; set<int> s; s.clear();

        for(int j=i;j<n;j++){

            hash[arr[j]]++;
            s.insert(arr[j]);

            dominant=max(dominant,hash[arr[j]]);

            if( dominant > floor( (j-i+1)/2 ) ) ans++;
        }
        for(set<int> :: iterator it=s.begin();it!=s.end();++it)
            hash[(*it)]=0;
    }
    printf("%d\n",ans);
    return 0;
}
