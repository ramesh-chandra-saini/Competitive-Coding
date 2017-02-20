#include<bits/stdc++.h>
using namespace std;

map<int,int> hashing;

int main(){

    int N; cin >> N;

    int arr[N];
    for(int i=0;i<N;i++)
        cin >> arr[i];

    vector<int>odd; odd.clear();
    vector<int>even; even.clear();

    for(int i=0;i<N;i++){

        if(arr[i]%2==0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());

    int ans[N];

    for(int i=0,o=0,e=0;i<N;i++){

        if(i%2==0)
            ans[i]=odd[o++];
        else
            ans[i]=even[e++];
    }


    //for(int i=0;i<N;i++) cout<<ans[i]<<" "; cout<<endl;

    hashing.clear();
    for(int i=0;i<N;i++)
        hashing[arr[i]]=i;

    int f_ans=0;

    for(int i=0;i<N;i++){

        if(arr[i]!=ans[i]){

            f_ans++;

            int idx1=hashing[arr[i]];
            int idx2=hashing[ans[i]];
            hashing[ans[i]]=idx1;
            hashing[arr[i]]=idx2;

            //swap value in array too

            int temp2=arr[idx1];
            arr[idx1]=arr[idx2];
            arr[idx2]=temp2;
           //cout<<arr[idx1]<<" "<<arr[idx2]<<endl;
        }
    }
    cout<<f_ans<<endl;
    return 0;
}
