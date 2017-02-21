#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    multiset<int> mySet;mySet.clear();
    mySet.insert(arr[0]); cout<<arr[0]<<endl;
    multiset<int> :: iterator it=mySet.begin();
    multiset<int> :: iterator prev = it;
    long double mid ;
    for(int i=1;i<n;i++){
            mySet.insert(arr[i]);    for(multiset<int> :: iterator t=mySet.begin();t!=mySet.end();t++) cout<<*t<<" "; cout<<endl;
        if(i%2==0)
            mid = *it,cout<<*it<<endl;
        else
            prev = it,++it,mid = (long double)(*prev+*it)/2.0,cout<<*prev<<" "<<*it<<endl;;
        printf("%.12Lf\n",mid);
    } return 0;
}
