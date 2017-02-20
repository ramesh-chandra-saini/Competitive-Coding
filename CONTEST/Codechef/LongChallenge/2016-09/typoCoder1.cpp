#include<bits/stdc++.h>
using namespace std;
int main(){
    //clock_t startTime = clock();
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);;//cin >> arr[i];
        vector<multiset<int> > s;
        for(int i=0;i<n;i++){
            bool inserted=false;
            int j=0;
            for(vector<multiset<int> >::iterator it=s.begin();it!=s.end();++it,j++){
                    bool flag=true;
                for(multiset<int> :: iterator sit=(*it).begin();sit!=(*it).end();++sit){
                    int value=*sit;
                    if((value & arr[i]) == value || (value & arr[i]) == arr[i]){
                        flag=false; break;
                    }
                }
                if(flag){
                    s[j].insert(arr[i]);
                    inserted=true;
                    break;
                }
            }
            if(!inserted){
                multiset<int> newSet; newSet.insert(arr[i]);
                s.push_back(newSet);
            }
        }
       printf("%d\n",s.size());
    }
    /*
    clock_t endTime = clock();
    double duration = (float)(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"RUNTIME : "<<duration<<endl;
    */
    return 0;
}
