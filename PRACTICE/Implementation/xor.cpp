#include <bits/stdc++.h>
using namespace std;
#define bit 27
#define gc getchar_unlocked
#define pc putchar_unlocked
typedef struct Node {
    struct Node *zero;
    struct Node *one;
} node;
inline void read(int &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
}
node* getNode(){
    node* temp = (node*)malloc(sizeof(node));
    temp->one = temp->zero = NULL;
    return temp;
}
int ANS = 0;
void insert(node* root,int val){

    node*temp = root,*it=root;

    int ans = 0;
    vector<bool> value(bit,false);
    for(int i=0;i<bit;i++,(val>>=1))
        value[i]=(val&1);
    //inserting msb first
    for(int i=value.size()-1;i>=0;i--){
        if(value[i]==false){
            if(root->zero==NULL)
                root->zero = getNode();
            root = root->zero;

             if(it->one){
                ans = (ans<<1)+1;
                it = it->one;
            }else{
                ans = (ans<<1);
                it = it->zero;
            }

        }else{
            if(root->one==NULL)
                root->one = getNode();
            root = root->one;
             if(it->zero){
                ans = (ans<<1)+1;
                it = it->zero;
            }else{
                ans = (ans<<1)+0;
                it = it->one;
            }
        }
    }
    ANS = max(ans,ANS);
}
int main(){

    int N,M; read(N),read(M);
    int arr[N][M];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            read(arr[i][j]);
    for(int stJ=0;stJ<M;stJ++){
        vector<int> subMat(N,0);
        for(int j=stJ;j<M;j++){
            for(int i=0;i<N;i++){
                subMat[i]^=arr[i][j];
            }
            node *trie=getNode();
            insert(trie,0);
            int value = 0;
            for(int i=0;i<N;i++){
                value^=subMat[i];
                insert(trie,value);
            }
        }
    }
    printf("%d\n",ANS);
    return 0;
}
