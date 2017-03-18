#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
 
int BLOCK;
int bit[10000007];
int MAX;
char buffer[35];
 
inline void read(int &x){
    register char c = gc();
    for(;c<'0' || c>'9';c=gc());
    x=0;
    for(;c>='0' && c<='9';c=gc())
        x = (x<<3)+(x<<1)+(c-'0');
}
inline void write(long long x){
    register int i = 0;
    do
        buffer[i++]=x%10+'0',x/=10;
    while (x);
    while(i-1>=0)
        pc(buffer[--i]);
    pc('\n');
}
long long query(int i,long long sum=0){
    for(;i>0;i -= (i&(-i)))
        sum+=bit[i];
    return sum;
}
void update(int i,int SIZE){
 
    for(;i<=SIZE;i += (i&(-i)) )
        bit[i]+=1;//,cout<<i<<" "<<SIZE<<endl;;
}
int main(){
 
    //freopen("in.txt","r",stdin);
    
    int T;
    read(T); //cout<<T<<endl;
 
    while(T--){
        int N;
        read(N); //cout<<N<<endl;
 
        vector<int> arr(N);
        for(int i=0;i<N;i++)
            read(arr[i]);//,cout<<arr[i]<<" "; cout<<endl;
 
        vector<int> arr_copy = arr;
        sort(arr_copy.begin(),arr_copy.end());
        map<int,int> cmp;
        for(int i=0;i<N;i++)
            if(cmp.find(arr_copy[i])==cmp.end())
                cmp[arr_copy[i]]=cmp.size()+1;
 
        int SIZE = cmp.size()+1;
        for(int i=0;i<=SIZE;i++)
            bit[i]=0; //intialize bit
 
        long long ans = 0;
        for(int i=0;i<N;i++){
           // cout<<i<<" ===> "<<query(cmp[arr[i]])<<endl;
            ans+=i-query(cmp[arr[i]]);
            update(cmp[arr[i]],SIZE);
        }
        //cout<<ans<<endl;
        write(ans);
    }
    return 0;
}
