#include<bits/stdc++.h>
using namespace std;


bool check_substr(string str, string str2){

    for(int i=0;i<str.length();i++){

        int ct=0;
        for(int j=0,k=i; j<str2.length() && k<str.length() ; j++,k++){

            if(str[k]!=str2[j]) break;
            else ct++;
        }
        if(ct==str2.length()) return true;
    }
    return false;

}
int main(){


    int t;

    cin >> t;

    while(t--){


        int n;

        cin >> n;

        vector<string > A; A.clear();
        string str;


        for(int i=0;i<n;i++){

            cin >> str;
            A.push_back(str);
            str.clear();
        }
        sort(A.begin(),A.end());

        int idx=0,len=INT_MAX;
        for(int i=0;i<n;i++){

            if(A[i].size()<len){

                len=A[i].size();
                idx=i;
            }
        }

        string P(A[idx]);
        vector<string> ans; ans.clear();

        for(int i=0;i<len;i++){

                str.clear();
                for(int j=i;j<len;j++){

                    str.push_back(P[j]);

                    bool flag=true;

                    cout<<str<<endl;
                    for(int k=0;k<n;k++){

                        flag=check_substr(A[i],str);
                    }

                    if(flag) ans.push_back(str);
                }
        }

        sort(ans.begin(),ans.end());

         len=INT_MIN;
         cout<<ans.size();
          idx=0;
        for(int i=0;i<ans.size();i++){

            if(len<ans[i].length()){
                idx=i;
                len=ans[i].size();
            }
        }
        cout<<len<<endl;
        cout<<ans[idx]<<endl;
    }


    return 0;
}
