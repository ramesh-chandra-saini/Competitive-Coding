#include<bits/stdc++.h>
using namespace std;

void printSet(set<int>&ans){
 for(set<int>::iterator it = ans.begin();it!=ans.end();++it){
                printf("%d ",*it);
            }
            printf("\n");
}
#define N 10000
vector<bool> primeList(N+1,true);
void seive(){
    primeList[0]=primeList[1]=false;
    for(int i=2;i*i<=N;i++){
        if(primeList[i]){
            for(int j=i*i;j<=N;j+=i){
                primeList[j]=false;
            }
        }
    }
}
vector<int> numOfPrimeFactors(N+1,0);
void getNumOfFactor(){
    numOfPrimeFactors[0]=0;
    for(int i=1;i<=N;i++){
        set<int> factorList; factorList.clear();
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                factorList.insert(j);
                factorList.insert(i/j);
            }
        }
        //cout<<i<<" : "; printSet(factorList);
        numOfPrimeFactors[i]=factorList.size();
    }
}
int main(){
    seive();
    getNumOfFactor();
    int t; scanf("%d",&t); while(t--){
        int L,H; scanf("%d%d",&L,&H);
        set<int> ans;
        for(int i=L;i<=H;i++){
            if(primeList[numOfPrimeFactors[i]]){
                ans.insert(i);
            }
        }
        if(ans.size()){
                printSet(ans);
        } else{
            printf("-1\n");
        }
    } return 0;
}
