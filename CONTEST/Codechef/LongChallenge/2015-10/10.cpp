#include<bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

inline void read(int &x){

    x=0;
    register char c=gc();

    for(;c<'0' || c>'9';c=gc());

    for(;c>='0' && c<='9';c=gc())
        x=(x<<3)+(x<<1)+(c-'0');
}
inline void write(int x){

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

long long int end=(long long int )( (double)1.45*(double)CLOCKS_PER_SEC );
int  ar[100005];
int arr[100005];
bool subset[10001][10001];
//GeekForGeeks...I got Dp Approach but will see what will happen

bool isSubsetSum(int n, int sum)
{

     for (int i = 1; i <sum ; i++)
     {
       for (int j = 1; j <= n ; j++)
       {

         if (i >= ar[j-1])
           subset[i][j] = subset[i][j-1] || subset[i - ar[j-1]][j-1];
         else  subset[i][j] = subset[i][j-1];
       }
     }
     for(int j=1;j<=n;j++){


         if (sum >= ar[j-1])
           subset[sum][j] = subset[sum][j-1] || subset[sum - ar[j-1]][j-1];
         else  subset[sum][j] = subset[sum][j-1];

         if(subset[sum][j]) return true;
     }
     return subset[sum][n];
}

 int main(){

    memset(subset,false,sizeof(subset));
    memset(subset[0],true,sizeof(subset[0]));

    int N,W,Q,a,b,c,j,i,K,val;
    read(N);read(Q);
    for(int i=0;i<N;i++) read(arr[i]);
    while(Q--){

        read(a); read(b); read(c);
        switch (a){
            case 1 :  arr[b-1]=c;
            break;
            case 2 :  for(b--,c--;b<c;b++,c--)
                          swap(arr[b],arr[c]);
            break;
            default : read(W);
                for(i=b-1,j=0;i<c;j++,i++){
                    if(W==(ar[j]=arr[i]))
                     break;
                }

                if(i!=c ||  isSubsetSum(j,W))
                    printf("Yes\n");
                else printf("No\n");
            break;
            }
        }
    return 0;
}
