/*
    RAMESH CHANDRA 2 OCT 2015
    NATIONAL INSTITUTE OF TECHNOLOGY
    KARNATAKA SURATHKAL
    https://www.facebook.com/rameshc10695

*/

#include<bits/stdc++.h>
using namespace std;

int main(){


    int t;
    //scanf("%d",&t);
    cin >>t;

    int H,M, total=720; ///total Possible minute
    float angle,H_angle,M_angle,check;
    float error=0.00833333,_360=(float)360,_0=(float)0,_6=6.00;
    //cout<<error<<endl;
    while(t--){

        //scanf("%f",&angle);
        cin>>angle;
        H_angle=_0; M_angle=_0;
        for(int i=0;i<total;i++){


            H_angle=double(i)/double(2);
            M_angle=double(i%60)*double(6);
            check=abs(H_angle-M_angle);

            check=min(check,_360-check);
            H=i/60; M=i%60;
           // cout<<i/60<<":"<<i%60<<" = "<<abs(H_angle-M_angle)<<","<<H_angle<<" "<<M_angle<<" =="<<check<<endl;
            if(abs(check-angle)<=error){

                //cout<<H<<":"<<M<<endl;
              //printf("%.2d:%.2d\n",H,M);
              cout<<(H/10)<<(H%10)<<":"<<(M/10)<<(M%10)<<endl;
            }
        }
    }
    return 0;
}
