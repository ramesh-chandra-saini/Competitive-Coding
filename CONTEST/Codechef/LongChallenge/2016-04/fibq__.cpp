/*
    Author : Ramesh Chandra
    National Institute Of Technology Karnataka Surathkal
    10 Apr 2016
    Best Problem Ever Solved....Real Happiness comes when such kind of question..got 100pts
    Basic Idea
    subset(a,b) =  ( (I+A^a)(I+A^b)-I )*A^(-1)
    Data Structure : Binary Inedexed Tree
    Space Complexity : O(N);
    Time Complexity : O(MlogN);
    Happiness cannot explained in words...spend one whole day of crucial time...
    Loveliest Problem....Thanks to problem setter
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll unitMat[2][2]={{1,0},{0,1}};
ll fibMat[2][2]={{1,1},{1,0}};
ll invMat[2][2]={{0,1},{1,-1}};
ll result[2][2];
ll   arrN[100005][2][2];
ll    BIT[100005][2][2];

#define gc getchar_unlocked
using namespace std;
typedef ll INT;
inline void read(ll &x){ //read input
	register INT c = gc(); x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
inline void write( ll a){//write output
    char snum[35];
    ll i = 0;
    do{
        snum[i++] = a%10 +48;
        a = a/10;
    }while(a!= 0);
    --i;    while(i>=0) putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
}
void prArr(ll A[2][2]){//print Arr
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
            cout<<A[j][k]<<" ";
        } cout<<endl;
    } cout<<endl;
}
void copyMat(ll A[2][2],ll B[2][2]){//copy matrix
  A[0][0]=B[0][0],A[0][1]=B[0][1],A[1][0]=B[1][0],A[1][1]=B[1][1];
}
void addMat(ll A[2][2],ll B[2][2],ll res[2][2]){//add matrix
    res[0][0] = (A[0][0] + B[0][0])%mod;
    res[1][0] = (A[1][0] + B[1][0])%mod;
    res [0][1]= (A[0][1] + B[0][1])%mod;
    res[1][1] = (A[1][1] + B[1][1])%mod;
}
void multMat(ll A[2][2],ll B[2][2],ll res[2][2]){//multiply matrix
    res[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%mod;
    res[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%mod;
    res[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%mod;
    res[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%mod;
}
void powMat(ll N[2][2],ll ans[2][2],ll pow){//calculate |mat|^pow in order to get fibonacci nnumber
    for(copyMat(ans,unitMat);pow;pow>>=1){
        if(pow&1)
            multMat(N,ans,result),copyMat(ans,result);
        multMat(N,N,result),copyMat(N,result);
    }
}
ll fastExpo(ll N,ll pw){//fast expo required in calculation of A^(-1)
    ll ans=1LL;
    for(;pw;pw>>=1){
        if(pw&1) ans=(ans*N)%mod;
        N=(N*N)%mod;
    }  return ans;
}
void _getSum(ll index,ll queryAns[2][2]){//get multiplicatin of matrix from 1 to index
    copyMat(queryAns,unitMat); ll temp[2][2];
    while(index>0){
        multMat(BIT[index],queryAns,temp); copyMat(queryAns,temp);
        index=index-( index & -index );
    } return;
}
void _update(ll n,ll index,ll value[2][2]){//update BIT entry using new value
    if(index<=0) return ; ll temp[2][2];
    while(index<=n){
        multMat(BIT[index],value,temp); copyMat(BIT[index],temp);
         index=index+( index & -index);
    }    return;
}
void getINV(ll A[2][2], ll invMatrix[2][2]){//get inverse of matrix
    ll K = ( (A[0][0]*A[1][1]+mod)%mod-(A[1][0]*A[0][1]+mod)%mod+mod)%mod; //cout<<"K :: "<<K<<endl;
    invMatrix[0][0]=A[1][1];     invMatrix[0][1]=mod-A[0][1];
    invMatrix[1][0]=mod-A[1][0]; invMatrix[1][1]=A[0][0];
    ll invMod= fastExpo(K,mod-2);
    invMatrix[0][0]= (invMatrix[0][0]*invMod+mod)%mod;
    invMatrix[1][0] =(invMatrix[1][0]*invMod+mod)%mod;
    invMatrix[0][1]= (invMatrix[0][1]*invMod+mod)%mod;
    invMatrix[1][1] =(invMatrix[1][1]*invMod+mod)%mod;
}
int main(){//driver program
   ll n,m,val;    read(n); read(m);
   ll  N[2][2],res[2][2],sum[2][2];
    for(int i=0;i<=100000;i++){//intialized all required matrix with unitMatrix of Multiplication
           copyMat(BIT[i],unitMat);
           copyMat(arrN[i],unitMat);
    }
   for(ll i=1;i<=n;++i){//now calculate fibonacci number and build BIT
        read(val); copyMat(N,fibMat);
        powMat(N,arrN[i],val); //prArr(arrN[i]); //cout<<(arr[i])<<")."<< An[0][0]<<endl;
        addMat(unitMat,arrN[i],arrN[i]);
        _update(n,i,arrN[i]);
   }
 // checkerSum(n);
   register INT c; ll x,y;
   while(m--){//print ans for Judge
       c = gc(); for(;(c!=67&& c!=81);c = gc());//scan choice
        read(x); read(y);
        if(c==67) {//update BIT
            ll invPrevValue[2][2]; getINV(arrN[x],invPrevValue);//get inverse of current value of arrN[x]
            _update(n,x,invPrevValue); //remove old value from all entry
            copyMat(N,fibMat); powMat(N,arrN[x],y);//get new arrN[x]
            addMat(unitMat,arrN[x],arrN[x]);//get new arrN[x] and add unit matrix also
            _update(n,x,arrN[x]);//update BIT with new value
        }
        else{//get Required sum in given range
             ll RSum[2][2];_getSum(y,RSum);//get multiplication from 1 to y
            ll LSum[2][2]; _getSum(x-1,LSum);//get multiplication from 1 to x-1
            ll invLSum[2][2];getINV(LSum,invLSum);
            ll answer[2][2];
            multMat(invLSum,RSum,answer);
            write(answer[0][1]); //final answer to judge..
        }
   }
    return 0;//the end
}
