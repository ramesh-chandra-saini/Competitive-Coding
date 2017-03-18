#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked

int BLOCK;
int f[1000006];
char buffer[35];

inline void read(int &x){
    register char c = gc();
    for(;c<'0' || c>'9';c=gc());
    x=0;
    for(;c>='0' && c<='9';c=gc())
        x = (x<<3)+(x<<1)+(c-'0');
}
inline void write(int x){
    register int i = 0;
    do
        buffer[i++]=x%10+'0',x/=10;
    while (x);
    while(i-1>=0)
        pc(buffer[--i]);
    pc('\n');
}
int SQRT(int N){
    int sq = (int)sqrt(N);
    while ((sq+1)*(sq+1)<=N)
        sq++;
    while ((sq-1)*(sq-1)>=N)
        sq--;
    return sq;
}
bool __cmp(pair<pair<int,int> ,int > A, pair<pair<int,int> ,int > B){
    if( A.first.first/BLOCK != B.first.first/BLOCK)
        return A.first.first/BLOCK < B.first.first/BLOCK;
    return A.first.second<B.first.second;
}


int main(){

    int N;
    read(N);

    int arr[N+1];
    for(int i=1;i<=N;i++)
        read(arr[i]);

    int Q;
    read(Q);

    pair<pair<int,int> ,int > q[Q];
    for(int i=0;i<Q;i++)
        read(q[i].first.first),read(q[i].first.second), q[i].second=i;

    ///Mo's Algorithm

    BLOCK=SQRT(N);
    sort(q,q+Q,__cmp);

    int ans[Q];
    int mo_left = 1,mo_right = 1,counter=1;
    for(int i=0;i<1000006;i++)
        f[i]=0;
    f[arr[1]]=1;///self made query
    for(int i=0;i<Q;i++){
        int L   = q[i].first.first;
        int R   = q[i].first.second;
        int qNo = q[i].second;

        while(mo_right+1<=R){ ///extend Segment --> right

            mo_right=mo_right+1;
            counter+=(f[arr[mo_right]]==0);
            f[arr[mo_right]]=f[arr[mo_right]]+1;
        }

        while(mo_right-1>=R){ ///cut segment <--- right

            counter-=(f[arr[mo_right]]==1);
            f[arr[mo_right]] = f[arr[mo_right]]-1;
            mo_right=mo_right-1;
        }

        while(mo_left-1>=L){  ///extend segment <-- left

           mo_left=mo_left-1;
           counter+=(f[arr[mo_left]]==0);
           f[arr[mo_left]]=f[arr[mo_left]]+1;
        }

        while(mo_left+1<=L){   ///cut segment --> left

            counter-=(f[arr[mo_left]]==1);
            f[arr[mo_left]]=f[arr[mo_left]]-1;
            mo_left=mo_left+1;
        }

        ans[qNo]=counter;
    }
    for(int qNo=0;qNo<Q;qNo++)
        write(ans[qNo]);
    return 0;
}
