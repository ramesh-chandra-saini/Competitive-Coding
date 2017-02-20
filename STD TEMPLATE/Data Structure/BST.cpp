#include<bits/stdc++.h>
using namespace std;


///create treenode
typedef struct TreeNode {

	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} treenode;

///get new node
treenode* treenode_new(int val) {

	treenode* node = (treenode *) malloc(sizeof(treenode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

///create  root node
treenode *create(treenode *root,int value){

	root=(treenode *)malloc(sizeof(treenode));
	root->left=NULL;
	root->right=NULL;
	root->val=value;
	return root;
}

///insert childe in tree
void insert(treenode *root,int value){

	if(root->val>=value) {

		if(root->left==NULL) root->left=treenode_new(value);
		else insert(root->left,value);
	}
	else{

		if(root->right==NULL) root->right=treenode_new(value);
		else insert(root->right,value);
	}
	return ;
}

///preorder traversal
void preorder(treenode *root){

	if(root==NULL) return;

	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
	return ;
}

///inorder traversal
void inorder(treenode *root){

	if(root==NULL) return;

	inorder(root->left);
	cout<<root->val<<" ";

	inorder(root->right);
	return;
}

///postorder traversal
void postorder(treenode *root){

	if(root==NULL) return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
	return;
}

///make stack structure...
typedef struct Stack{

	treenode *addr;
	struct Stack *_next;
} _stack;

///check stack empty or not..
int isEmptyStack(_stack *top){

	if(top==NULL) return 1;
	return 0;
}

///push element into stack ...
void Push(_stack **topRef,treenode *address){

	_stack *_new=(_stack*)malloc(sizeof(_stack));
	_new->addr=address;
	_new->_next=*topRef;
	*topRef=_new;
}

///pop element into stack
treenode * Pop(_stack **topRef){

	_stack *top=*topRef;
	*topRef=top->_next;
	return top->addr;
}
///iterative inorder ..
int*  Inorder(treenode* root,int *len){

	int *A=(int *)malloc(100001*sizeof(int)),i=0;
	*len=0;

	if(root==NULL)  return A;
	_stack *top=NULL;

	treenode *iter=root;
	int done=0;

	while(done==0){

		while(iter!=NULL){

			Push(&top,iter);
			iter=iter->left;
		}

		done=isEmptyStack(top);
		if(done==1)break;
		else {

			iter=Pop(&top);
			A[i++]=iter->val;
			iter=iter->right;
		}
	}
	*len=i;
	return A;
}

int *Preorder(treenode *root,int *len){

	int *A=(int*)malloc(100001*sizeof(int)),i=0;
	if(root==NULL) return A;

    _stack *top=NULL;

    int done=0;
    treenode *iter=root;

    while(done==0){

		while(iter!=NULL){

			A[i++]=iter->val;

			Push(&top,iter);
			iter=iter->left;
		}

		done =isEmptyStack(top);

		if(done==1) break;
		else {

			iter=Pop(&top);
			iter=iter->right;
		}
    }
    *len=i;
    return A;
}

int *postorderTraversal(treenode *root,int *len){

		int *A=(int*)malloc(100001*sizeof(int)),i=0;
		*len=0;

		if(root==NULL) return A;

		_stack *top=NULL;
		treenode *iter=root;

	do
    {
        // Move to leftmost node
        while (iter)
        {
            // Push root's right child and then root to stack.
            if (iter->right)
                Push(&top, iter->right);

            Push(&top, iter);

            // Set root as root's left child
            iter = iter->left;
        }

        // Pop an item from stack and set it as root
        iter = Pop(&top);

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (iter->right && !isEmptyStack(top) && top->addr == iter->right)
        {
            Pop(&top);  // remove right child from stack
            Push(&top, iter);  // push root back to stack
            iter = iter->right; // change root so that the right
                                // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
            A[i++]=iter->val;
					//printf("%d ", iter->data);
            iter = NULL;
        }
    } while (!isEmptyStack(top));
		*len=i;
		return A;
}

void LCA(treenode * root,int A,int B,vector<int> &_L,bool &a,bool &b,bool &c){

    if(root==NULL) return;
    LCA(root->left,A,B,_L,a,b,c);

     if(root->val==A) a=true;
     if(root->val==B) b=true;

     if(((a==false && b==true) ||(a==true && b==false)) &&c==false)_L.push_back(root->val);
     if(a^b==false) cout<<root->val<<" ";
     if(a==true && b==true) c=true;
     if(!_L.empty()) _L.erase(_L.end(),_L.end());
    LCA(root->right,A,B,_L,a,b,c);
    // if(!_L.empty()) _L.erase(_L.end(),_L.end());
}
///driver program

int main(){

	treenode *root=NULL;

	cout<<"Menu\n\t0.Exit\n\t1.Insert\n\t2.Recursive Display\n\t3.Iterativedisplay \n\t4.DeleteTree"<<endl;

	int choice,len=0;
	int *A=(int*)malloc(100001*sizeof(int));
	int _A; int _B;vector<int> _L;
    //cin>>A>>B;_L.clear();
    bool a=false;
    bool b=false;
    bool c=false;

	do{

		cout<<"Enter Choice : ";
		cin>>choice;

		switch(choice){

			case 0 : cout<<"System.out"<<endl;
			break;
			case 1 : int value;
					if(root==NULL ){ cout<<"Root Value : "; cin>>value; root=create(root,value); }
					else {cout<<"Value : "; cin>>value; insert(root,value);}
			break;
			case 2 :
				cout<<"Inorder : "; inorder(root); cout<<endl;
				cout<<"Preorder : "; preorder(root); cout<<endl;
				cout<<"Postorder : " ; postorder(root); cout<<endl;
				cout<<endl;
			break;
			case 3 :
					A=Inorder(root,&len);
					cout<<"Inorder : ";for(int i=0;i<len;i++) cout<<A[i]<<" ";cout<<endl;
					A=Preorder(root,&len);
					cout<<"Preorder : ";for(int i=0;i<len;i++) cout<<A[i]<<" ";cout<<endl;
					A=postorderTraversal(root,&len);
					cout<<"Postorder : ";for(int i=0;i<len;i++) cout<<A[i]<<" ";cout<<endl;
			break;
			case 4 : root=NULL; break;
			case 5 :   a=false;b=false; c=false;
                        cin>>_A>>_B;_L.clear();
                        LCA(root,_A,_B,_L,a,b,c); cout<<endl;


			          for(int _i=0;_i<_L.size();_i++) cout<<_L[_i]<<" "; cout<<endl;
			          break;

			default : cout<<"Error : Choice Not Found"<<endl;
			break;
		}

	} while(choice);

	return 0;
}
