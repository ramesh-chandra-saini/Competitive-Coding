#include<bits/stdc++.h>
using namespace std;
int main(){

    int t; t=rand()%10+1; cout<<t<<endl;
    while(t--){
        int n=rand()%100+1,m=rand()%100+1,k1=rand()%10+1,k2=rand()%10+1; cout<<n<<" "<<m<<" "<<k1<<" "<<k2<<endl;
        for(int i=0;i<n;i++,cout<<endl)
            for(int j=0;j<m;j++)
                if( (i==0 && j==0) || (i==0 && j==m-1) ) cout<<"0"<<" ";
                else cout<< (rand()%2)<<" ";
        cout<<endl;
    }
    return 0;
}
