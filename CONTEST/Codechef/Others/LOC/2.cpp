#include<bits/stdc++.h>
using namespace std;
#define MAX 471779
#define SIZE 112345
//#define int long long int
vector<int>prime;
vector<bool> primeChecker(MAX,true);
//store aint prime number
void seive(){
    primeChecker[0]=primeChecker[1]=false;
    for(int i=2;i*i<=MAX;i++)
        if(primeChecker[i])
            for(int j=i*i;j<MAX;j+=i)
                primeChecker[j]=false;
    for(int i=2;i<MAX;i++)
        if(primeChecker[i])
            prime.push_back(i);
}
//check square free numbers
void squareFreeChecker(vector<bool>&squareFree){
    for(int i=1;i<SIZE;i++)
        for(int j=2;j*j<=i;j++)
            if(i%(j*j)==0)
                squareFree[i]=false;
}
//store sum of divisiors
void getSumOfDivisior(vector<int>&sumOfDivisior){
        for(int i=1;i<SIZE;i++){ int j = 1;
            for(;j*j<i;j++)
                if(i%j==0)
                    sumOfDivisior[i]+=j+(i/j);
            if(j*j==i)
                sumOfDivisior[i]+=j;
        }
}
//get number of prime factors
void getNumberOfPrimeFactors(vector<int>&numberOfFactors,vector<int>&sumOfDivisior){
    for(int j=1;j<SIZE;j++){
        int ans=!(sumOfDivisior[j]%2),N=sumOfDivisior[j];
            while (N%2 == 0) N = N/2;
        for (int i = 3; i <= sqrt(N); i = i+2){
            ans+=!(N%i);
            while (N%i == 0)
                N = N/i;
        }
        if(N>2)
            ans++;
        numberOfFactors[j]=ans;
    }
}
//check good numbers
void goodNumberChecker(vector<bool> &goodNumber,vector<int>&numberOfFactors,vector<bool>&squareFree){
    for(int i=0;i<SIZE;i++)
        if(squareFree[i] and primeChecker[numberOfFactors[i]])
            goodNumber[i]=true;
}
//pre processing to improve complexity
void preprocessing(vector<int>&ans,vector<bool>&goodNumber,vector<int>&sumOfDivisior){
      for(int i=1;i<SIZE;i++)
        ans[i]=(goodNumber[i])?ans[i-1]+sumOfDivisior[i]:ans[i-1];
}
//main driver function
int main(){
    seive();
    vector<bool> squareFree(SIZE,true);  squareFreeChecker(squareFree);
    vector<int> sumOfDivisior(SIZE,0);   getSumOfDivisior(sumOfDivisior);
    vector<int> numberOfFactors(SIZE,0); getNumberOfPrimeFactors(numberOfFactors,sumOfDivisior);
    vector<bool> goodNumber(SIZE,false); goodNumberChecker(goodNumber,numberOfFactors,squareFree);
    vector<int> ans(SIZE,0); preprocessing(ans,goodNumber,sumOfDivisior);
    int t; scanf("%d",&t);
    while(t--){
        int L,R; scanf("%d%d",&L,&R);printf("%d\n",ans[R]-ans[L-1]);
    }
    return 0;
}
