#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,n;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        bool ans=false;
        bool stop=false;
        while(stop==false ){
            int cal=0;
            for(int i=0;i<arr.size();i++)
               cal=cal^arr[i];
            if(cal== 0){
                stop=true; //xor zero
            } else{
                bool action=false;
                for(int i=0;i<arr.size() && action == false;i++){
                    if((cal^arr[i]) != 0){
                        arr.erase(arr.begin()+i);action=true;ans=ans^true;
                    }
                }
                if(action == false){
                    arr.erase(arr.begin()); action=true;ans=ans^true;
                }
            }
        }
        if(ans==false) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}
