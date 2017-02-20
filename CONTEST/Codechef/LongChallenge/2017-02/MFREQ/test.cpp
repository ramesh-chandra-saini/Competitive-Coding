#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    int n,m;
    n = 1+rand()%10;
    m = 1+rand()%10;
    cout << n << " " << m << endl;
    for(int i=0;i<n;i++)
        cout<<(rand()%10)<<" "; cout<<endl;
    while(m--){
        int l,r;
        l = 1+rand()%n;
        r = 1+rand()%n;
        if(l>r)
            swap(l,r);
        int k;
        do{
            k = 1+rand()%(r-l+1);
        } while(2*k<r-l+1);
        cout<<l<<" "<<r<<" "<<k<<endl;
    }
}
