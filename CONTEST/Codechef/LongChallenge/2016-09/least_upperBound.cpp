#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    set<int> s;
    for(int i=0,val;i<n;i++)
        cin >> val, s.insert(val);

    do{
        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            cout<<*it<<" ";
        } cout<<endl;
        int i=0;
        set<int>::iterator itBegin = s.begin();
        set<int>::iterator itEnd = s.end();
        set<int>::iterator tempIt;

        while(itBegin!=itEnd){
            ++i;
            cout<<i<<").";
            if(i%2){
                cout<<"Erase : "<<*itBegin<<endl;
                tempIt=itBegin;
                ++itBegin;
                s.erase(tempIt);
            }else{
                cout<<"Skip : "<<*itBegin<<endl;
                ++itBegin;
            }
        }
        cout<<"set.Size() : "<<s.size()<<endl;
    } while(s.size()>0);

    /*int q; cin >> q;
    while(q--){
        int value; cin >> value;
        int ub = INT_MAX;
        set<int> ::iterator it = s.lower_bound(value);
        if(it!=s.end())
            ub = *it;
        cout<<ub<<endl;

    }*/

    return 0;
}
