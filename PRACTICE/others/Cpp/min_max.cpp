
#include<bits/stdc++.h>
using namespace std;
bool isPalin(string &A){

    for(int i=0;i<A.length();i++)
        if(A.at(i)!=A.at(A.length()-1-i))
            return false;
    return true;
}
int main(){

    int t;
    cin >> t;


    long long int N,A,B;
    while(t--){


        cin >> N>>A >> B;
        vector<long long int> s(N),str;
        for(int i=0;i<N;i++)
            cin>>s[i];

        int l=s.size();
        long long int P=pow(2,l),ans=0;
        for(long long int i=1;i<P;i++){

            long long int temp=i,j=0;
            str.clear();
            while(temp){

                if(temp%2) str.push_back(s.at(j));
                temp/=2,++j;
            }

 //           for(int a=0;   a< str.size();a++)cout<<str[a]<<" "; cout<<endl;
            if(str.size()>=3){
                long long int m=0,M=0;
                for(long long int u=1;u<str.size()-1;u++){

                    if(str[u-1]>str[u] && str[u]<str[u+1]) m++;
                    if(str[u-1]<str[u] && str[u]>str[u+1]) M++;
                }
                if(A==m && B==M) ans++;
            }else if(A==0 && B ==0) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
