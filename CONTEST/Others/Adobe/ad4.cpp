#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

string Remove_Zero(string A){

    while(A.length()>1 && A.at(0)=='0') A.erase(A.begin());

    return A;
}

string __reverse(string A){

    int L=A.length();
    for(int i=0;i<L/2;i++){
        char c=A.at(i);A.at(i)=A.at(L-1-i);A.at(L-1-i)=c;
    }
    return A;
}

string __mod(string A){

    long long int K=0,D;
    int len=A.length();
    long long int ct=0;
    for(int i=0;i<len;i++){

        if(A.at(i)=='0') ct++;
        else break;
    }

    for(int i=0;i<len;i++){

        K=K*10+(A.at(i)-'0');
        D=K/mod;
        K=K-(D*mod);
    }
    string B;B.clear();
    while(K){
        B=B+char(K%10+'0'); K/=10;
    }

    B=__reverse(B);

    if(ct){
        string zero(ct,'0');
        B=zero+B;
    }
    if(B.empty())B.push_back('0');

    return B;
}

int main(){

    long long int N;
    cin >> N;

    vector<string> arr(N);

    for(long long int i=0;i<N;i++){
        cin >> arr[i];
    }

    long long int Q;
    cin >> Q;

    long long int q,idx,L,R;
    string P;
    string reply;

    while(Q--){

            cin >> q;

            if(q==1){
                cin >> idx >> P;
                arr[idx-1]=P;
            }
            else{

              cin >> L >> R;
                L--; R--;
                reply.clear();
                for(long long int i=L;i<=R;i++){
                    reply+=arr[i];
                }
                cout<<Remove_Zero(__mod(reply))<<endl;
            }
    }
    return 0;
}
