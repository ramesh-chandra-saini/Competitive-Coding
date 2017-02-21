#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    set<int> st;
    int temp = n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        st.insert(-x);
        for(;;){
            if(!st.empty() && abs(*st.begin())>=temp){
                int curr = *st.begin();
                cout<<abs(curr)<<" ";
                st.erase(curr);
                temp--;
            }else{
                break;
            }
        }
        cout<<endl;
    }
}
