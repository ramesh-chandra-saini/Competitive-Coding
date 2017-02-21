#include<bits/stdc++.h>
using namespace std;
int A[1025][2];
//vector<vector<int> >A(1025,vector<int>(2,0));
int main(){
    int n,k,x;scanf("%d%d%d",&n,&k,&x);

    int prev = 0,curr=1;
    for(int i=0,x;i<n;i++)
        scanf("%d",&x),A[x][prev]++;
    while(k--){
        int total = 0,num,freq;
        for(int i=0;i<1025;i++){
            num = i,freq = A[i][prev];
            if(total%2==0){
                A[num^x][curr]+=(freq+1)/2;
                A[num][curr]+=freq/2;
            }else{
                A[num^x][curr]+=freq/2;
                A[num][curr]+=(freq+1)/2;
            }
            total+=freq,A[i][prev]=0;
        }
        swap(prev,curr);
    }
    int mn = INT_MAX,mx = INT_MIN;
    for(int i=0;i<1025;i++)
        if(A[i][prev])
            mn = min(mn,i),mx = max(mx,i);
    printf("%d %d\n",mx,mn);
}
