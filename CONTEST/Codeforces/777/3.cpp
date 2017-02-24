#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#include <iostream>
using namespace std;

// Structure to represent an interval
struct Interval
{
    int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i;  // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
};

// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
};

// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert.  Here the low value of interval
// is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);

    // Get low value of interval at root
    int l = root->i->low;

    // If root's low value is smaller, then new interval goes to
    // left subtree
    if (i.low < l)
        root->left = insert(root->left, i);

    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);

    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;

    return root;
}

// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}

// The main function that searches a given interval i in a given
// Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return NULL;

    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;

    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);

    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, i);
}

void inorder(ITNode *root)
{
    if (root == NULL) return;

    inorder(root->left);

   // cout << "[" << root->i->low << ", " << root->i->high << "]"
    //     << " max = " << root->max << endl;

    inorder(root->right);
}
ITNode* fun(vector<pair<int,int> >&arr){

Interval ints[arr.size()];
    for(int i=0;i<arr.size();i++)
        ints[i].low = arr[i].first,
        ints[i].low = arr[i].second;



    int n = sizeof(ints)/sizeof(ints[0]);
    ITNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, ints[i]);

    //cout << "Inorder traversal of constructed Interval Tree is\n";
    inorder(root);

        return root;

}
bool check(pair<int,int> p,ITNode *root){
        Interval x = {p.first, p.second};

   // cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
    Interval *res = overlapSearch(root, x);
    if (res == NULL)
        return false;
    return true;
}

int main(){
    freopen("in.txt","r",stdin);
    ll N,M; cin >> N >> M;
    vector<vector<int> > mat(N+1,vector<int>(M+1,0));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> mat[i][j];


    vector<pair<int,int> > arr;
    for(int j=1;j<=M;j++){
        int st=1,end=1,num = mat[1][j];
        for(int i=1;i<=N;i++){
            if(num<=mat[i][j])
                end=i;
            else arr.push_back(make_pair(st,end)),st=i,end=i;
            num=mat[i][j];
        }
        arr.push_back(make_pair(st,end));
        ///cout<<endl;
    }
     ITNode *root = fun(arr);
    int k; cin >> k;
    while(k--){
        int l,r; cin >> l >> r;

        (check(make_pair(l,r),root))?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }

    return 0;
}
