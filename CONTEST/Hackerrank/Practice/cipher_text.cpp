#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N,K,i;
    cin >> N >> K;

    string str;
    cin >> str;

    vector<bool> cipher; cipher.clear();

    int len=str.length();
    for(i=0;i<len;i++) cipher.push_back( bool(str.at(i)-'0') );
    //for(i=0;i<len;i++) cout<<cipher.at(i); cout<<endl;

    int cumm_xor;
    vector<bool> ans; ans.clear();
    //As we know first character is same as given

    ans.push_back(cipher.at(0));
    cumm_xor=cipher.at(0);


    for(i=1;i<K && i<N;i++){

        ans.push_back( cumm_xor xor cipher.at(i));
        cumm_xor=cumm_xor xor ans.at(i);
    }

    for(;i<N;i++){

        cumm_xor=cumm_xor xor ans.at(i-K);
        ans.push_back( cumm_xor xor cipher.at(i));
        cumm_xor=cumm_xor xor ans.at(i);
    }

    for(int i=0;i<N;i++)
        cout<<ans.at(i); cout<<endl;
    return 0;
}
