#include <bits/stdc++.h>

using namespace std;
bool __cmp(string A,string B){
    if(A.length()!=B.length())
        return A.length()<B.length();
    return A<=B;
}
int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int i = 0; i < n; i++){
       cin >> unsorted[i];
        //while(unsorted[i].size()>1 && unsorted[i][0]=='0')
            //unsorted[i].erase(unsorted[i].begin());
    }
    sort(unsorted.begin(),unsorted.end(),__cmp);
    for(int i = 0; i < n; i++)
       cout<<unsorted[i]<<endl;
    return 0;
}
