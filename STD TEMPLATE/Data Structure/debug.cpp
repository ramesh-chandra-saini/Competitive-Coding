int P[100000];
int A=0;
int len=0;
int calsum(int P[],int len){

    int sum=0;
    for(int i=0;i<len;i++) sum+=P[i];
	cout<<"Path :" ; for(int i=0;i<len;i++) cout<<P[i]<<" "; cout<<endl;}
    return sum;
}
void preorder(TreeNode *root,int P[],int sum,bool &flag){

    if(!root)return;

    P[len++]=root->val;
    A+=root->val;
    if(!root->left && !root->right){

        if(sum==calsum(P,len)){
            flag=true;
            return;
        }
    }
    preorder(root->left,P,sum,flag);
    preorder(root->right,P,sum,flag);
    return;
}

int Solution::hasPathSum(TreeNode* A, int B) {

   A=0;
    len=0;
    bool flag=false;
    preorder(A,P,B,flag);
    return flag;
}
