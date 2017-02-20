#include<iostream>
using namespace std;
void display(int stck[],int top)
{
   if(top==-1){
        cout<<"*****Stack is Empty*****"<<endl;
        return ;
     }
        cout<<"Stack Element :"<<endl;
        for(int i=0;i<=top;i++){
              /*display operation*/
           cout<<stck[i]<<endl;
        }
}
int main()
{
    int size;
    cout<<"Enter the size of Queue"<<endl;
    cin>>size;

    int Queue[size];

    cout<<"Menu\n\t1.ENQUE\n\t2.DEQUE\n\t3.DISPLAY\n\t4.EXIT"<<endl;
    int choice;

    do{
        cout<<"Enter your choice :  ";
        cin>>choice;

        switch(choice){

            case 1  :   Enque(Queue,size,tail);break;
            case 2  :   Deque(stck,top);break;
            case 3  :   Display(stck,top);break;
            case 4  :   cout<<"Program Ended By User"<<endl;break;
            default :   cout<<"Invalid Option"<<endl;break;
        }
    }
    while(choice!=4);
    return 0;
}
