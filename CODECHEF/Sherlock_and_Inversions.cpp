#include<bits/stdc++.h>
using namespace std;

int BIT[1000006];
int BLOCK;
int SIZE;

int SQRT(int N){
    int sq = (int)sqrt(N);
    while ((sq+1)*(sq+1)<=N)
        sq++;
    while ((sq-1)*(sq-1)>=N)
        sq--;
    return sq;
}
bool __cmp(pair<pair<int,int>,int> A, pair<pair<int,int>,int> B){

    if(A.first.first/BLOCK != B.first.first/BLOCK)
        return A.first.first/BLOCK < B.first.first/BLOCK;

    return A.first.second < B.first.second;
}
void print(vector<int>&arr,int N){
    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void compress(int N,vector<int>&arr){

    vector<int> arr_copy = arr;
    sort(arr_copy.begin(),arr_copy.end());

    map<int,int> cmp;
    for(int i=0;i<N;i++)
        if(cmp.find(arr_copy[i])==cmp.end())
            cmp[arr_copy[i]]=cmp.size();

    for(int i=0;i<N;i++)
        arr[i]=cmp[arr[i]];

    SIZE = cmp.size()+1;
}
long long query(int i,long long sum=0){
    for(;i;i -= (i&(-i)))
        sum += BIT[i];
    return sum;
}
void update(int i,int val){
    for(;i<=SIZE;i += (i&(-i)))
        BIT[i] += val;
}
int main(){

//    freopen("in.txt","r",stdin);

    int N;
    scanf("%d",&N);

    vector<int> arr(N);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);


    compress(N,arr);

    for(int i=0;i<=SIZE;i++)
        BIT[i]=0; ///intialize BIT

    ///Mo's Algorithm

    int Q;
    scanf("%d",&Q);

    pair<pair<int,int>,int> q[Q];
    for(int i=0;i<Q;i++){
        scanf("%d%d",&q[i].first.first, &q[i].first.second);
        q[i].first.first--;
        q[i].first.second--;
        q[i].second=i;
    }
   ///sort query
    BLOCK = SQRT(N);
    sort(q,q+Q,__cmp);

    int mo_left=0,mo_right=0,total=1;
    long long  ans[Q],inv=0;
    ///self made query
    update(arr[0],1);

    for(int i=0;i<Q;i++){

        int L   = q[i].first.first;
        int R   = q[i].first.second;
        int qNo = q[i].second;

        while(mo_right+1<=R){

            mo_right=mo_right+1;
            inv+=total-query(arr[mo_right]);
            update(arr[mo_right],1);
            total=total+1;
        }

        while(mo_right-1>=R){

            inv-=total-query(arr[mo_right]);
            update(arr[mo_right],-1);
            mo_right=mo_right-1;
            total=total-1;
        }

        while(mo_left+1<=L){

            inv-=query(arr[mo_left]-1);
            update(arr[mo_left],-1);
            mo_left=mo_left+1;
            total = total-1;
        }

        while(mo_left-1>=L){

            mo_left=mo_left-1;
            inv+=query(arr[mo_left]-1);
            update(arr[mo_left],1);
            total = total+1;
        }
        ans[qNo] = inv;
    }
    for(int i=0;i<Q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
