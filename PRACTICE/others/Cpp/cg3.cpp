#include<bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    int arr[N][2];
    for(int i=0;i<N;i++)
        cin >> arr[i][0] >>arr[i][1];

    bool visit[N];
   for(int i=0;i<N;i++)
    visit[i]=false;

    for(int i=0;i<N;i++){
        int search=arr[i][1];
        bool flag=false;
        for(int j=0;j<N && flag==false;j++){
            if(arr[j][0]==search && visit[j]==false){
                visit[j]=true;
                flag=true;
                //cout<<j<<" "<<search<<endl;
            }
        }

        for(int j=0;j<N && flag==false;j++){
            for(int k=j+1;k<N && flag==false;k++){
                if(arr[j][0]+arr[k][0]==search && visit[j]==false && visit[k]==false){
                    visit[j]=visit[k]=true;
                    //cout<<j<<" "<<k<<" "<<search<<endl;
                    flag=true;
                }
            }
        }
    }
    //for(int i=0;i<N;i++) cout<<visit[i]<<" "; cout<<endl;
    for(int i=0;i<N;i++){
        if(visit[i]==false){
            cout<<arr[i][0]<<endl;
            return 0;
        }
    }
    return 0;
}
