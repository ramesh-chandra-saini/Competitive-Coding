#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<string> P(8); P.clear();
    for(int i=0;i<8;i++)
        cin >> P[i];

   int __W=10;
   for(int i=0;i<8;i++){

        for(int j=0;j<8;j++){

            if(P[j][i]=='B') break;
            else if(P[j][i]=='W'){

                    //cout<<j<<" ";
                __W=min(__W,j); break;
            }
        }
   }
   //cout<<endl;

   int __B=10;
   for(int i=0;i<8;i++){

        for(int j=8-1,K=0;j>=0;j--,K++){

            if(P[j][i]=='W') break;
            else if(P[j][i]=='B'){
                    //cout<<K<<" ";
                __B=min(__B,K); break;
            }
        }
   }
 //cout<<endl;
 // cout<<__W<<" "<<__B<<endl;


   if(__W<=__B) cout<<"A"<<endl;
   else cout<<"B"<<endl;
    return 0;
}
