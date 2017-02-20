#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main(){
    ll n;
    scanf("%lld",&n);
    vector<ll>arr(n);
    ll zero=0;//to count zero's
    for(ll i=0;i<n;zero+=(arr[i]==0),i++)
        scanf("%lld",&arr[i]);
    //sort is required for searching puspuse
    sort(arr.begin(),arr.end());
     //for(int i=0;i<n;i++)cout<<arr[i]<<" "; cout<<endl;
    ll ans=max(2LL,zero),length=0,first,second,temp,k;
    vector<ll> :: iterator it;
    //generate all possible pair of given array
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            length=2;//always length will we greater than 2
            first=arr[i],second=arr[j]; // take a pair
            if(arr[i] == 0LL && arr[j]==0LL) continue;
            it=arr.begin();
            while(binary_search(arr.begin(), arr.end(),(first+second))==true){
                it=lower_bound(it,arr.end(),(first+second));
                if(it==arr.begin()+i || it==arr.begin()+j) {
                    if(it!=arr.end()){
                        ++it;
                        if( (*it) == (first+second) ){
                            length++;
                            ans=max(ans,length);
                            temp=first+second; first=second; second=temp;
                        }
                        else break;
                    }
                    else break;
                }
                else{
                    length++;
                    ans=max(ans,length);
                    temp=first+second; first=second; second=temp;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
