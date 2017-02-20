#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode {

	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} treenode;

typedef Stack{

	treenode *addrs;
	struct Stack *next;
} _stack;

treenode* treenode_new(int val) {

	treenode* node = (treenode *) malloc(sizeof(treenode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}
_stack *push(_stack ** top,treenode * addr){


	_stack *_new=(_stack*)malloc(sizeof(_stack));
	_new->addrs=addr;
	_new->next=(*top);
	(*top)=_new;
	return _new;
}
_stack *pop(_stack **top){

	_stack *topRef=*top;
	if(topRef==NULL) return NULL;

	_stack *ans=*top;
	*top=topRef->next;
	return ans;
}

int* inorderTraversal(treenode* A, int *len1) {

    int *S=(int*)malloc(100001*sizeof(int));
    int i=0;

    int done=0;

    _stack *top=NULL

}
treenode *push(treenode *root,int val){

	if(root==NULL){

		treenode _new=(treenode *)malloc(sizeof(treenode));
		_new->val=val;
		_new->left=NULL;
		_new->right=NULL;
		return _new;
	}

	if(root->val<=val){

		if(root->right==NULL){


		}
	}

}
int main(){



	return 0;
}