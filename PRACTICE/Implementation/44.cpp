#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum; cin >> n >> sum;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    int ans=0;
    set< pair<set<int>,set<int> > > superSet;
    for(int i=1;i<pow(2,n);i++){
        int sumI=0;
        set<int> iSet;
        for(int temp=i,id=0;temp;temp/=2,id++){
            sumI+=(temp%2)?arr[id]:0; iSet.insert(id);
        }
        if(sumI>=sum){
            for(int j=1;j<pow(2,n);j++){
                    int sumJ=0;
                    set<int>jSet;
                    for(int temp=j,id=0;temp;temp/=2,id++){
                        sumJ+=(temp%2)?arr[id]:0;jSet.insert(id);
                    }
                    for(set<int>::iterator it=iSet.begin();it!=iSet.end();++it){
                        if(jSet.find(*it)!=jSet.end())
                            continue;
                    }
                    if(sumJ>=sum)
                        superSet.insert(make_pair(iSet,jSet));
            }
        }
    } cout<<superSet.size()<<endl;
    return 0;
}
