#include<bits/stdc++.h>
using namespace std;
int arr[1005][1005][5];
int MAX[1005][1005],MAX2[1005][1005],final_ans,i,j;
map<int,int> emap;
set<int>eset;
void populateSum(int n, int m, int r,int c){
        int i,j;
        //rowwise commulative
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                arr[i][j][1]=arr[i][j-1][1]+arr[i][j][0]; } }
        //rowwise of segment length of r commulative
        for(i=1;i<=n;i++){
            for(j=0;j<c;j++) {arr[i][j][2]=arr[i][j][1];}
            for(j=c;j<=m;j++){
                arr[i][j][2]=arr[i][j][1]-arr[i][j-c][1];} }
                         //for(int i=1;i<=n;i++){for(int j=1;j<=m;j++) cout<<arr[i][j][2]<<" "; cout<<endl;}
        //column wise commulative
         for(j=1;j<=m;j++){
            for(i=1;i<=n;i++){
                arr[i][j][3]=arr[i-1][j][3]+arr[i][j][2];}}
                         //for(int i=1;i<=n;i++){for(int j=1;j<=m;j++) cout<<arr[i][j][3]<<" "; cout<<endl;}
         //sum of r*c matrix
         for(j=1;j<=m;j++){
            for(i=0;i<r;i++){ arr[i][j][4]=arr[i][j][3];}
            for(i=r;i<=n;i++){
                arr[i][j][4]=arr[i][j][3]-arr[i-r][j][3];}}
                    //for(int i=1;i<=n;i++){for(int j=1;j<=m;j++) cout<<arr[i][j][4]<<" "; cout<<endl;}
}
// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
void printKMax(int I, int m, int k){
std::deque<int>  Qi(k);
    for (j = 1; j <= k; ++j){
        while ( (!Qi.empty()) && arr[I][j][0] >= arr[I] [Qi.back()][0])
            Qi.pop_back();
        Qi.push_back(j);
    }
    for ( ; j <= m; ++j){
        MAX[I][j-1]=arr[I] [Qi.front()][0];
        while ( (!Qi.empty()) && Qi.front() <= j - k)
            Qi.pop_front();
        while ( (!Qi.empty()) && arr[I][j][0] >= arr[I][Qi.back()][0])
            Qi.pop_back();
        Qi.push_back(j);
    }
    MAX[I][m]=arr[I] [Qi.front()][0];
    for(j=k-1;j>=0;j--)
        MAX[I][j]=MAX[I][j+1];
}
int printKMax2(int J, int n, int k){
std::deque<int>  Qi(k);
    for (i = 1; i <= k; ++i){
        while ( (!Qi.empty()) && MAX[i][J] >= MAX[Qi.back()][J])
            Qi.pop_back();
        Qi.push_back(i);
    }

    for ( ; i <= n; ++i){
        MAX2[i-1][J]=MAX[Qi.front()][J];
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
        while ( (!Qi.empty()) && MAX[i][J] >= MAX[Qi.back()][J])
            Qi.pop_back();
        Qi.push_back(i);
    }
    MAX2[n][J]=MAX[Qi.front()][J];
    for(i=k-1;i>=0;i--)
        MAX2[i][J]=MAX[i+1][J];
}
int CalMaxSeg(int n,int m,int r,int c){
    final_ans=INT_MAX; int r_c=r*c;

    for(int i=1;i<=n;i++)
        printKMax(i,m,c);
    for(int j=1;j<=m;j++)
        printKMax2(j,n,r);
    for(int i=r;i<=n;i++)
        for(int j=c;j<=m;j++)
            final_ans=min(final_ans,MAX2[i][j]*r_c-arr[i][j][4]);
    return final_ans;
}
int main(){
    int n,m,i,j,q,r,c; scanf("%d%d",&n,&m);//cin >> n >> m;
    for(i=0;i<=n;i++) arr[i][0][0]=arr[i][0][1]=arr[i][0][2]=arr[i][0][3]=arr[i][0][4]=0;
    for(j=0;j<=m;j++) arr[0][j][0]=arr[0][j][1]=arr[0][j][2]=arr[0][j][3]=arr[0][j][4]=0;
    for(i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&arr[i][j][0]);
    scanf("%d",&q);
    while(q--){
        int r,c; scanf("%d%d",&r,&c);// cin >> r >> c;
        populateSum(n,m,r,c);//populate sum of r*c matrix
        printf("%d\n",CalMaxSeg(n,m,r,c));// cout<<final_ans<<endl;
    }
    return 0;
}
