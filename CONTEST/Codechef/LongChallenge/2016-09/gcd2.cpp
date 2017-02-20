#include<bits/stdc++.h>
using namespace std;
    int toti[100], totiS[100];
void compute(int MAX){

    int i, j, k, ans;
    for(i = 0;i < MAX;++i)   toti[i] = i;
    for(i = 2;i < MAX;++i) {
        if(toti[i] == i){
            toti[i] = i - 1;
            for(j = 2*i;j < MAX;j += i)
                toti[j] -= (toti[j] / i);
        }
    }
                for(int i=1;i<MAX;i++) cout<<i<< " "; cout<<endl;
    for(int i=1;i<MAX;i++) cout<<toti[i]<< " "; cout<<endl;
    for(i = 1;i < MAX;++i)
        for(j = i, k = 1;j < MAX;j += i, k++)
            totiS[j] += i*toti[k];
    for(int i=1;i<MAX;i++)   cout<<totiS[i]<<" "; cout<<endl;
}

void compute2(int MAX){
int toti[100], totiS[100];memset(toti,0,sizeof(toti)); memset(totiS,0,sizeof(totiS));
    int i, j, k, ans;
    for(i = 0;i < MAX;++i)   toti[i] = i;
    for(i = 2;i < MAX;++i) {
        if(toti[i] == i){
            toti[i] = i - 1;
            for(j = 2*i;j < MAX;j += i)
                toti[j] -= (toti[j] / i);
        }
    }
            for(int i=1;i<MAX;i++) cout<<i<< " "; cout<<endl;
    for(int i=1;i<MAX;i++) cout<<toti[i]<< " "; cout<<endl;
    for(i = 1;i < MAX;++i)
        for(j = i, k = 1;j < MAX;j += i, k++)
            totiS[j] += k/i*toti[k];
    for(int i=1;i<MAX;i++)   cout<<totiS[i]<<" "; cout<<endl;
}
int fun(int n){

    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=(i/__gcd(i,n));
    }
    return ans;
}
int main(){
    clock_t start = clock();
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cout<<fun(i)<<" ";
    } cout<<endl;
    clock_t end = clock();
    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<duration<<endl;
    compute(n+1);
    compute2(n+1);

}
