#include<bits/stdc++.h>
using namespace std;
/*
vector<bool> isPrime(10000001,true);
void __init(){

    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=10000000;i++)
        if(isPrime[i])
            for(int j=i*i;j<=10000000;j+=i)
                isPrime[j]=false;
}
*/
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void read(int &x){

    x=0;
    register char c=gc();

    for(;c<'0' || c>'9';c=gc());

    for(;c>='0' && c<='9';c=gc())
        x=(x<<3)+(x<<1)+(c-'0');
}
inline void write(long long int x){

    register char buffor[35];
    register int i=0;

    do{

        buffor[i++]=(x%10)+'0';
        x/=10;
    } while(x);
    i--;
    while(i>=0) putchar_unlocked(buffor[i--]);
    putchar_unlocked('\n');
}
int __gcd(int a,int b){

    if(b==0) return a;
    return __gcd(b,a%b);
}
int main(){

    //__init();
    int T,N,i;
    long long int ans;
    //cin >> T;
    read(T);
    while(T--){

        ans=0;
        //cin >> N;
        read(N);


                        ///checker solution : brute force
                        for(i=1;i<=N;i++)
                            ans+=(N/__gcd(i,N));//cout<<(N/__gcd(i,N))<<" ";cout<<endl;
                        //cout<<ans<<endl;
                        write(ans);
    }
    return 0;
}
