#include<bits/stdc++.h>
using namespace std;

int _getSum(int *_bit,int index){

    index=index+1;

    int sum=0;
    while(index>0){

        sum+=_bit[index];
        index=index-(index & -index);
    }
    return sum;
}
void _update(int *bit,int size,int index,int value){

    index=index+1;//convert 0-based index to 1-based index..

    while(index<=size){

        bit[index]+=value;
        index=index+(index & -index);
    }
    return;
}
int * createBit(int *A,int size){

    int *bit=(int*)malloc((size+1)*sizeof(int));

    for(int i=0;i<=size;i++)
        bit[i]=0;

    for(int i=0;i<size;i++){


        _update(bit,size,i,A[i]);
    }
    return bit;
}
int main(){


    int size;
    cout<<"Size : ";
    cin>>size;

    int * A=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
        cin>>A[i];
     int *_bit=createBit(A,size);



    int choice=0,L,R,index,value;
    do{

        cout<<"Menu\n\t1.get sum till index \n\t2.update any index\n\t3.BIT\n\t0.Exit\n";
        cin>>choice;
        switch(choice){


            case 0 : cout<<"Program Ended By User"<<endl;
                      break;
            case 1 : cout<<"[0...Index] : "; cin>>L;
                     cout<<_getSum(_bit,L)<<endl;
                      break;
            case 2 : cout<<"index : "; cin>>index;
                     cout<<" value : "; cin>>value;
                     A[index]+=value; _update(_bit,size,index,value);
                        break;
            case 3 :  for(int i=1;i<=size;i++) cout<<_bit[i]<<" "; cout<<endl;
                        break;
            default  : cout<<"Invalide query "<<endl; break;
        }
    }
    while(choice);

    return 0;
}
