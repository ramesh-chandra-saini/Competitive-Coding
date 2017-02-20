/*Demonstration of stack operation*/
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
void push(int stck[],int size,int &top)
{
  if(top==size-1){
        cout<<"*****STACK OVERFLOW*****"<<endl;
        return ;
    }
    int value;
    cout<<"Enter value to be pushed"<<endl;
    cin>>value;
     /*push operation*/
    stck[++top]=value;
}
void pop(int stck[],int &top)
{
    if(top==-1){
      cout<<"*****STACK UNDERFLOW*****"<<endl;
      return;
      }
       /*pop operation*/
        cout<<"POPPED ELEMENT : "<<stck[top--]<<endl;
}
int main()
{
    int size;
    cout<<"Enter the size of Stack :"<<endl;
    cin>>size;

    int stck[size],top=-1;
    cout<<"Menu\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT"<<endl;
    int choice;

    do{
        cout<<"Enter your choice :  ";
        cin>>choice;

        switch(choice){

            case 1  :   push(stck,size,top);break;
            case 2  :   pop(stck,top);break;
            case 3  :   display(stck,top);break;
            case 4  :   cout<<"Program Ended By User"<<endl;break;
            default :   cout<<"Invalid Option"<<endl;break;
        }
    }
    while(choice!=4);
   return 0;
}
