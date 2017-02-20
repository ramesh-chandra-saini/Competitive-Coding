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

void inorder(TreeNode *root,vector<int>&In){
	if(!root) return;
	inorder(root->left,In);
	cout<<root->val<<" ";
	In.push_back(root->val);
	inorder(root->right,In);
	return;
}
void preorder(TreeNode *root,vector<int>&Pr){
	if(!root) return;
	cout<<root->val<<" ";
	Pr.push_back(root->val);
	preorder(root->left,Pr);
	preorder(root->right,Pr);
	return;
}

void postorder(TreeNode *root,vector<int>&Ps){
	if(!root) return;
	postorder(root->left,Ps);
	postorder(root->right,Ps);
	cout<<root->val<<" ";
	Ps.push_back(root->val);
	return;
}

void display(TreeNode* root,vector<int> &In,vector<int>&Pr,vector<int>&Ps){

	if(!root) {
		cout<<"Empty : "<<endl;return;
	}
	cout<<"Inorder : ";inorder(root,In); cout<<endl;
	cout<<"Preorder : ";preorder(root,Pr); cout<<endl;
	cout<<"Postorder : ";postorder(root,Ps);cout<<endl;
	return;
}

int search(vector<int> A,int start,int end,int key){

	for(int i=start;i<=end;i++){

		if(A.at(i)==key) return i;
	}
}
TreeNode * build(vector<int> &P,vector<int> &I,int istart,int iend){

	if(istart>iend) return NULL;
	TreeNode *New=get(P.at(p++));

	if(istart==iend) return New;

	int imid=search(I,istart,iend,New->val);
	New->left=build(P,I,istart,imid-1);
	New->right=build(P,I,imid+1,iend);
	return New;
}
TreeNode *Treeconstr_Pr_In(vector<int> &P,vector<int> &I){
	p=0;
	return build(P,I,0,I.size()-1);
}
TreeNode* build2(vector<int>&I,int istart,int iend,int sz){

	if(istart>iend || pstart>peind) return NULL;

	TreeNode* New=get(P.at(pend));

	int imid=search(I,istart,iend,New->val);
	New->left=build2(I,istart,imid-1,P,Pstart,pstart+((mid-1)-istart+1)-1);
	New->right=build2(I,imid+1,iend,P,pend-(iend-(imid+1)+1),pend-1);
	return New;
}

TreeNode* Treeconstr_Ps_In(vector<int> &P,vector<int> &I){
	return build2(I,0,I.size()-1,P,0,I.size()-1);
}

int main(){

	TreeNode *root=NULL;
	TreeNode *N=NULL,*N2=NULL;
	//duplicate not allowed....BST
	int choice;
	vector<int> In,Pr,Ps; In.clear();Pr.clear();Ps.clear();
	cout<<"Menu\n\t0.Exit\n\t1.insert\n\t2.display\n\t3.construct\n";
	do{

		cin>>choice;
		switch(choice){
			case 0 : cout<<"Program Ended By User "<<endl; break;
			case 1 : int val;cout<<"value "; cin>>val ;root=insert(root,val);break;
			case 2 : display(root,In,Pr,Ps); break;
			case 3 : N=Treeconstr_Pr_In(Pr,In); display(N,In,Pr,Ps);break;
			case 4 : N2=Treeconstr_Ps_In(Pr,In); display(N2,In,Pr,Ps);break;
			default : cout<<"Invalid Query "<<endl; break;
		}
	} while(choice);
	return 0;
}