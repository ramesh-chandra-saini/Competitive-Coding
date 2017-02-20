#include<bits/stdc++.h>
using namespace std;


bool check_substr(string str, string str2){

   if(str.length()<str2.length()) return false;
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


        for(int i=0;i<n;i++)
            cin >> str,A.push_back(str),str.clear();
        //for(int i=0;i<n;i++) cout<<A[i]<<" "; cout<<endl;

        string ANS; ANS.clear();


        for(int i=0;i<n;i++){


            for(int j=0;j<A[i].length();j++){

                string str; str.clear();

                for(int k=j;k<A[i].length();k++){

                        str.push_back(A[i][k]);
                            //cout<<str<<"  ";

                        bool flag=true;
                        for(int x=0;x<n;x++)
                            flag  =flag & check_substr(A[x],str);
                       // cout<<flag<<endl;

                        if(flag){

                            if(ANS.empty()) ANS=str;
                            else if(str.length()>ANS.length()) ANS=str;
                            else if(str.length()==ANS.length() && ANS > str) ANS=str;
                        }
                        //cout<<ANS<<endl;
                    }
                }
            }
 //          cout<<endl;
            cout<<ANS<<endl;
     }

    return 0;
}
