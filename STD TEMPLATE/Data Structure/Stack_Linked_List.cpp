#include<bits/stdc++.h>
using namespace std;

typedef struct Node{

	int val;
	struct Node*next;
} node;

bool isEmptyStack(node *top){

	if(top==NULL) {cout<<"Oops! Empty Stack"<<endl;return true;}
	return false;
}

node *push(node *top,int value){

	node* _new=(node*)malloc(sizeof(node));
	_new->val=value;
	_new->next=top;
	return _new;
}

node *pop(node *top){

	if(isEmptyStack(top)) return top;
	return top->next;
}

void display(node *top){

	if(isEmptyStack(top)) return ;
	cout<<"Top : ";
	while(top){

		cout<<top->val<<" ";
		top=top->next;
	}
	cout<<endl;
	return;
}

void getTopElement(node *top){

	if(isEmptyStack(top)) return ;
	cout<<"Top : "<<top->val<<endl;
	return;
}

void getsizeOfStack(node *top){

	if(isEmptyStack(top)) return ;

	int count=0;

	while(top){

		count++;
		top=top->next;
	}
	cout<<"Node : "<<count<<endl;
	return;
}

int main()
{
	node *top=NULL;

	int choice=0;
	cout<<"Menu\n\t0.Exit\n\t1.Push\n\t2.Pop\n\t3.getTopElement\n\t4.sizeOfStack\n\t5.displayStackElement\n\t6.IsEmptyStack"<<endl;

	do{

		cout<<"Choice : ";
		cin>>choice;

		switch(choice){

			case 0 : cout<<"System.out"<<endl;break;
			case 1 : int val; cout<<"Value : "; cin>>val; top=push(top,val);break;
			case 2 : top=pop(top); break;
			case 3 : getTopElement(top);break;
			case 4 : getsizeOfStack(top);break;
			case 5 : display(top);break;
			case 6 : isEmptyStack(top);break;
			case 7 : break;
			case 8 : break;
			case 9 : break;
			default: cout<<"Error : Choice Not Found"<<endl; break;
		}
	}while(choice);
	return 0;
}