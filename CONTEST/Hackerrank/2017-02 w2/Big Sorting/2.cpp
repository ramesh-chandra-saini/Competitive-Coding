#include <bits/stdc++.h>
using namespace std;
bool __cmp(string A,string B){
    return (A.length()!=B.length())? A.length()<B.length():A<B;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int i = 0; i < n; i++)
       cin >> unsorted[i];
    sort(unsorted.begin(),unsorted.end(),__cmp);
    for(int i = 0; i < n; i++)
       cout<<unsorted[i]<<"\n";
   return 0;
}
