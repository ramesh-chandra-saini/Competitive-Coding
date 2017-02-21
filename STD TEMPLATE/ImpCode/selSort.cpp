#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* next;
    };

  struct node* print(struct node* node){
    struct node* root=node;
    while(root!=NULL){
        cout<<root->data<<endl;
        root=root->next;
    }

  };

int main(){

     struct node* root=(struct node*)malloc(sizeof(struct node));
     struct node* root1=(struct node*)malloc(sizeof(struct node));
     struct node* root2=(struct node*)malloc(sizeof(struct node));


     maptt[1]= root;
     root->data=2;
     root->next=root1;
     root1->data=3;
     root1->next=root2;
     root2->data=4;
     root2->next=NULL;
     struct node* node;

     for(it=maptt.begin();it!=maptt.end();it++){
        cout<<it->first<<endl;
          node=it->second;
     }
     print(node);
}
