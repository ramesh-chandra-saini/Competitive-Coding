#include<bits/stdc++.h>
using namespace std;

#define N 200000
#define DIGITS 2000000
#define MAX_DIGIT 10000

/*
#define N 2000
#define DIGITS 200000
#define MAX_DIGIT 1000
*/
int main(){
    srand(time(NULL));
    int n = 1+rand()%N;
    printf("%d\n",n);
    int digits = DIGITS;
    //Total number of digits 2*10^6(approx)
    //max digit in one string 10000
    for(int i=0;i<n;i++){
        int digit = 1+rand()%digits;
        digit = (digit>MAX_DIGIT)?MAX_DIGIT:digit;
        digits = max(2,digits-digit);
        for(int j=0;j<digit;j++){
            if(j==0)
                printf("%d",1+rand()%9);
            else
                printf("%d",rand()%10);
        }
        printf("\n");
    }
    return 0;
}
