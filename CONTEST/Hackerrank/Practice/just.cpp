
#include<bits/stdc++.h>
using namespace std;

int main(){


    int T;

    cin >> T;

    while(T--){

        string str;
        char c=getchar_unlocked();

        if(c=='\n') c=getchar_unlocked();
       do{

            str.push_back(c);
            c=getchar_unlocked();
        } while(c!='\n');

        int len=str.length();
        string comp("hackerrank");
        //cout<<comp<<endl;
        //cout<<str<<endl;

        if(str.length()<comp.length()) cout<<"-1"<<endl;
        else{

            int start=0,end=0;

            for(int i=0;i<comp.length();i++){

                if(str[i]!=comp[i]) start=-1;
            }
            for(int i=str.length()-1, j=comp.length()-1; i>=0 && j>=0;i--,j--){

                if(str[i]!=comp[j]) end=-1;
            }
            if(start ==0 &&  end==0) cout << "0" <<endl;
            else if(start==0) cout<<"1"<<endl;
            else if(end==0) cout<<"2"<<endl;
            else cout<<"-1"<<endl;
        }
    }

    return 0;
}
