#include<bits/stdc++.h>
using namespace std;

int p=0;
typedef struct node {

	struct node *left;
	int val;
	struct node  * right;
} TreeNode;

TreeNode *get(int val){
	TreeNode* N=(TreeNode*)malloc(sizeof(TreeNode));
	N->left=N->right=NULL;
	N->val=val;
	return N;
}

TreeNode *insert(TreeNode* root,int val){

	if(!root) root=get(val);
	else if(val<root->val) root->left=insert(root->left,val);
	else root->right=insert(root->right,val);
	return root;
}
void levelorder(TreeNode* root,int &ct){

	if(!root) return;

	queue<TreeNode*> q;
	q.push(root);q.push(NULL);
	while(1){

		TreeNode *curr=q.front(); q.pop();
		if(curr==NULL){
			cout<<endl;
			q.push(NULL); ct++;
			curr=q.front();q.pop();
			if(curr==NULL) break;
		}
		cout<<curr->val<<" ";

		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
	}
	return ;
}
void _levelOrder(TreeNode *A){

    if(!A) return ;
    queue<TreeNode*> q;

   cout<<"\n*****************************************************\n";
    q.push(A); q.push(NULL);

    while(1){


        TreeNode* curr=q.front(); q.pop();

        if(curr==NULL){
			cout<<"\n";
			q.push(NULL);
			curr=q.front(); q.pop();
			if(curr==NULL) break;

        }
        cout<<curr->val<<"  ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
       cout<<"\n*****************************************************\n";
       return;
}
int main(){

	TreeNode * root=NULL;
	cout<<"1.insert\n2.display\n";
	while(1)
	{
		cout<<"Choice : ";
		int choice;
		cin>>choice;int ct=0;

		if(choice==1) { int val; cout<<"value : ";cin>>val;root=insert(root,val);}
		else {cout<<"Levelorder"<<endl;levelorder(root,ct);cout<<endl;cout<<ct<<endl;_levelOrder(root); }
	}
	return 0;
}