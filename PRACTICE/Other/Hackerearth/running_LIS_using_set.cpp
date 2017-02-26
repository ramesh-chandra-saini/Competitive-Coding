#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> lis_arr;
set<int> lis_set;
set<int>::iterator it;
void insert(int x){
    arr.push_back(x);
    if(lis_set.find(x)==lis_set.end()){
        lis_set.insert(x);//first push x
        it=lis_set.find(x);//get the upper bound for this number
        it++;
        if(it!=lis_set.end()){ //if upper bound exist in lis set
            //greater than element present in lis set
            lis_arr.push_back(*it);//remember what you erased
            lis_set.erase(it);//erase upper bound
        }else{
            lis_arr.push_back(-1);//just pushed to last
        }
    }else{
        //element is already present in lis set
        lis_arr.push_back(x);
    }
}
void erase(){
    if(lis_arr.back()==-1){
        lis_set.erase(arr.back());
    }else{
        lis_set.erase(arr.back());
        lis_set.insert(lis_arr.back());
    }
    lis_arr.pop_back();
    arr.pop_back();
}
void print(set<int>lis_set){
    for(it=lis_set.begin();it!=lis_set.end();++it)
        cout<<*it<<" "; cout<<endl;
}
void print(vector<int>vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" "; cout<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    int N,Q;
    scanf("%d%d",&N,&Q);

    for(int i=0,x;i<N;i++){
        cin >> x;
        insert(x);//,print(arr),print(lis_arr),print(lis_set),cout<<endl;
    }
    while(Q--){
        int type,x;
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&x);
            insert(x);
        }
        else{
            erase();
        }//print(arr),print(lis_arr),print(lis_set),cout<<endl;
        printf("%d\n",lis_set.size());
    }
}
