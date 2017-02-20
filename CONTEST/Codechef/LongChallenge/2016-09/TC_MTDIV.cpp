#include<bits/stdc++.h>
using namespace std;
#define A 100
int main(){
    int n=50,k=25;
    srand(time(NULL));
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            printf("%d ",1+rand()%A);
        } printf("\n");
    }
}
