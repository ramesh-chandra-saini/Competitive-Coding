#include<bits/stdc++.h>
using namespace std;

int main(){
    clock_t startTime=clock();
    for(int S=1;S<=10;S++){
        for(int K=1;K<=10;K++){
            cout<<"("<<K<<","<<S<<") :  ";
            cout<<"{";
            if(S==1) cout<<K<<",";
            else{
                for(int i=1;i<K&&K>=2;i++){
                    if(S==2){cout<<"{"<<i<<","<<(K-i)<<"},";}
                    for(int j=1;i+j<K&&K>=3;j++){
                        if(S==3){cout<<"{"<<i<<","<<j<<","<<(K-i-j)<<"},";}
                        for(int k=1;i+j+k<K&&K>=4;k++){
                            if(S==4){cout<<"{"<<i<<","<<j<<","<<k<<","<<(K-i-j-k)<<"},";}
                            for(int l=1;i+j+k+l<K&&K>=5;l++){
                                if(S==5){cout<<"{"<<i<<","<<j<<","<<k<<","<<l<<","<<(K-i-j-k-l)<<"},";}
                                for(int m=1;i+j+k+l+m<K&&K>=6;m++){
                                    if(S==6){cout<<"{"<<i<<","<<j<<","<<k<<","<<l<<","<<m<<","<<(K-i-j-k-l-m)<<"},";}
                                    for(int n=1;i+j+k+l+m+n<K&&K>=7;n++){
                                        if(S==7){cout<<"{"<<i<<","<<j<<","<<k<<","<<l<<","<<m<<","<<n<<","<<(K-i-j-k-l-m-n)<<"},";}
                                        for(int o=1;i+j+k+l+m+n+o<K&&K>=8;o++){
                                            if(S==8){cout<<"{"<<i<<","<<j<<","<<k<<","<<l<<","<<m<<","<<n<<","<<o<<","<<(K-i-j-k-l-m-n-o)<<"},";}
                                            for(int p=1;i+j+k+l+m+n+o+p<K&&K>=9;p++){
                                                if(S==9){cout<<"{"<<i<<","<<j<<","<<k<<","<<l<<","<<m<<","<<n<<","<<o<<","<<p<<","<<(K-i-j-k-l-m-n-o-p)<<"},";}
                                                for(int q=1;i+j+k+l+m+n+o+p+q<K&&K>=10;q++){
                                                    if(S==10){cout<<"{"<<i<<","<<j<<","<<k<<","<<l<<","<<m<<","<<n<<","<<o<<","<<p<<","<<q<<","<<(K-i-j-k-l-m-n-o-p-q)<<"},";}
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout<<"}"<<endl;
        }
        cout<<endl;
    }
    clock_t endTime=clock();
    float duration=(float) (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<duration<<endl;

    return 0;
}
