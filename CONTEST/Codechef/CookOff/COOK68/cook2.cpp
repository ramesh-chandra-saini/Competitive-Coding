#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int H,M;
        cin >> H >> M;
        int ans=0;
        for(int i=0;i<H;i++){
            for(int j=0;j<M;j++){

                int h=i,m=j;
                vector<int> freq(10,0);
                do{
                    freq[(h%10)]++;h/=10;
                } while(h);
                do{
                    freq[(m%10)]++;m/=10;
                } while(m);
                int ct=0;
                for(int d=0;d<10;d++)
                    if(freq[d]) ct++;
                ans+=(ct==1)?1:0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
