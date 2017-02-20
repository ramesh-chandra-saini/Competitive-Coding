#include <bits/stdc++.h>
using namespace std;


void Remove_Front_Zero( vector<long long int> &A){

    while(A.size()>1 && !*A.begin()) A.erase(A.begin());
}
void _reverse(vector<long long int> &A){

    long long int size=A.size(),temp;
    for(long long int i=0;i<size/2;i++){

        temp=A[i]; A[i]=A[size-1-i]; A[size-1-i]=temp;
    }
}
vector<long long int> Big_Mult(vector<long long int> &A, vector<long long int> &B){

    Remove_Front_Zero(A);
    Remove_Front_Zero(B);
    vector<long long int> _A,_B; _A.clear(); _B.clear();

    _A=(A.size()>=B.size())? A : B;
    _B=(A.size()<B.size()) ? A : B;


    _reverse(_A);
    _reverse(_B);
    vector<long long int>ans(_A.size()+_B.size(),0);

    long long int shift=0;
    long long int a=_A.size(),b=_B.size();

    for(long long int i=0;i<b;i++){

        long long int M=_B[i];
        long long int temp=0;
        long long int carry=0;
        long long int j=0;
        for( j=0;j<a;j++){

            temp+=_A[j]*M;
            carry=carry+ans[j+shift]+temp%10;
            ans[j+shift]=carry%10;
            carry/=10;
            temp/=10;
        }
        while(temp){
            carry=carry+ans[j+shift]+temp%10;
            ans[j+shift]=carry%10;
            carry/=10;
            temp/=10;
        }
        while(carry){
            carry=carry+ans[j+shift];
            ans[j+shift]=carry%10;
            carry/=10;
        }
        shift++;
    }

    _reverse(ans);
    Remove_Front_Zero(ans);
    //cout<<"";for (long long int i = 0; i < A.size(); i++) cout << A[i]; cout << " * ";
    //cout<<"";for (long long int i = 0; i < B.size(); i++) cout << B[i]; cout << " = ";
    //cout<<"";for (long long int i = 0; i < ans.size(); i++) cout << ans[i]; cout << endl;
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long int output to STDOUT */
    long long int N,T;

    cin >> T;

   vector<long long int>__ans;
   vector<long long int> __M;
   long long int __temp;
   long long int __size;

    while(T--){

        cin >> N;
        if(N==0) cout<<"1"<<endl;
        else{
            __ans.clear();
            __ans.push_back(1);

            for(;N;N--){

                __M.clear();
                __temp=N;
                while(__temp){

                    __M.push_back(__temp%10);
                    __temp=__temp/10;
                }
                _reverse(__M);
                __ans=Big_Mult(__ans,__M);

            }
            __size=__ans.size();

            long long int f_ans=0;
            for(long long int i=0;i<__size;i++)
                f_ans+=__ans[i];
            cout<<f_ans<<endl;
        }
    }
    return 0;
}
