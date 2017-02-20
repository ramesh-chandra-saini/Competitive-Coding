#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int T = 1+rand()%50;
    cout<<T<<endl;
    while(T--){
        int N = 1+rand()%5;
        int M = 1+rand()%5;
        int K = 1+rand()%5;
        int P = rand()%K;
        cout<<N<<" "<<M<<" "<<P<<" "<<K<<endl;
    }

}
