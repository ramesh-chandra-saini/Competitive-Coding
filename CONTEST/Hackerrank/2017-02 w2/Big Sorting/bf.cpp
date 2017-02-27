#include <bits/stdc++.h>
using namespace std;
bool __cmp(string A,string B){
    return A<=B;
}
int main(){
    int n=21;
    vector<string> vec(n);
    for(int i = 0; i < n; i++)
       vec[i]="2";
    sort(vec.begin(),vec.end(),__cmp);
    for(int i = 0; i < n; i++)
       cout<<vec[i]<<endl;
    return 0;
}
