#include<bits/stdc++.h>
using namespace std;

int main(){

	int size;
	cout<<"Total number of balls : ";
	cin>>size;

	int ball[size];
	/// assumption red=0; blue=1; green=2;

     int put[size];
    for(int i=0;i<size;i++){

		cin>>ball[i];
    }
    int r=0;
    int g=size-1;
    int b=g-1;

    for(int i=0;i<size;i++){

        if(ball[i]==0) put[r++]=0;
        else if(ball[i]==2){

			if(put[g]==1) put[b--]=1;
			put[g--]=2;
        }
        else put[b--]=1;
    }
    for(int i=0;i<size;i++) cout<<put[i]<<" "; cout<<endl;
    return 0;
}