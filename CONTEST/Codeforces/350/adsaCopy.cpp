/*
Creted By Dharmendra singh(13co213)
Ramesh Chandra (13co237)
*/
//Header file
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	char color;
	int item;
	struct Node *leftchild;
	struct Node *rightchild;
	struct Node *parent;
};
struct Node *dummy,*root=NULL;

void RightRotation(struct Node *x){
//balance after insertion
/*
         z
        /  \
       x    T4
      / \
     y   T3
    / \
   T1 T2
*/

	struct Node* y=x->leftchild;
	x->leftchild=y->rightchild;

	if(y->rightchild!=dummy)
        y->rightchild->parent=x;
    y->parent=x->parent;

    if(x->parent==dummy)
        root=y;
    else if(x==x->parent->rightchild)
        x->parent->rightchild=y;
    else
        x->parent->leftchild=y;
    y->rightchild=x;
    x->parent=y;
}

void LeftRotation(struct Node *x){
/*
         z
        /  \
       x    T4
      / \
     T1   y
         / \
        T2  T3
*/
    struct Node * y = x->rightchild;
    x->rightchild=y->leftchild;

    if(y->leftchild!=dummy)
        y->leftchild->parent=x;

    y->parent=x->parent;

    if(x->parent==dummy)
        root=y;
    else if(x==x->parent->leftchild)
        x->parent->leftchild=y;
    else
        x->parent->rightchild=y;
    y->leftchild=x;
    x->parent=y;
}
struct Node *successor(struct Node *ptr){
	struct Node *it=ptr->rightchild;
	while(it->leftchild!=dummy)
	{
		it=it->leftchild;
	}
	return(it);
}

void inorder(struct Node *ptr){
	if(ptr!=dummy)
	{
		inorder(ptr->leftchild);
		printf("%d(%c) ",ptr->item,ptr->color);
		inorder(ptr->rightchild);
	}
}

void balance_insert(struct Node *ptr){

	struct Node *par,*uncle,*grandparent;
	while(ptr->parent->color=='r')
	{

		par=ptr->parent;
		grandparent=par->parent;
		if(par==grandparent->leftchild){

            uncle=grandparent->rightchild;

            if(uncle->color=='r'){

                par->color=uncle->color='b';
                grandparent->color='r';
                ptr=grandparent;
            }
            else{

                if(ptr==par->rightchild){

                    LeftRotation(par);
                    ptr=par;
                    par=ptr->parent;
                }
                par->color='b';
                grandparent->color='r';
                RightRotation(grandparent);
            }
		}
		else{

            if(par==grandparent->rightchild){

                uncle=grandparent->leftchild;

                if(uncle->color=='r'){

                    par->color=uncle->color='b';
                    grandparent->color='r';
                    ptr=grandparent;
                }
                else{

                    if(ptr==par->leftchild){

                        RightRotation(par);
                        ptr=par;
                        par=ptr->parent;
                    }
                    par->color='b';
                    grandparent->color='r';
                    LeftRotation(grandparent);
                }
            }
		}
	}
	root->color='b';
}
//function to insert an item
void insert(int item){

	struct Node *parent,*it,*temp;
	it=root;
	parent=dummy;
	while(it!=dummy)
	{
		parent=it;
		if(item < it->item)
		it=it->leftchild;
		else if(item > it->item)
		it=it->rightchild;
		else
		{
			printf("Duplicate found\n");
			return;
		}
	}
	temp=(struct Node *) malloc(sizeof(struct Node));
	temp->item=item;
	temp->leftchild=temp->rightchild=dummy;
	temp->color='r';
	temp->parent=parent;
	if(parent==dummy)
	root=temp;
	else if(temp->item < parent->item)
        parent->leftchild=temp;
	else
        parent->rightchild=temp;
	balance_insert(temp);
}

//function to delete an item
void deletion(int);
//balance after deletion
void balance_deletion(struct Node *ptr);
int  finddata(int data,struct Node **ptr){
	struct Node *it;
	if(root==dummy)
	{
		*ptr=dummy;
		return(0);
	}
	if(root->item==data)
	{
		*ptr=root;
		return(1);
	}
	it=root;
	while(it!=dummy)
	{
		if(data==it->item)
		{
			*ptr=it;
			return(1);
		}
		else if(data<it->item)
		it=it->leftchild;
		else
		it=it->rightchild;
	}
	*ptr=dummy;
	return(0);
}

int main()
{

	int choice,data;
	dummy=(struct Node *) malloc(sizeof(struct Node));
	dummy->color='b';
	dummy->item=-1;
	dummy->leftchild=dummy->rightchild=NULL;
	root=dummy;

    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	do
	{

		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1:
				printf("Enter the number to be inserted\n");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
				printf("Enter the number which to be deleted\n");
				scanf("%d",&data);
				break;
		    case 3:
                    inorder(root);
                    break;
		    case 4:
		    	break;
		    default:
			 printf("wrong choice\n");
			 break;
		}
	}
	while(choice!=4);
}
