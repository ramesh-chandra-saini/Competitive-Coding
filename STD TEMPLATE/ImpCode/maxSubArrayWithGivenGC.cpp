#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
void read(int &x){
    register char c = gc();
    for(;c<'0' || c>'9';c=gc());
    for(x=0;c>='0'&& c<='9';c=gc())
        x= (x<<3)+(x<<1)+(c-'0');
}
int ans=0;
int query(int ss, int se,int qs,int qe,int index,vector<int>&segTree){
    if(qs>qe || ss>se || se<qs || qe<ss ) return 0;
    if(qs<=ss && se<=qe)    return segTree[index];
    return __gcd(query(ss,(ss+se)/2,qs,qe,2*index+1,segTree),
        query((ss+se)/2+1,se,qs,qe,2*index+2,segTree));
}
int update(int ss,int se,int index,int pos, int value,vector<int>&segTree){
    if(ss>se)
        return 0;
    if(ss==se)
        return segTree[index]=value;
    int mid = (ss+se)/2;
    if(ss<=pos && pos<=mid)
        update(ss,mid,2*index+1,pos,value,segTree);
    else
        update(mid+1,se,2*index+2,pos,value,segTree);
    return segTree[index] = __gcd(segTree[2*index+1],segTree[2*index+2]);

}
int build(int ss,int se,int index, int arr[], vector<int>&segTree){
    if(ss>se)
        return 0;
    if(ss==se)
        return segTree[index]=arr[ss];
    int mid = (ss+se)/2;
    build(ss,mid,2*index+1,arr,segTree);
    build(mid+1,se,2*index+2,arr,segTree);
    return segTree[index]=__gcd(segTree[2*index+1],segTree[2*index+2]);
}
bool isPossible(int windowSize,int n,int k,vector<int>&segTree){
    for(int i=1,j=windowSize;i<=n && j<=n;j++,i++)
        if(query(1,n,i,j,0,segTree)>=k)
            return true;
    return false;
}
void binarySearch(int low,int high,int n,int k,vector<int>&segTree){
    if(low>high)
        return ;
    int windowSize = (low+high)/2;
    if(isPossible(windowSize,n,k,segTree)==true){
        ans=windowSize;
        return binarySearch(windowSize+1,high,n,k,segTree);
    }
    return binarySearch(low,windowSize-1,n,k,segTree);
}
int main(){
        int n,k; read(n),read(k);
        int segSize = n*(ceil(log2(n)));
        vector<int> segTree(segSize,0);
        int arr[n+1];    for(int i=1;i<=n;i++) read(arr[i]);
        build(1,n,0,arr,segTree);
        ans =0;
        int i=1,j=1;
        while(true){
            int currGcd=__gcd(query(1,n,i,j,0,segTree),arr[j]);
            if(currGcd>=k){
                ans=max(ans,j-i+1);
                if(j>=n) break;
                else j++;
            }else{
                if(i>=n) break;
                else i++;
            }
        }
        printf("%d\n",ans);
     return 0;
}
