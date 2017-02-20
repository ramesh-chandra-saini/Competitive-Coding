#include<bits/stdc++.h>
using namespace std;
vector<int>Map    (100000008,0);
vector<int>segTree(100000008,0);
int query(int L,int R,int l,int r, int index,int n){
    if( L<0 || R<0 || L>=n && R>=n ||  L>R || l>r || R<l || r<L) return 0;
    if(L<=l && r<=R) return segTree[index];
    return max(query(L,R,l,(l+r)/2,2*index+1,n),query(L,R,1+(l+r)/2,r,2*index+2,n));
}
int build(int index,int L,int R,int arr[]){
    if(L>R) return 0;
    if(L==R)return segTree[index]=arr[L];
    return segTree[index]=max(build(2*index+1,L,(L+R)/2,arr),build(2*index+2,1+(L+R)/2,R,arr));
}
void solveFaster(vector<pair<int,int> >&recordChecker,int checker[], int arr[],int maxArr[],int n,int D){
  int L=0,l=0,R=0,r=0;vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        while(l<recordChecker[checker[i]].first) Map[arr[l]]++,l++;
        while(L<i-D && L<=l)  Map[arr[L]]--,L++;
        while(R<=min(i+D,n-1)) Map[arr[R]]++,R++;
        while(r<=min(recordChecker[checker[i]].second,R)) Map[arr[r]]--,r++;
        ans[i]=(maxArr[i]>arr[i])?Map[maxArr[i]]:0;
    }
    for(int i=0;i<n;i++)
        if(ans[i]) printf("%d %d\n",maxArr[i],ans[i]);
        else printf("-1\n");
}
int main(){
    int n,m; cin >> n >> m;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    build(0,0,n-1,arr);
    int checker[n],checkerId=0;
    vector<pair<int,int> >recordChecker;
    while(m--){
        int L,R; cin >> L >> R; recordChecker.push_back(make_pair(L-1,R-1));
        for(int i=L-1;i<R;i++)  checker[i]=checkerId;checkerId++;
    } int D; cin >> D;// cout<<" D : "<<D<<endl;
    int maxArr[n];
    for(int i=0;i<n;i++)
        maxArr[i]=max(query(max(i-D,0),recordChecker[checker[i]].first-1,0,n-1,0,n),query(recordChecker[checker[i]].second+1,min(i+D,n-1),0,n-1,0,n));
    solveFaster(recordChecker,checker,arr,maxArr,n,D);
    return 0;
}
