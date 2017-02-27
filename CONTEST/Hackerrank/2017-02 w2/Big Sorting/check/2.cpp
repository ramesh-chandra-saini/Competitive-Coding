#include <bits/stdc++.h>
using namespace std;
bool __cmp(string A,string B){
    return (A.length()!=B.length())? A.length()<B.length():A<B;
}
int main(){
    //clock_t runtime = clock();
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int i = 0; i < n; i++)
       cin >> unsorted[i];
    sort(unsorted.begin(),unsorted.end(),__cmp);
    for(int i = 0; i < n; i++)
       cout<<unsorted[i]<<endl;
    //runtime = clock()-runtime;
    //printf("%.9f\n",double(runtime*1.0)/CLOCKS_PER_SEC);
    return 0;
}
