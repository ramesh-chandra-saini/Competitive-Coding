#include <bits/stdc++.h>
using namespace std;
vector<int> cumm(200005,0);
vector<int>    a(200005,0);
int solve(int a,int b,string &A,string &B){
    if(a==0 && b==0){ //both the string matched
        return 1;
    }else if(a==0 && b!=0){ // B string has some unmatched character
        return 1;
    }else if(a!=0 && b==0){ // B is traversed fully, i
        if(isupper(A[a])) //uppercase(A[a-1]) then 0
            return 0;
        else               //simply erase A[a-1]
            return solve(a-1,b,A,B);
    }else{

        if(islower(B[b])){
            if(islower(A[a])){
                int ans = 0;
                //skip --> because A[a-1] is lower and can be deleted
                ans = max(ans,solve(a-1,b,A,B));
                //if both char match
                if(A[a]==B[b])
                    ans = max(ans,solve(a-1,b-1,A,B));
                return ans;
            }else{
                int ans = 0;
                //cant skip
                //no matching also
                return ans;
            }
        }else if(isupper(B[b])){
            if(islower(A[a])){
                int ans = 0;
                //skip --> because A[a-1] is lower and can be deleted
                ans = max(ans,solve(a-1,b,A,B));
                //if both char match
                if(A[a]==B[b])
                    ans = max(ans,solve(a-1,b-1,A,B));
                //A[i] also can be converted to upper
                if(toupper(A[a])==B[b])
                    ans = max(ans,solve(a-1,b-1,A,B));
                return ans;
            }else{
                int ans = 0;
                //cant skip
                //if both char match
                if(A[a]==B[b])
                    ans = max(ans,solve(a-1,b-1,A,B));
                return ans;
            }
        }
    }
}
int main(){

    int t; cin >> t;
    while(t--){
        string A,B; cin >> A >> B;
        int a = A.length(),b=B.length();
        A.insert(A.begin()+0,'#'),B.insert(B.begin()+0,'#');
        int ans = solve(a,b,A,B);
        //cout<<A<<" "<<B<<endl;
        (ans==1)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}
