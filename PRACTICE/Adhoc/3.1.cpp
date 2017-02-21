#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    double determinant,x1,x2,hypo,area,pro,sum;
    long long t,flag;
    scanf("%lld",&t);
    while(t--){
    flag=0;
    scanf("%lf",&hypo);
    scanf("%lf",&area);
    pro=area*2;
    sum=sqrt((hypo*hypo)+2*pro);
    determinant = sum*sum - 4*1*pro;
//printf("%lf %lf is sum,determinant\n",sum,determinant);
    if(determinant<0) printf("-1\n");
    else{
        x1 = (sum + sqrt(determinant)) / (2*1.0);
        x2=sum-x1;
        printf("%lf %lf %lf\n",x2,x1,hypo);
    }
    }
return 0;
}
