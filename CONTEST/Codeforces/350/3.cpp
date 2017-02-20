/**

    RAMESH CHANDRA
    NATIONAL INSTITUTE OF TECHNOLOGY KARNATKA SURATHKAL
**/
#include<bits/stdc++.h>
using namespace std;
vector<string> S;
bool __cmp(const string &A, const string &B){

    if(A+B<=B+A) return true;
    return false;
}
int main(){

   int n,l=0;
   cin >> n;
   string s; s.clear(); S.clear();
   for(int i=0;i<n;i++)
    cin >> s,S.push_back(s);
    sort(S.begin(),S.end(),__cmp);
    for(int i=0;i<n;i++)
        cout<<S[i]; cout<<endl;
    return 0;
}
