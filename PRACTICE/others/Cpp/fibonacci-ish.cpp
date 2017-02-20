/*
    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
map<long long int,long long int> store;
map<long long int,long long int> ::iterator it;
int main(){

    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    long long int ans=2LL,zero=0LL;
    for(long long int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        it=store.find(arr[i]);
        if(it!=store.end()) ++(it->second);
        else store.insert(make_pair(arr[i],1LL));
        zero+=(arr[i]==0)?1LL:0LL;
    }
    ans=max(ans,zero);
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<n;j++){
            if( (arr[i]==0LL && arr[j]==0LL)|| i==j);
            else{
                long long int size=2LL;
                vector<long long int> usedElement;usedElement.clear();
                usedElement.push_back(arr[i]); it=store.find(arr[i]) ;--(it->second);
                usedElement.push_back(arr[j]); it=store.find(arr[j]) ;--(it->second);
                long long int first=arr[i],second=arr[j],temp;
                while(store.find(first+second)!=store.end() ){
                    it=store.find(first+second);
                    if(it->second<=0LL) break;
                    else{
                        usedElement.push_back(first+second);it=store.find(first+second); --(it->second) ;
                        temp=first+second;first=second; second=temp;
                        ++size;
                        ans=max(size,ans);
                    }
                }
                for(long long int u=0;u<usedElement.size();u++){
                    it=store.find(usedElement.at(u));++(it->second);
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
