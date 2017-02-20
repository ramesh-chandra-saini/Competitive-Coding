#include<bits/stdc++.h>
using namespace std;
int Solution::minDepth(TreeNode* A) {

    if(!A) return 0;

    std::queue<std::pair<TreeNode*, int> > q;
    q.push(make_pair(A,1));
    while(!q.empty()){

        std::queue<std::pair<TreeNode*, int> > curr = q.front();
        q.pop();
        if(!curr.first->left &&!curr.first->right) return curr.second;
        if(curr.first->left){
            q.push(make_pair(curr.first->left,curr.second+1));
        }
        if(curr.first->right){

            q.push(make_pair(curr.first->right,curr.second+1));
        }
    }

}