#include<bits/stdc++.h>
using namespace std;
int main(){
    
    list<int> myList;
    while(true){
        int c; cin >> c;
        if(c==1){
            int n; cin >> n;
            myList.push_back(n);
        }else if(c==2){
            int n; cin >> n;
            list<int>::iterator it = myList.begin();
            it=myList.find(n);
            myList.erase(it);
        } else if(c==3){
            int n; cin >> n;
            myList.remove(n);
        }
        else break;
        for(list<int>::iterator it = myList.begin();it!=myList.end();++it) cout<<*it<<" "; cout<<endl;
    }
}
