#include<bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;

    while(T--){

        string A;
        cin >> A;

        vector<string> sub;
        string subhelper;
        for(int i=0;i<A.length();i++){
            subhelper.clear();
            for(int j=i;j<A.length();j++){
                subhelper+=A.at(j);
                sub.push_back(subhelper);
            }
        }
        for(int i=0;i<sub.size();i++)
            sort(sub.at(i).begin(),sub.at(i).end());
        sort(sub.begin(),sub.end());

        int ans=0;
        for(int i=0;i<sub.size();){

            string prev=sub.at(i);
            int freq=0;
            while(i<sub.size() && prev==sub.at(i)) freq++,i++;
            ans+=((freq-1)*freq)/2;
        }
        cout<<ans<<endl;
        //for(int i=0;i<sub.size();i++) cout<<sub.at(i)<<endl;
    }


    return 0;
}
