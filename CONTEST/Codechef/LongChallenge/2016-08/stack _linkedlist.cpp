#include<stdio.h>
#include<stdlib.h>



 struct node
{
int data;
struct node* next;
};

struct  node* insertnode(int num)
{
    struct node* root=(node*)malloc(sizeof(node));
        root->data=num;
        root->next=NULL;

        return root;
}

struct node* push(struct node* root,int num)
{

    if(root==NULL) return insertnode(num);
    else  root->next=push(root->next,num);

    return root;
}

struct node* pop(struct node* root)
{
    struct node* node=root;

    if(root==NULL) return NULL;

    if(root->next==NULL)
    {
            free(root);
            return NULL;
    }


    if(root->next->next!=NULL)
    {
        root->next=pop(root->next);
    }
    else if(root->next->next==NULL)
    {
        free(root->next);
        root->next=NULL;
    }

    return root;

}

int main(){
    struct node* root=NULL;
    int choice;
    int num;
    printf("Enter the number of elements\n");

    while(1){
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
            printf("insert elements\n");
            scanf("%d",&num);
            root=push(root,num);
            for(struct node* temp=root;temp;temp=temp->next)
                        printf("%d\t",temp->data);
            //printf("%d\n",root->next->data);
            break;
     case 2:
            printf("pop the element\n");
           root= pop(root);
             for(struct node* temp=root;temp;temp=temp->next)
                        printf("%d\t",temp->data);
    }
    }
}



