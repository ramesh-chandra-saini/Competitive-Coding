#include<bits/stdc++.h>
using namespace std;

void __bin(int arr[],int low,int high,int key,float &idx){

    if(low>high) return;
    int mid=(low+high)/2;

    if(arr[mid]<=key){

        idx=(float)mid+0.5;
        __bin(arr,mid+1,high,key,idx);
    }
    else
        __bin(arr,low,mid-1,key,idx);
}

int bin(int arr[],int low,int high,int key){


    if(low>high) return -1;

    int mid=(low+high)/2;

    if(arr[mid]==key) return mid;
    if(arr[mid]<key) return bin(arr,mid+1,high,key);
    return bin(arr,low,mid-1,key);
}
int main(){


    int N,Q;

    cin >> N >> Q;

    int arr[N];

    for (int i=0;i<N;i++)
        cin >> arr[i];

    sort(arr,arr+N);

    int X,K,type;
    while(Q--){

        cin >> X >> K >> type;

        int idx=bin(arr,0,N-1,X);

        float idx2=-0.5;

        __bin(arr,0,N-1,X,idx2);

        if(type){

            if(idx!=-1){

                    if(idx-K>=0) cout<<arr[idx-K]<<endl;
                    else cout<<"-1"<<endl;
            }
            else{

                int __c=ceil( (float)idx2-(float)K );
                if(__c>=0 && __c<N) cout<<arr[__c]<<endl;
                else cout<<"-1"<<endl;
            }
        }
        else{
                if(idx!=-1){
                    if(idx+K<N)cout<<arr[idx+K]<<endl;
                    else cout<<"-1"<<endl;
                }
                else{

                    int __f=floor(   (float)idx2+(float)K  );

                    if(__f>=0 && __f<N) cout<<arr[__f]<<endl;
                    else cout<<"-1"<<endl;
                }
        }

    }
    return 0;
}









