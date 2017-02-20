#include<bits/stdc++.h>
using namespace std;

int main(){

    int N;

    cin >> N;

    vector<int> final_list;
    for(int i=0;i<=N;i++){

        int n=i,j=n-1,ans=0;
        for(;j>1;j--){

            int ps=n*n-j*j;
            int _ps=sqrt(ps);

            if(_ps*_ps==ps){

                //cout<<_ps<<"^2 + "<<j<<"^2 = "<<n<<"^2"<<endl;
                ans=n;
                break;
            }
        }
        if(ans){
            int size=final_list.size();
            bool flag=true;

            for(j=0;j<size;j++){

                if(n%final_list[j]==0){

                    flag=false;
                    break;
                }
            }
            if(flag) {final_list.push_back(n);
            cout<<n<<",";}
        }
    }

    //for(int i=0;i<final_list.size();++i) cout<<final_list[i]<<" "; cout<<endl;
    cout<<endl<<final_list.size()<<endl;

    return 0;
}
